/* Controller */

/* C libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/* hardware platform libraries */
#include <mbed.h>

/* asteroids */
#include "model.h"
#include "asteroids.h"

/* Joystick 5-way switch
*/

typedef enum { left,down,right,up,centre } btnId_t; 
DigitalIn joystick[] = {P5_0, P5_1, P5_4, P5_2, P5_3};
bool jsPrsdAndRlsd(btnId_t b);
bool joyStick(btnId_t b) {
	bool result = false;
	uint32_t state;
	static uint32_t savedState[4]  = {1,1,1,1};
	//initially all 1s: nothing pressed
	state = joystick[b].read();
	if ((savedState[b] == 0) && (state == 1)) {
		result = true;
	}
	savedState[b] = state;
	return result;
}

void controls(void)
{
	if(joyStick(right)) {
		angle += angleMove;
	}
	if(joyStick(left)) {
		angle -= angleMove;
	}
	if(joyStick(centre)) {		
		newShot(shots);
	}
	if(joyStick(down)) {
		moveShip();
	}
	if(joyStick(up)) {
		score++;
	}
}
