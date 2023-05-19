#include "MainObject.h"

MainObject::MainObject()
{
    x_val = 0;
    y_val = 0;
}

MainObject::~MainObject()
{

}

bool MainObject::LoadIMG(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadIMG(path, screen);
    return ret;
}


void MainObject::Show(SDL_Renderer* des)
{
    LoadIMG("maybay.png", des);

    SDL_Rect RenderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_object, NULL, &RenderQuad);
}

void MainObject::HandleInputAction(SDL_Event events, SDL_Renderer* screen, Mix_Chunk* bullet_sound)
{
    if(events.type == SDL_KEYDOWN){
        switch (events.key.keysym.sym){
            case SDLK_d:
                x_val = 5;
                y_val = 0;
                break;

            case SDLK_a:
                x_val = -5;
                y_val = 0;
                break;

            case SDLK_w:
                y_val = -5;
                x_val = 0;
                break;

            case SDLK_s:
                y_val = 5;
                x_val = 0;
                break;


            default:
                break;
        }
    }
    else if(events.type == SDL_KEYUP)
    {
        switch (events.key.keysym.sym){
            case SDLK_a:
                y_val = 0;
                x_val = 0;
                break;

            case SDLK_d:
                y_val = 0;
                x_val = 0;
                break;

            case SDLK_w:
                y_val = 0;
                x_val = 0;
                break;

            case SDLK_s:
                y_val = 0;
                x_val = 0;
                break;

            default:
                break;
        }
    }
    else if(events.type == SDL_MOUSEBUTTONDOWN){
        if(events.button.button == SDL_BUTTON_LEFT){
                Mix_PlayChannel(-1, bullet_sound, 0);
                BulletObject* p_amo = new BulletObject();
                p_amo->SetWidthHeight(BULLET_WIDTH, BULLET_HEIGHT);
                p_amo->LoadIMG("dan1.png", screen);

                p_amo->SetRect(this->rect_.x+33, this->rect_.y);
                p_amo->set_is_move(true);
                p_amo->Set_y_val(4);
                p_bullet_list.push_back(p_amo);
        }
    }

}

void MainObject::HandleBullet(SDL_Renderer* des)
{
    for (unsigned int i = 0; i < p_bullet_list.size(); i++)
    {
        BulletObject* p_bullet= p_bullet_list.at(i);
        if (p_bullet != NULL)
        {
            if (p_bullet->get_is_move() == TRUE)
            {
                p_bullet->HandleMove(SCREEN_WIDTH, SCREEN_HIGHT);
                p_bullet->Render(des);
            }
            else
            {
                if (p_bullet != NULL)
                {
                    p_bullet_list.erase(p_bullet_list.begin() + i);
                    delete p_bullet;
                    p_bullet = NULL;
                }
            }
        }
    }
}


void MainObject::HandleMove()
{
    rect_.x += x_val;
    rect_.y += y_val;

    if (rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH || rect_.x < 0)
    {
        rect_.x -= x_val;
    }

    if (rect_.y <0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HIGHT)
    {
        rect_.y -= y_val;
    }
}
void MainObject::removeBullet(const int& idx)
{
    for (unsigned int i = 0; i < p_bullet_list.size(); i++)
    {
        if (p_bullet_list.size() > 0 && idx < p_bullet_list.size())
        {
            BulletObject* p_bullet = p_bullet_list.at(idx);
            p_bullet_list.erase(p_bullet_list.begin() + idx);
            if(p_bullet != NULL)
            {
                delete p_bullet;
                p_bullet = NULL;
            }
        }
    }
}
