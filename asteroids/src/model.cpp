/* Asteroids model */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "model.h"
#include "utils.h"
#include "asteroids.h"

float pi = 3.1415926f;

void newRock(rock_t* head) {
	if(frames % 100 == 0 && rockCount < 15 ) {
    rock_t* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (rock_t*)malloc(sizeof(rock_t));
    current->next->p.x = randrange(16, 465);current->next->p.y =  randrange(16, 257);
		current->next->v.x = randrange(-2, 3);current->next->v.y = randrange(-2, 3);
		if(current->next->v.x == 0 && current->next->v.y == 0)
				current->next->v.x = 1;
    current->next->next = NULL;
		rockCount++;
	}
}

void updateRocks(rock_t* head) {
	rock_t* current = head;
	if (current != NULL) {
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
	current->next->p.x = 200;current->next->p.y =  200;
	current->next->v.x = 2;current->next->v.y = 0;
	current->next->age = frames;
	current->next->next = NULL;
	shotCount++;
}

void updateShots(shot_t* head) {
	shot_t *current = head;
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
		current = current->next;
	}
}
double x, x1, x2, y, y1, y2;
float angle = 0.0, angleMove = 0.05;
int radius =15;


void shipRot() {
	x = radius * cos (angle);
	x1 = radius * sin (angle + 2.35619);
	x2 = radius * cos (angle + 3.92699);
	y = radius * sin (angle);
	y1 = radius * cos (angle + 2.35619);
	y2 = radius * sin (angle + 3.92699);
	
	shipX = x + shipX;
	shipY = y + shipY - 10;
	shipXL = x1 + shipX + 5;
	shipYL = y1 + shipX + 10;
	shipXR = x2 + shipX - 5;
	shipYR = y2 + shipX + 10;
	
	if(angle > 2 * pi) {
		angle = 0.1;
	}
	if(angle < 0) {
		angle = (2 * pi) - 0.1;
	}
	
}

void physics(void) {
	frames++;
	newRock(asteroids);	
	updateRocks(asteroids);
	updateShots(shots);
}
