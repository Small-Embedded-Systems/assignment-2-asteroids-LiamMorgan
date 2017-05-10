/* Asteroids model */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "model.h"
#include "utils.h"
#include "asteroids.h"
/* If you want to initialise a linked list:
    You'll have to replace node_t with the right type
*/
	rock_t *head;
	coordinate_t p = head->p;
	vector_t v = head->v;
	int rockCount = 0;

const size_t MAXSize = 10;
rock_t data[MAXSize];
rock_t *initialise() {
		int c;
    for(c=0 ; c<(MAXSize-1) ; c++){
        data[c].next = &data[c+1];
    }
    data[c].next = NULL;
    return data;
}

void addRockEnd(rock_t *head) { 																					//Add to end of Rock list
	rock_t *newRock =(rock_t *)malloc(sizeof(rock_t));
	/*if(newRock == NULL) {
		exit(1); 																													//If newRock is invalid exit method
	}*/
	newRock->p.x = randrange(16,465); newRock->p.y = randrange(16,157); 
	newRock->v.x = randrange(-5,6); newRock->v.y = randrange(-5,6);					//assign newRocks position values
	newRock->next = NULL; 																									//New rock is last in list
	if(head->next == NULL) {
		head->next = newRock;
		rockCount++;
	} else {
			rock_t *current = head;
			while(current->next != NULL) {
				current = current->next; 																					//Iterate until at end of list			
			}
		current->next = newRock;
		rockCount++;
	}
}

int countAsteroids(rock_t *head) {
	return -1;
}

void physics(void) {
}
