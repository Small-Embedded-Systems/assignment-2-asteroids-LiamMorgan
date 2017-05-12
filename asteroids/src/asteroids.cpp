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
float Dt = 0.01f;
int paused = 0;

rock_t *asteroids;
shot_t *shots;
int frames;
int rockCount; int shotCount;
double shipCX = 240; double shipCY = 146;
double shipX, shipY;
double shipXL = shipCX - 7; double shipXR = shipCX + 7;
double shipYL = shipCY + 10; double shipYR = shipCY + 10;

Ticker model, view, controller;

/* The single user button needs to have the PullUp resistor enabled */
DigitalIn userbutton(P2_10,PullUp);

void initialise() {
		asteroids = static_cast<rock_t*>(malloc(sizeof(rock_t)));
		asteroids->next->p.x = randrange(16, 465);asteroids->next->p.y =  randrange(16, 257);
		asteroids->next->v.x = randrange(-1, 2);asteroids->next->v.y = randrange(-1, 2);
		asteroids->next = NULL;
	
		shots = static_cast<shot_t*>(malloc(sizeof(shot_t)));
		shots->next = NULL;
}

int main() {
		initialise();	
    init_DBuffer();	
    view.attach( draw, 0.025);
    model.attach( physics, Dt);
    controller.attach( controls, 0.1);   
    while(true) {
    }
}