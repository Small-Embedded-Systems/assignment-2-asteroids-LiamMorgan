/* Asteroids model */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "model.h"
#include "utils.h"
#include "asteroids.h"

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
	if(frames % 100 == 0 && shotCount < 15 ) {
			shot_t* current = head;
			while (current->next != NULL) {
					current = current->next;
			}
			current->next = (shot_t*)malloc(sizeof(shot_t));
			current->next->p.x = randrange(16, 465);current->next->p.y =  randrange(16, 257);
			current->next->v.x = randrange(-2, 3);current->next->v.y = randrange(-2, 3);
			if(current->next->v.x == 0 && current->next->v.y == 0)
					current->next->v.x = 1;
			current->next->next = NULL;
			shotCount++;
	}
}

void updateShots(shot_t* head) {
	shot_t *current = head;
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
		
		current = current->next;
		updateShots(current);
	}
}

void physics(void) {
	frames++;
	newRock(asteroids);	
	updateRocks(asteroids);
	newShot(shots);
	updateShots(shots);
}
