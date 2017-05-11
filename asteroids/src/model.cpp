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
	if(frames % 100 == 0) {
    rock_t* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (rock_t*)malloc(sizeof(rock_t));
    current->next->p.x = randrange(16, 465);current->next->p.y =  randrange(16, 257);
		current->next->v.x = randrange(-5, 6);current->next->v.x = randrange(-5, 6);
    current->next->next = NULL;
		rockCount++;
	}		
}

void drawRocks() {
	
}
 
void physics(void) {
	frames++;
	newRock(asteroids);
	
}
