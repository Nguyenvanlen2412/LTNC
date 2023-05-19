
#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include "Commonfunction.h"

class BaseObject{
public:
    BaseObject();
    ~BaseObject();

    void SetRect(const double &x, const double &y){
        rect_.x = x;
        rect_.y = y;
    }
    SDL_Rect GetRect() const{return rect_;}
    SDL_Texture* GetObject() const{return p_object;}

    virtual bool LoadIMG(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void free();

protected:
    SDL_Texture* p_object = NULL;
    SDL_Rect rect_;
};

#endif // BASE_OBJECT_H
