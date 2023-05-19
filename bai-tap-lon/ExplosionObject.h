
#ifndef EXPLOSION_OBJECT_H_
#define EXPLOSION_OBJECT_H_

#include "BaseObject.h"
#include "Commonfunction.h"

const int EXP_WIDTH = 165;
const int EXP_HEIGHT = 165;

class ExplosionObject : public BaseObject
{
public:
    ExplosionObject();
    ~ExplosionObject();

    bool LoadIMG(std::string path,SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
};


#endif // EXPLOSION_OBJECT_H_
