#ifndef gameobject_h_
#define gameobject_h_

#include <stdlib.h>
#include <SDL/SDL3.h>

//Collision type might be
//NO_COLLISION, BOX_COLLISION, CIRCLE_COLLISION, BOX_TRIGGER_COLLISION, CIRCLE_TRIGGER_COLLISION

struct Sprite //A Sprite with behaviour
{
    SDL_Texture* texture;
    SDL_FRect rect;
    //char subjectToPhysics;
    //CollisionType collisionType;
    //Script* script;
};

struct Prop //A Sprite without behaviour
{
    SDL_Texture* texture;
    SDL_FRect rect;
    //char subjectToPhysics;
    //CollisionType collisionType;
}

struct Invisible //Some collider or an empty object with behaviour
{
    SDL_FRect rect;
    //CollisionType collisionType;
    //Script* script;
}

#endif
