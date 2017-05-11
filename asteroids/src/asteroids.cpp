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

/* Game state */
float elapsed_time; 
int   score;
int   lives;
rock_t *asteroids;
shot_t *shots;
int frames;
int rockCount; int shotCount;
struct ship player;
float Dt = 0.01f;

Ticker model, view, controller;
bool paused = true;
/* The single user button needs to have the PullUp resistor enabled */
DigitalIn userbutton(P2_10,PullUp);

void initialise() {
		asteroids = static_cast<rock_t*>(malloc(sizeof(rock_t)));
		asteroids->p.x = 0;asteroids->p.y =0;
		asteroids->v.x = 2;asteroids->v.y = 2;
		asteroids->next = NULL;
	
		shots = static_cast<shot_t*>(malloc(sizeof(shot_t)));
		shots->next = NULL;	
}

int main() {
		srand(time(0));
				initialise();
    init_DBuffer();	
    view.attach( draw, 0.025);
    model.attach( physics, Dt);
    controller.attach( controls, 0.1);
    lives = 3;    
    while(true) {
    }
}

