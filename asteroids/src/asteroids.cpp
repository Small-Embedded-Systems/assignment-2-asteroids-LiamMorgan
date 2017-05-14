/* Asteroids
Sample solution for assignment
Semester 2 -- Small Embedded Systems
Dr Alun Moon
*/

/* C libraries */
#include <stdlib.h>

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

/* hardware platform libraries */
#include <display.h>
#include <mbed.h>

/* Main game elements */
#include "model.h"
#include "view.h"
#include "controller.h"
#include "utils.h"

/* Game state */
float elapsed_time;
int   score = 0;
int   lives = 3; int shields = 3;
int frames; int endFrames;
float Dt = 0.01f;
bool paused = 1; bool endGame = 0;

rock_t *asteroids;
shot_t *shots;
Ticker model, view, controller;

/* The single user button needs to have the PullUp resistor enabled */
DigitalIn userbutton(P2_10,PullUp);

//Initialise the linked lists of asteroids and shots.
void init_Lists() {
	asteroids = static_cast<rock_t*>(malloc(sizeof(rock_t)));
	asteroids->p.x = randrange(16, 465);asteroids->p.y =  randrange(16, 257);
	asteroids->v.x = randrange(-1, 2);asteroids->v.y = randrange(-1, 2);
	asteroids->next = NULL;
	
	shots = static_cast<shot_t*>(malloc(sizeof(shot_t)));
	shots->next = NULL;
}
//Reset variables on game restart.
void resetValues() {
	lives = 3;
	shields = 3;
	score = 0;
	shipCX = 240; shipCY = 146;
	shipGo = false; shipLeft = false; shipRight = false;
	angle = 0.0;
	endFrames = 0;
}

int main() {
	init_Lists();
	init_DBuffer();
	
	view.attach( draw, 0.025);
	model.attach( physics, Dt);
	controller.attach( controls, 0.1);
	
	while(true) {
	}
}
