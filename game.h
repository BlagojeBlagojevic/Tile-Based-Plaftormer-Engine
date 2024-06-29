#ifndef GAME_H
#define GAME_H
#include "utils.h"
#include "sprite.h"
#include "map.h"
#include "player.h"
#include "enemy.h"
void                initGame(void);
static inline void  eventHandler(void);
static inline void  inputHandler(void);
static inline void  mainRenderer(void);
static inline void  gameLoop(void);




//GAME VARS








#define GAME_IMPLEMENTATION
#ifdef  GAME_IMPLEMENTATION

void initGame(void){
		if(SDL_Init(SDL_INIT_EVERYTHING)) {
		ERROR_BREAK("Init Error!!!\n");
		}

	SDL_Window *window =  SDL_CreateWindow(
	                        "asd",
	                        SDL_WINDOWPOS_CENTERED,
	                        SDL_WINDOWPOS_CENTERED,
	                        WIDTH,
	                        HEIGHT,
	                        SDL_WINDOW_OPENGL
	                      );
	if(window == NULL) {
		ERROR_BREAK("Window not inited!!!\n");
		}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if(renderer == NULL) {
		ERROR_BREAK("Renderer not init!!!\n");
		}
	isClose = FALSE;
	
	
	
	initMap();
	initPlayer();
	initEnemy();
	
}
static inline void inputHandler() {

	const u8* stateOfKeyboard = SDL_GetKeyboardState(NULL);
	playerInputHandling(stateOfKeyboard);
	LOG("HANDLING USER INPUT\n");

	}


static inline void eventHandler(void) {
	//STA GOD DAL STATIC ILI NE
	
	mapEventHandling();
	if(loopIteratonCounter%10 == 0)
		enemyEventHandling();
	playerEventHandling();
	static SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {

			case SDL_QUIT: {
					LOG("Window Closed!!!\n");
					isClose = TRUE;
					break;
					}
			}
		}
	}


int x;
static void mainRenderer() {
	SDL_RenderClear(renderer);
	
	SDL_SetRenderDrawColor(renderer, 0,0, 255, 255);
	//renderSprite(s, x);	
	//x++;
	//PAINTERS ALGHOITHAM
	
	
	renderMap();
	renderEnemy();
	renderPlayer();
	
	//ren
	//OTHTE SHIT
	SDL_RenderPresent(renderer);
	//SDL_Delay(1000);
	}




static inline void gameLoop() {
	//frameStartTime = SDL_GetTicks64();
	//i32 counter = 0;
	while(!isClose) {
		curentTime = SDL_GetTicks64();
		loopIteratonCounter++;
		//if(!loopIteratonCounter%2)
			inputHandler();	
		eventHandler();
		mainRenderer();
		passedTime = SDL_GetTicks64() - curentTime;
		if(passedTime < TARGETTIME) {
			SDL_Delay((u32)(TARGETTIME - passedTime));
			LOG("passed time %u\n", ((u32)(TARGETTIME - passedTime)));
			}



		}


	}






#endif

#endif