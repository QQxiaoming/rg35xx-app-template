#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#define TTF_FILE_PATH "inziu-iosevkaCC-SC-regular.ttf"

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

void drawText(SDL_Surface *screen, TTF_Font *font, char *text, int x, int y, int r, int g, int b) {
    SDL_Color color = { r, g, b };
    SDL_Surface *textSurface = TTF_RenderUTF8_Solid(font, text, color);
    SDL_Rect position = { x, y, 0, 0 };
    SDL_BlitSurface(textSurface, NULL, screen, &position);
    SDL_FreeSurface(textSurface);
}

void clear(SDL_Surface *screen, int r, int g, int b) {
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, r, g, b));
}

void refresh(SDL_Surface *screen) {
    SDL_Flip(screen);
    SDL_Flip(screen);
}

int main(void) {
    TTF_Init();
    TTF_Font *font = TTF_OpenFont(TTF_FILE_PATH, 24);
    if(!font) {
        printf("TTF_OpenFont err!\n");
        return 0;
    }
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface *screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    SDL_WM_SetCaption("SDL Test", NULL);

    clear(screen, 0, 0, 0);
    drawText(screen, font, "Hello World!", 0, 0, 255, 255, 255);
    refresh(screen);

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
                            clear(screen, 0, 0, 0);
                            drawText(screen, font, "你好，世界！", 0, 0, 255, 255, 255);
                            refresh(screen);
                            break;
                        }
                        case RG35XX_KEY_B: {
                            clear(screen, 0, 0, 0);
                            drawText(screen, font, "Hello World!", 0, 0, 255, 255, 255);
                            refresh(screen);
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

