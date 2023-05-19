#include "Bullet.h"

BulletObject::BulletObject()
{
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;
}

BulletObject::~BulletObject()
{

}
    bool BulletObject::LoadIMG(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadIMG(path, screen);
    return ret;
}

void BulletObject::Show(SDL_Renderer* des)
{
    LoadIMG("dan2.png", des);

    SDL_Rect RenderQuad = {rect_.x+25, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_object, NULL, &RenderQuad);
}


// Di chuyển đạn cuả nhân vật
void BulletObject::HandleMove(const int& x_border, const int& y_border)
{
    rect_.y -= y_val_;
    //rect_.x -= x_val_;
    if (rect_.y > y_border)  //Khi gặp khung hình hoặc vật cản
    {
        is_move_ = false;
    }
}

void BulletObject::HandleMoveOfThreat()
{
    rect_.y += y_val_;
    if (rect_.y > SCREEN_HIGHT)  //Khi gặp khung hình hoặc vật cản
    {
        is_move_ = false;
    }
}


