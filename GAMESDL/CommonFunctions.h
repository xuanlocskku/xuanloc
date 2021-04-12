#ifndef  COMMON_FUNCTION_H_
#define  COMMON_FUNCTION_H_



#include "stdafx.h"
#include <cstdint>
#include <SDL.h>
#include <string>
#include <SDL_image.h>

using namespace  std;

const int SCREEN_WDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

static SDL_Surface *g_screen = NULL;
static SDL_Surface *g_bkground = NULL;
static SDL_Event g_event;


namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
}

#endif