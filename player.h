#ifndef PLAYER_H
#define PLAYER_H
#include "sprite.h"
#include "map.h"
i32 playerPosX = 1;
i32 playerPosY = 9;
i32 playerVelX = 0;
i32 playerVelY = 0;
//i32 playerOfsetX = WIDTH  / 2 + tileWidth  / 2;
//i32 playerOfsetY = HEIGHT / 2 + tileHeight / 2;
i32 playerOfsetX = WIDTH   / 2;
i32 playerOfsetY = HEIGHT  / 2;
const char* namePlayer[MAX_CHAR_ARR] ={
	"asset/player/1.png",
	"asset/player/2.bmp",
	"asset/player/3.bmp",
	"asset/player/4.bmp",
};

Sprite player;

void initPlayer(void){
		
		player = initSprite(namePlayer, 4, (i16)playerOfsetX, (i16)playerOfsetY, tileWidth, tileHeight);
}

static inline void renderPlayer(void){
	renderSprite(player, player.numOfAnimation);
}

static inline void playerInputHandling(const u8* stateOfKeyboard){
	
	if(stateOfKeyboard[SDL_SCANCODE_W])
		playerVelY-=5;
	if(stateOfKeyboard[SDL_SCANCODE_A])
		playerVelX--;
	if(stateOfKeyboard[SDL_SCANCODE_D])
		playerVelX++;
	
	
}


static inline void playerEventHandling(void){
	
	
	
	
	
	//playerPosX+= playerVelX * (i32)(SDL_GetTicks64() - curentTime);
	//playerPosY+= playerVelY * (i32)(SDL_GetTicks64() - curentTime);
	playerPosX+= playerVelX;
	playerPosY+= playerVelY;
	LOG("PLAYER POS (%d, %d)\n", playerPosX, playerPosY);
	
	//playerOfsetX = WIDTH   / 2 - playerPosX * tileWidth; 
	//playerOfsetY = HEIGHT  / 2 - playerPosY * tileHeight;
	playerVelX = 0;
	playerVelY = 0;
	//LOG("OFSET X %d OFSET Y %d\n", playerOfsetX, playerOfsetY);
}

#endif