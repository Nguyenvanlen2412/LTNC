#ifndef BULLET_H_
#define BULLET_H_

#include "BaseObject.h"
#include "Commonfunction.h"

class BulletObject : public BaseObject{
public:
    BulletObject();
    ~BulletObject();

    void Show(SDL_Renderer* des);
    bool LoadIMG(std::string path, SDL_Renderer* screen);

    void HandleMove(const int& x_border, const int& y_border);

    bool get_is_move() const
    {
        return is_move_;
    }
    void set_is_move(const bool &is_move)
    {
        is_move_ = is_move;
    }
    void SetWidthHeight(const int& width, const int& height)
    {
        rect_.w = width;
        rect_.h = height;
    }

    void Set_x_val(const int& val)
    {
        x_val_ = val;
    }
    void Set_y_val(const int& val)
    {
        y_val_ = val;
    }

    int Get_x_val() const
    {
        return x_val_;
    }
    int Get_y_val() const
    {
        return y_val_;
    }
    void HandleMoveOfThreat();

private:
    int x_val_;
    int y_val_;
    bool is_move_;
};

#endif // BULLET_H_
