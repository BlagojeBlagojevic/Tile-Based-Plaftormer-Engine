#ifndef ENEMY_H
#define ENEMY_H
#include "utils.h"
#include "sprite.h"
#include "map.h"


Sprite enemy;
u8 enemyCounter = 0;
#define MAX_ENEMY 30

typedef struct {
	i32 x;
	i32 y;
	u8 direction;
	} Enemy;

Enemy e[MAX_ENEMY];

void initEnemy(void);
static inline void renderEnemy(void);
static inline void enemyInputHandling(const u8* stateOfKeyboard);
static inline void enemyEventHandling(void);

const char* nameEnemy[MAX_CHAR_ARR]= {
	"asset/monster/enemy.png",
	};


#define ENEMY_IMPLEMENTATION
#ifdef  ENEMY_IMPLEMENTATION

void initEnemy(void) {
	enemy = initSprite(nameEnemy, 1, 0, 0, tileWidth, tileHeight);
	for(i32 y = 0; y < mapHeight;  y++) {
		for(i32 x = 0; x < mapWidth; x++) {
			if(MAP(y, x) == 'M') {
				e[enemyCounter].x = x;
				e[enemyCounter].y = y;
				e[enemyCounter].direction = 0;

				enemyCounter++;
				LOG("ENEMY COUNTER %d %d", e[enemyCounter- 1].x, e[enemyCounter - 1].y);
				if(enemyCounter == MAX_ENEMY) {
					ERROR_BREAK("EXCITED MAX NUM OF PLAYERS\n");
					}
				//system("pause");
				}

			}
		}

	}

static inline void renderEnemy(void) {
	for(u8 i = 0; i < enemyCounter; i++) {
		enemy.sizeRect.x = e[i].x;
		enemy.sizeRect.y = e[i].y;
		enemy.sizeRect.x = (e[i].x - playerPosX)*tileWidth + playerOfsetX;
		enemy.sizeRect.y = (e[i].y  - playerPosY)*tileHeight + playerOfsetY;
		//i32 ofsetSpriteX = x; //- playerOfsetX / tileWidth ;
		//i32 ofsetSpriteY = y; //- playerOfsetY / tileHeight;
		renderSprite(enemy, 0);
		}

	}



static inline void enemyEventHandling(void) {
	
	for(u8 i = 0; i < enemyCounter; i++) {
		if(e[i].direction == 0) {
			if(MAP(e[i].y, e[i].x + 1) == '.') {
				MAP_SET(e[i].y, e[i].x) = '.';
				MAP_SET(e[i].y, e[i].x + 1) = 'M';
				e[i].x++;
				}
			else {
				e[i].direction = 1;
				}

			}
			else{
			if(MAP(e[i].y, e[i].x - 1) == '.') {
				MAP_SET(e[i].y, e[i].x) = '.';
				MAP_SET(e[i].y, e[i].x - 1) = 'M';
				e[i].x--;
				}
			else {
				e[i].direction = 0;
				}
			
				
			}
			
			
			
		}


	}

#endif
#endif