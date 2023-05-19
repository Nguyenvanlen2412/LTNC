
#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

#include <iostream>
#include <SDL_mixer.h>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include<vector>
#include <random>
#include<SDL_mixer.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;
static Mix_Chunk* g_sound_bullet = NULL;
static Mix_Chunk* g_sound_explosion = NULL;
static Mix_Music* g_music = NULL;

const int SCREEN_WIDTH = 1386;
const int SCREEN_HIGHT = 780;
const int SCREEN_BPP = 32;

const int COLOR_RED = 255;
const int COLOR_GREEN = 255;
const int COLOR_BLUE = 255;

const int NUM_THREATS = 5;

const int RENDER_DRAW_COLOR = 0xff;

/*typedef struct Input
{
    int left_;
    int right_;
    int up_;
    int down_;
};*/

namespace SDLCommonfuction
{
    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}
#endif // COMMON_FUNCTION_H
