#include "MyScene.h"
#include "MyGame.h"
#include <fstream>

namespace GMUCS425
{

bool MyScene::create( std::istream & inputfile)
{
  using namespace std;

  struct readEntity // need a structure for holding entities
  {
      string filename;
      float y; //layer
      float scale;
      float orient;
      bool agent;
  };

  MyTextureManager * texture_manager=getMyGame()->getTextureManager();
  MySpriteManager * sprite_manager=getMyGame()->getSpriteManager();
  int screen_width = getMyGame()->getScreenWidth();
  int screen_height = getMyGame()->getScreenHeight();

  //build the level from the input stream
  int x,y;
  inputfile >> x >> y;	// read in the dimensions of the grid
  string backdropName;
  inputfile >> backdropName;	// read in the backdrop image name

  float cell_w=screen_width/x;
  float cell_h=screen_height/y;

  // create backdrop texture
  if(!texture_manager->create(backdropName))
  {
    cerr<<"ERROR: Failed to create texture "<<backdropName<<endl;
    return false;
  }
  //create backdrop sprite
  if(!sprite_manager->create("backdrop", texture_manager->get(backdropName)))
  {
    cerr<<"ERROR: Failed to create backdrop"<<endl;
    return false;
  }
  m_backdrop=new MyAgent(false,false);
  assert(m_backdrop);
  m_backdrop->setSprite(sprite_manager->get("backdrop"));

  string buf;
  inputfile >> buf;	// Start looking for the Objects section
  while  (buf != "Objects") inputfile >> buf;

  if (buf != "Objects")	// Oops, the file must not be formated correctly
  {
    cerr << "ERROR: Level file error" << endl;
    return false;
  }

  // read in the objects
  readEntity *rent = NULL;	// hold info for one object
  unordered_map<string,readEntity*> objs;		// hold all object and agent types;

  // read through all objects until you find the Characters section
  // these are the statinary objects
  while (!inputfile.eof() && buf != "Characters")
  {
    inputfile >> buf;			// read in the char
    if (buf != "Characters")
    {
      rent = new readEntity();	// create a new instance to store the next object

      // read the rest of the line
      inputfile >> rent->filename >> rent->orient >> rent->scale;
      rent->agent = false;		// these are objects
      objs[buf] = rent;		  	// store this object in the map
      if(!texture_manager->create(rent->filename))
      {
        cerr<<"ERROR: Failed to create "<<buf<<endl;
        return false;
      }
      //create the sprite
      if(!sprite_manager->create(buf, texture_manager->get(rent->filename)))
      {
        cerr<<"ERROR: Failed to create "<<buf<<endl;
        return false;
      }
    }
  }

  // Read in the characters (movable agents)
  while  (buf != "Characters") inputfile >> buf;	// get through any junk
  while (!inputfile.eof() && buf != "World") // Read through until the world section
  {
    inputfile >> buf;		// read in the char
    if (buf != "World")
    {
      rent = new readEntity();	// create a new instance to store the next object
      inputfile >> rent->filename >> rent->scale; // read the rest of the line
      rent->agent = true;			// this is an agent
      objs[buf] = rent;			// store the agent in the map
      if(!texture_manager->create(rent->filename))
      {
        cerr<<"ERROR: Failed to create "<<buf<<endl;
        return false;
      }
      //create the sprite
      if(!sprite_manager->create(buf, texture_manager->get(rent->filename)))
      {
        cerr<<"ERROR: Failed to create "<<buf<<endl;
        return false;
      }
    }
  }

  // read through the placement map
  char c;
  for (int i = 0; i < y; i++)			// down (row)
  {
    for (int j = 0; j < x; j++)		// across (column)
    {
      inputfile >> c;			// read one char at a time
      buf = c + '\0';			// convert char to string
      rent = objs[buf];		// find cooresponding object or agent
      if (rent != NULL)		// it might not be an agent or object
      {
        //TODO: You will need to create your own agent here
        //based on the type of charactor
        MyAgent * agent=new MyAgent(rent->agent);
        assert(agent);
        MySprite * sprite=sprite_manager->get(buf);
        assert(sprite);
        agent->setSprite(sprite);
        agent->rotateTo(rent->orient);
        agent->tranlateTo(j,i);
        agent->scaleTo(rent->scale);

        this->m_agents.push_back(agent); //remember
      }
      else // rent==null, not an object or agent
      {
        if(c!='o')
          cerr<<"WARNING: Unknow tag: "<<c<<". Ignore."<<endl;
      }
    } //end for j (col)
  }//end for i (row)

  // delete all of the readEntities in the objs map
  rent = objs["s"]; // just so we can see what is going on in memory (delete this later)
  for (auto obj : objs) // iterate through the objs
  {
    delete obj.second; // delete each readEntity
  }
  objs.clear(); // calls their destructors if there are any. (not good enough)

  //done!
  return true;
}

//handle a given event
void MyScene::handle_event(SDL_Event & e)
{
  for(MyAgent * agent : this->m_agents)
  {
    agent->handle_event(e);
  }
}

//update the scene
void MyScene::update()
{
  this->broad_range_collision();
  for(MyAgent * agent : this->m_agents)
  {
    agent->update();
  }
}

//display the scene
void MyScene::display()
{
  //draw backgrop if any
  if(m_backdrop!=NULL) m_backdrop->display();
  //draw all agents
  for(MyAgent * agent : this->m_agents)
  {
    agent->display();
  }
}

//show HUD (heads-up display) or status bar
void MyScene::draw_HUD()
{
  for(MyAgent * agent : this->m_agents)
  {
    agent->draw_HUD();
  }
}

//detect collisions in board range
int MyScene::broad_range_collision()
{
  return 0;
}


//create a texture from file
bool MySceneManager::create(std::string name, std::string scene_file)
{
  std::ifstream inputfile;		// Holds a pointer into the file
  std::string path = __FILE__; //gets the current cpp file's path with the cpp file
  path = path.substr(0,1+path.find_last_of('\\')); //removes filename to leave path
  path+= scene_file; //if txt file is in the same directory as cpp file
  inputfile.open(path);
  //std::cout<<"path="<<path<<std::endl;

  if (!inputfile.is_open()) // oops. there was a problem opening the file
  {
    std::cerr << "ERROR: FILE COULD NOT BE OPENED" << std::endl;	// Hmm. No output?
    return false;
  }

  MyScene * level=new MyScene();
  assert(level);
  if(!level->create(inputfile)) return false;
  this->add(name,level);
  return true;
}


}//end namespace
