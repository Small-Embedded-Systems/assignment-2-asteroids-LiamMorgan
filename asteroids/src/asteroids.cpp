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
int frames;
int rockCount = 0;
struct ship player;
float Dt = 0.01f;

Ticker model, view, controller;
bool paused = true;
/* The single user button needs to have the PullUp resistor enabled */
DigitalIn userbutton(P2_10,PullUp);
int main() {
	
		asteroids = static_cast<rock_t*>(malloc(sizeof(rock_t)));
		asteroids->next = NULL;
	
	
    init_DBuffer();	
    view.attach( draw, 0.025);
    model.attach( physics, Dt);
    controller.attach( controls, 0.1);
    lives = 3;    
    while(true) {
    }
}
