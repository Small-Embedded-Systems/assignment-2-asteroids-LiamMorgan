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
float angle = 0.0, angleMove = 0.66;
int radius =15;
float velX, velY;
float accel = 1;
///////////////////////////////////

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
		if(current != NULL) {
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
				current->p.x = randrange(16, 465);current->p.y =  randrange(16, 257);
				shields--;
				if(shields < 0) {
					lives--;
					if(lives <= 0)
						paused = 1;
				}
			}
			current = current->next;
			updateRocks(current);
	}
}
 
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
	shotCount++;
}

void updateShots(shot_t* head) {
	shot_t *current = head;
	while(current != NULL) {
		current->p.x += current->v.x;current->p.y += current->v.y;
		current = current->next;
	}
}

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
}

void moveShip() {
	velX = (10 * cos (angle));
	velY = (10 * sin (angle));
	shipCX += (velX / accel);
	shipCY += (velY / accel);					
}

void physics(void) {
	frames++;
	shipRot();
	newRock(asteroids);	
	updateRocks(asteroids);
	updateShots(shots);
}