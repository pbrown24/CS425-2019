#pragma once

#include "MySprite.h"

namespace GMUCS425
{
    //this defines the transform of the agent
    class MyAgent
    {
      public:

        //movable: true if this agent can move
        //collision: true if this agent can collision with other agents
        MyAgent(bool movable=true, bool collision=true)
        {
          x=y=degree=0;
          scale=1;
          visible=true;
          sprite=NULL;
          this->movable=movable;
          this->collision=collision;
        }

        //react to the events
        virtual void handle_event(SDL_Event & e);

        //update this agent's motion, looks, sound, etc
        virtual void update();

        //render this agent
        virtual void display();

        //show HUD (heads-up display) or status bar
        virtual void draw_HUD();

        //transforms
        void rotate(float degree){ this->degree+=degree; }
        void rotateTo(float degree){ this->degree=degree; }

        void tranlate(float x, float y){ this->x+=x; this->y+=y; }
        void tranlateTo(float x, float y){ this->x=x; this->y=y; }

        void scaleTo(float s){ this->scale=s; }

        //display
        void show(){ visible=true; }
        void hide(){ visible=false; }

        //sprite, aks costume
        void setSprite(MySprite * sprite){ this->sprite=sprite; }

        //motion/animation
        //void glide(float x, float y, float seconds);

      protected:

        //current position and orientations
        float x,y;
        float degree; //rotation
        float scale;

    		bool visible;
    		bool movable;
    		bool collision;

        MySprite * sprite; //current sprite
        //it is possible that you can have more than one sprites
        //vector<MySprite *> sprites; //the sprites
    };

}//end namespace
