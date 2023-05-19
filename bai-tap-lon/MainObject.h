#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include <vector>
#include "Bullet.h"
#include "Commonfunction.h"
#include "BaseObject.h"

#define WIDTH_MAIN_OBJECT 63
#define HEIGHT_MAIN_OBJECT 90

#define BULLET_WIDTH 11
#define BULLET_HEIGHT 10

class MainObject : public BaseObject
{
public:

    MainObject();
    ~MainObject();

    bool LoadIMG(std::string path,SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen, Mix_Chunk* bullet_sound);
    void HandleBullet(SDL_Renderer* des);
    void HandleMove();

    void CheckToMap();

    void set_bullet_list(std::vector<BulletObject*> bullet_list)
    {
        p_bullet_list = bullet_list;
    }

    std::vector<BulletObject*> get_bullet_list() const
    {
        return p_bullet_list;
    }
    void removeBullet (const int& idx);
private:

    std::vector<BulletObject*> p_bullet_list;
    int x_val;
    int y_val;

    int frame_;
};

#endif // MAIN_OBJECT_H_
