#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#define RG35XX_KEY_Up       SDLK_w
#define RG35XX_KEY_Right    SDLK_d
#define RG35XX_KEY_Down     SDLK_s
#define RG35XX_KEY_Left     SDLK_q
#define RG35XX_KEY_A        SDLK_a
#define RG35XX_KEY_B        SDLK_b
#define RG35XX_KEY_X        SDLK_x
#define RG35XX_KEY_Y        SDLK_y
#define RG35XX_KEY_L1       SDLK_h
#define RG35XX_KEY_R1       SDLK_l
#define RG35XX_KEY_L2       SDLK_j
#define RG35XX_KEY_R2       SDLK_k
#define RG35XX_KEY_SELECT   SDLK_n
#define RG35XX_KEY_START    SDLK_m
#define RG35XX_KEY_MENU     SDLK_u
#define RG35XX_KEY_VOL_ADD  SDLK_r
#define RG35XX_KEY_VOL_SUB  SDLK_t
#define RG35XX_KEY_POWER    SDLK_POWER

int main(void) {
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("/mnt/SDCARD/helloworld/inziu-iosevkaCC-SC-regular.ttf", 24);
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface *screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("SDL Test", NULL);

    // 1. Clear the screen
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_Flip(screen);
    
    // 2. Draw text to the screen
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface *text = TTF_RenderText_Solid(font, "Hello World!", color);
    SDL_Rect position = { 0, 0, 0, 0 };
    SDL_BlitSurface(text, NULL, screen, &position);
    SDL_FreeSurface(text);
    SDL_Flip(screen);
        
    SDL_Event event;
    int running = 1;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    running = 0;
                    break;
                }
                case SDL_KEYDOWN: {
                    switch(event.key.keysym.sym) {
                        case RG35XX_KEY_MENU: {
                            running = 0;
                            break;
                        }
                        case RG35XX_KEY_A: {
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                            SDL_Flip(screen);
                            SDL_Color color = { 255, 255, 255 };
                            SDL_Surface *text = TTF_RenderUTF8_Solid(font, "你好，世界！", color);
                            SDL_Rect position = { 0, 0, 0, 0 };
                            SDL_BlitSurface(text, NULL, screen, &position);
                            SDL_FreeSurface(text);
                            SDL_Flip(screen);
                            break;
                        }
                        case RG35XX_KEY_B: {
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                            SDL_Flip(screen);
                            SDL_Color color = { 255, 255, 255 };
                            SDL_Surface *text = TTF_RenderText_Solid(font, "Hello World!", color);
                            SDL_Rect position = { 0, 0, 0, 0 };
                            SDL_BlitSurface(text, NULL, screen, &position);
                            SDL_FreeSurface(text);
                            SDL_Flip(screen);
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }

    SDL_Quit();
    TTF_Quit();

    return 0;
}

