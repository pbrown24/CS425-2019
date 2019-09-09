#include "MyAgent.h"

namespace GMUCS425
{

  void MyAgent::handle_event(SDL_Event & e)
  {
    if(this->movable)
    {
      //do nothing now...
    }
  }

  //update this agent's motion, looks, sound, etc
  void MyAgent::update()
  {
    //do nothing by default...
  }

  void MyAgent::display()
  {
    if(!this->visible) return; //not visible...
    //setup positions and ask sprite to draw something
    this->sprite->display(x, y, scale, degree);
  }

  //show HUD (heads-up display) or status bar
  void MyAgent::draw_HUD()
  {
    //draw nothing by defaut, your task to display the location of an agent
    //on the upper left corner
    //read http://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
  }

}//end namespace
