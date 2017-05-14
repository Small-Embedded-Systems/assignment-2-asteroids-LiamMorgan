/* Asteroids model */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "model.h"
#include "utils.h"
#include "asteroids.h"
///////////////////////////////////
float pi = 3.1415926f;
double x, x1, x2, y, y1, y2;
float angle = 0.0, angleMove = 0.02;
int radius =15;
float velX, velY;
bool shipGo = false; bool shipLeft = false; bool shipRight = false;
double shipCX = 240; double shipCY = 146;
double shipX, shipY;
double shipXL = shipCX - 7; double shipXR = shipCX + 7;
double shipYL = shipCY + 10; double shipYR = shipCY + 10;

int shotX, shotY;
///////////////////////////////////
//rock functions
void newRock(rock_t* head) {
	if(frames % 100 == 0 && rockCount < 10 ) {
    rock_t* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (rock_t*)malloc(sizeof(rock_t));
    current->next->p.x = randrange(16, 465);current->next->p.y =  randrange(16, 257);
		current->next->v.x = randrange(-1, 2);current->next->v.y = randrange(-1, 2);
		if(current->next->v.x == 0 && current->next->v.y == 0)
			current->next->v.x = randrange(-1, 2);current->next->v.y = randrange(-1, 2);
		if(((current->next->p.x - shipCX) <= 10 && (current->next->p.x + shipCX) >= 10)
				|| ((current->next->p.y - shipCY) <= 10 && (current->next->p.y + shipCY) >= 10)) {
			current->next->p.x = randrange(16, 465);
			current->next->p.y = randrange(16, 257);
		}
    current->next->next = NULL;
		rockCount++;
	}	
}

void updateRocks(rock_t* head) {
	rock_t* current = head;
		while(current != NULL) {
			current->p.x += current->v.x;current->p.y += current->v.y;
			if(current->p.x > 496) {
				current->p.x = -16;
			}
			if(current->p.x < -16) {
				current->p.x = 496;
			}
			if(current->p.y > 290) {
				current->p.y = -20;
			}
			if(current->p.y < -20) {
				current->p.y = 290;
			}
			if(current->p.x <= shipCX && current->p.x >= shipCX - 15 
				&& current->p.y >= shipCY - 15 && current->p.y <= shipCY + 15) 
			{
				current->p.x = rand()%480;current->p.y = rand()%272;
				shields--;
				if(shields < 0) {
					lives--;
					if(lives <= 0) {
						endGame = 1;
						paused = 1;
						endFrames = frames;
					}
				}
			}
			if(current->p.x <= shotX && current->p.x + 16 >= shotX
&& current->p.y + 16 >= shotY && current->p.y <= shotY) {
		current->p.x = rand()%480;
		current->p.y = rand()%272;
		score ++;
   }
			current = current->next;
	}
}
//end Rock functions
//shot functions
void newShot(shot_t* head) {
	shot_t* current = head;
	while (current->next != NULL) {
			current = current->next;
	}
	current->next = (shot_t*)malloc(sizeof(shot_t));
	current->next->p.x = shipCX;current->next->p.y =  shipCY;
	current->next->v.x = velX/1.5;current->next->v.y = velY/1.5;
	current->next->age = frames;
	current->next->next = NULL;
}

void updateShots(shot_t* head) {
	shot_t *current = head;
	while(current != NULL) {
		if((frames - current->age) >= 200) {
			current->p.x += NULL;current->p.y += NULL;
		} else {
			current->p.x += current->v.x;current->p.y += current->v.y;			
			shotX = current->p.x; shotY = current->p.y;
		}
		current = current->next;
	}
}
//end shot functions
//ship functions
void shipRot()
{
    //go through all angles from 0 to 2 * PI radians
	x = radius * cos (angle);
	y = radius * sin (angle);
	x1 = radius * cos (angle + 2.35619);
	y1 = radius * sin (angle + 2.35619);
	x2 = radius * cos (angle + 3.92699);
	y2 = radius * sin (angle + 3.92699);
	shipX = x + shipCX;
	shipY = y + shipCY;
	shipXL = x1 + shipCX;
	shipYL = y1 + shipCY;
	shipXR = x2 + shipCX;
	shipYR = y2 + shipCY;
	velX = (10 * cos (angle));
	velY = (10 * sin (angle));
	if(shipLeft) {
		shipRight = false;
		angle += angleMove;
	}
	if(shipRight) {
		shipLeft = false;
		angle -= angleMove;
	}
}

void moveShip() {
	if(shipGo) {
		velX = (10 * cos (angle));
		velY = (10 * sin (angle));
		shipCX += (velX / 15);
		shipCY += (velY / 15); // (vel/x) slows velocity, higher number slower ship

	}		
}

void wrapShip() {
	if (shipCX > 500)
		shipCX =  -20;
	if (shipCX < -20)
		shipCX =  500;
	if (shipCY > 292)
		shipCY =  -20;
	if (shipCY < -20)
		shipCY =  292;
	
}
//end ship functions
void physics(void) {
	if(!endGame) {
		frames++;
		shipRot();
		moveShip();
		wrapShip();
		newRock(asteroids);	
		updateRocks(asteroids);
		updateShots(shots);
	}		
}
