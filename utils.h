#ifndef UTILS_H
#define UTILS_H


#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_hints.h>
#include<SDL2/SDL_error.h>
#include<SDL2/SDL_log.h>
#include<SDL2/SDL_video.h>
#include<SDL2/SDL_render.h>
#include<SDL2/SDL_pixels.h>
#include<SDL2/SDL_rect.h>
#include<SDL2/SDL_surface.h>
#include<SDL2/SDL_clipboard.h>
#include<SDL2/SDL_events.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDl_timer.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_scancode.h>
#undef main

//TYPES
#include<stdint.h>
typedef  uint8_t  u8;
typedef  uint16_t u16;
typedef  uint32_t u32;
typedef  uint64_t u64;
typedef  int16_t  i16;
typedef  int32_t  i32;
typedef  int64_t  i64;
typedef  float    f32;
typedef  double   f64;

//BOOL
enum {FALSE, TRUE};

//ERROR AND LOG HANDLING

#define ERROR(...)        fprintf(stdout, __VA_ARGS__)
#define ERROR_BREAK(...)  fprintf(stderr, __VA_ARGS__); exit(-1)
#define LOG(...)     			fprintf(stdout, __VA_ARGS__) 
#define PAUSE()           system("pause")
#define CLAMP(X, LOW, HIGH) if(X < LOW) X = LOW; if(X > HIGH) X = HIGH;



//MAIN VARS
#define DEGUG 1
#define WIDTH  1600
#define HEIGHT 800
#define MAX_CHAR_ARR 50
#define MAX_SPRITE_ANIMATION 30 
#define MAX_SIZE_OF_SDL_TEXTURE_POINTER 100
 
SDL_Window   *window;
SDL_Renderer *renderer;
u8 isClose = FALSE;


const i32 tileWidth  = 100;
const i32 tileHeight = 100;
const i32 visibleTilesX = WIDTH / tileWidth;
const i32 visibleTilesY = HEIGHT / tileHeight;

#define FPS (u64)15
#define TARGETTIME (u64)(1000 / FPS)
u64 curentTime;
u64 passedTime;

u64 loopIteratonCounter = 0;





#endif
