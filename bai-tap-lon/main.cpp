#include "Commonfunction.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObjects.h"
#include "ExplosionObject.h"
#include "TextObject.h"

using namespace std;

BaseObject g_background;

TTF_Font* font_time = NULL;

bool init()
{
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        return false;
    }
    g_window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
    if(g_window == NULL) {
        success = false;
    }
    else{
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if(g_screen == NULL){
            success = false;
        }
        else{
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) && imgFlags)){
                success = false;
            }

        }
        if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
            return false;
        }
        g_sound_bullet = Mix_LoadWAV("Gun+357+Magnum.wav");
        g_sound_explosion = Mix_LoadWAV("Explosion.wav");
        g_music = Mix_LoadMUS("mobile-phone-ringtone-6769.wav");
        if(g_sound_bullet == NULL || g_sound_explosion == NULL){
            return false;
        }

        if(TTF_Init() == -1){
            success = false;
        }
        font_time = TTF_OpenFont("chu.ttf", 20);

    }
    return success;
}

bool LoadBackground(){
    bool ret = g_background.LoadIMG("background.png", g_screen);
    if(ret == false) return false;
    return true;
}

void close(){
    g_background.free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}





int main(int argv, char* args[])
{
    if(init() == false)
    {
        return -1;
    }
    if(LoadBackground() == false)
    {
        return -1;
    }

    // Player:
    MainObject player_;
    player_.LoadIMG("maybay.png", g_screen);
    player_.SetRect(700, 680);

    // ke dich
    ThreatObjects* p_threats = new ThreatObjects[NUM_THREATS];
    for(int t = 0; t<NUM_THREATS; t++)
    {
        ThreatObjects* p_threat = (p_threats + t);
        bool ret = p_threat->LoadIMG("caidb.png", g_screen);
        if(ret == false){
            return 0;
        }
        int rand_x = rand()%1300; // Sinh Threat ngẫu nhiên
            if (rand_x > SCREEN_WIDTH)
            {
                rand_x = SCREEN_WIDTH * 0.3;
            }
        p_threat->SetRect(rand_x, 0-t*50-50);
        p_threat->set_y_val(1);

        BulletObject* p_bullet_ = new BulletObject();

        p_threat->InitBullet(p_bullet_, g_screen);
    }



    ExplosionObject exp_main;
    bool ret = exp_main.LoadIMG("no.png", g_screen);
    if (ret == false)
        return 0;

    // text
    TextObject time_game;
    time_game.SetColor(TextObject::WHITE_TEXT);

    TextObject point_game;
    time_game.SetColor(TextObject::WHITE_TEXT);

    int qwert = 0;

    bool isquit = false;

    while(!isquit)
        {
            if( Mix_PlayingMusic() == 0 )
							{
								//Play the music
								Mix_PlayMusic( g_music, -1 );
							}
        while(SDL_PollEvent(&g_event)!=0)
        {
            if(g_event.type == SDL_QUIT)
            {
                isquit = true;
            }

            player_.HandleInputAction(g_event, g_screen, g_sound_bullet);
            player_.HandleMove();
            }


        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);


        SDL_RenderClear(g_screen);

        g_background.Render(g_screen, NULL);

        player_.HandleBullet(g_screen);
        player_.Show(g_screen);



        player_.HandleBullet(g_screen);

        std::string str_time = "Time: ";
        Uint32 time_val = SDL_GetTicks()/1000;
        std::string str_val = std::to_string(time_val);
        str_time +=str_val;

        time_game.SetText(str_time);
        time_game.loadfromRenderText(font_time, g_screen);
        time_game.RenderText(g_screen, SCREEN_WIDTH-200, 15);


        std::string str_point = "score: ";



        for (int i=0; i<NUM_THREATS;i++){
            ThreatObjects* p_threat = (p_threats + i);
            if(p_threat){
                p_threat->Show(g_screen);

                p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HIGHT);

                p_threat->MakeBullet(g_screen, SCREEN_HIGHT, SCREEN_HIGHT);

                bool is_col = SDLCommonfuction::CheckCollision(player_.GetRect(), p_threat->GetRect());
                if(is_col){



                    int x_pos = (player_.GetRect().x + player_.GetRect().w*0.5) - EXP_WIDTH*0.5;
                    int y_pos = (player_.GetRect().y + player_.GetRect().h*0.5) - EXP_HEIGHT*0.5;

                    exp_main.SetRect(x_pos, y_pos);
                    Mix_PlayChannel(-1, g_sound_explosion, 0);
                    exp_main.Show(g_screen);
                    Mix_HaltMusic();
                    SDL_RenderPresent(g_screen);
                    SDL_Delay(500);
                   if(MessageBox(NULL, "Game Over!", "Info", MB_OK) == IDOK){
                    delete[] p_threats;
                    close();
                    return 0;
                   }
                }

                std::vector<BulletObject*> p_bullet_list = player_.get_bullet_list();
                for (unsigned int am = 0; am < p_bullet_list.size(); am++)
                {
                    BulletObject* p_bullet = p_bullet_list.at(am);
                    if (p_bullet != NULL)
                    {
                        bool ret_collis = SDLCommonfuction::CheckCollision(p_bullet->GetRect(), p_threat->GetRect());
                        if (ret_collis)
                        {
                            qwert+=10;


                            int x_pos = (p_threat->GetRect().x + p_threat->GetRect().w*0.5) - EXP_WIDTH*0.5;
                            int y_pos = (p_threat->GetRect().y + p_threat->GetRect().h*0.5) - EXP_HEIGHT*0.5;

                            exp_main.SetRect(x_pos, y_pos);
                            Mix_PlayChannel(-1, g_sound_explosion, 0);
                            exp_main.Show(g_screen);
                            SDL_RenderPresent(g_screen);
                            p_threat->Reset(-50);
                            player_.removeBullet(am);
                            }
                        }
                    }

                for (int ko = 0; ko<NUM_THREATS; ko++){
                std::vector<BulletObject*> t_bullet_list = (p_threats+ko)->get_bullet_list();
                for ( unsigned int im = 0; im< t_bullet_list.size(); im++)
                    {
                    BulletObject* t_bullet = t_bullet_list.at(im);
                    if (t_bullet != NULL)
                    {
                        bool ret_collis = SDLCommonfuction::CheckCollision(t_bullet->GetRect(), player_.GetRect());
                        if (ret_collis)
                        {
                            int x_pos = (player_.GetRect().x + player_.GetRect().w*0.5) - EXP_WIDTH*0.5;
                            int y_pos = (player_.GetRect().y + player_.GetRect().h*0.5) - EXP_HEIGHT*0.5;

                            exp_main.SetRect(x_pos, y_pos);
                            Mix_PlayChannel(-1, g_sound_explosion, 0);
                            exp_main.Show(g_screen);
                            Mix_HaltMusic();
                            SDL_RenderPresent(g_screen);
                            SDL_Delay(500);
                            if(MessageBox(NULL, "Game Over!", "Info", MB_OK) == IDOK){
                            close();
                            return 0;
                            }
                        }
                    }
                }
            }

        }

    }

    std::string point_val = std::to_string(qwert);
                str_point += point_val;
                point_game.SetText(str_point);
        point_game.loadfromRenderText(font_time, g_screen);
        point_game.RenderText(g_screen, 15, 15);


    SDL_RenderPresent(g_screen);
    SDL_Delay(10);
    }

        delete[] p_threats;
    close();
    return 0;
}

