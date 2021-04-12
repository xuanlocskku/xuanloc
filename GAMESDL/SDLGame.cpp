// SDLGame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CommonFunctions.h"
//#include "CommonFunctions.cpp"
#include "MainObject.h"



using namespace  std;
#undef main

SDL_Surface *g_object;





bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	g_screen = SDL_SetVideoMode(SCREEN_WDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
	{
		return false;
	}
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	bool is_quit = false;
	if (Init() == false)
	{
		return 0;
	}

	g_bkground = SDLCommonFunc::LoadImage("bg2.png");
	if (g_bkground == NULL)
	{
		return 0;
	}
	
	SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);

	MainObject human_object;
	MainObject plane_object;

	human_object.SetRect(300, 200);
	plane_object.SetRect(300, 100);
	plane_object.LoadImg("plane80.jpg");

	bool ret = human_object.LoadImg("human64x91.png");
	if (!ret)
	{
		return 0;
	}
	
	while (!is_quit)
	{
		while (SDL_PollEvent(&g_event))
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			human_object.HandleInputAction(g_event);
			plane_object.HandleInputAction(g_event);
		}

		SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
		plane_object.Show(g_screen);
		human_object.Show(g_screen);		
		human_object.HandleMove();
		plane_object.HandleMove();
		
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}

	SDLCommonFunc::CleanUp();
	SDL_Quit();
	
	return 1;
}

