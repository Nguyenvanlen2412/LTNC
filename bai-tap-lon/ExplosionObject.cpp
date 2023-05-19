
#include "ExplosionObject.h"

ExplosionObject::ExplosionObject()
{

}

ExplosionObject::~ExplosionObject()
{

}

bool ExplosionObject::LoadIMG(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadIMG(path, screen);
    return ret;
}

void ExplosionObject::Show(SDL_Renderer* des)
{
    LoadIMG("no.png", des);

    SDL_Rect RenderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_object, NULL, &RenderQuad);
}


