#ifndef SPRITE_H
#define SPRITE_H
#include "utils.h"



//SPRITE TYPE
typedef struct{
	
	SDL_Texture **texture;
	SDL_Rect    sizeRect;
	u8          numOfAnimation;
	
}Sprite;



Sprite initSprite(const char* name[MAX_CHAR_ARR],u8 numOfAnimation, i16 x, i16 y, i16 w, i16 h);
static inline void renderSprite(Sprite s, u8 numOfAnimation);
static inline u8 checkCollision( SDL_Rect A, SDL_Rect B );

#define SPRITE_IMPLEMENTATION
#ifdef SPRITE_IMPLEMENTATION
Sprite initSprite(const char* name[MAX_CHAR_ARR],u8 numOfAnimation, i16 x, i16 y, i16 w, i16 h){
	
	
	Sprite s;
	if(numOfAnimation >= MAX_SPRITE_ANIMATION - 1){
		ERROR_BREAK("Larger Then %d\n", MAX_SPRITE_ANIMATION);
	}
	SDL_Surface *tempSurface;
	s.texture = calloc((size_t)numOfAnimation, 100);
	for(u8 i = 0; i < numOfAnimation; i++){
		tempSurface = IMG_Load(name[i]);
	  if(tempSurface == NULL){
	  	ERROR_BREAK("Error Loading Surface %s\n", name[i]);
		}
		s.texture[i] = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface); 		
				
	}
	s.numOfAnimation  = 0; //WHAT ANIMATION TO SCREEN
	s.sizeRect.h = h;
	s.sizeRect.w = w;
	s.sizeRect.x = x;
	s.sizeRect.y = y;
	return s;
}

static inline void renderSprite(Sprite s, u8 numOfAnimation){
	#if DEBUG
	if(s.numOfAnimation < numOfAnumation){
		ERROR_BREAK("Sprite does not exist\n");
	}
	#endif	
	SDL_RenderCopy(renderer, s.texture[numOfAnimation],NULL ,&s.sizeRect);

}


static inline u8 checkCollision( SDL_Rect A, SDL_Rect B )
{
   
    i16 leftA, leftB;
    i16 rightA, rightB;
    i16 topA, topB;
    i16 bottomA, bottomB;

    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    if( bottomA <= topB )
    {
        return FALSE;
    }

    if( topA >= bottomB )
    {
        return FALSE;
    }

    if( rightA <= leftB )
    {
        return FALSE;
    }

    if( leftA >= rightB )
    {
        return FALSE;
    }

  
    return TRUE;
}






#endif



#endif