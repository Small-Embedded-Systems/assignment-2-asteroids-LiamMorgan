/* Asteroids view
*/

/* C libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/* hardware platform libraries */
#include <display.h>
#include <mbed.h>

#include "asteroids.h"
#include "model.h"
#include "utils.h"
#include "objects.h"

Display *graphics = Display::theDisplay();

/* double buffering functions */

void init_DBuffer(void)
{   /* initialise the LCD driver to use second frame in buffer */
    uint16_t *bufferbase = graphics->getFb();
    uint16_t *nextbuffer = bufferbase+ (480*272);
    LPC_LCD->UPBASE = (uint32_t)nextbuffer;
}

void swap_DBuffer(void)
{   /* swaps frames used by the LCD driver and the graphics object */
    uint16_t *buffer = graphics->getFb();
    graphics->setFb( (uint16_t*) LPC_LCD->UPBASE);
    LPC_LCD->UPBASE = (uint32_t)buffer;
}

void drawInfo() {
		graphics->fillScreen(BLACK);
		graphics->drawRect(0,0,480,272,WHITE);
		for(int i=1;i<=lives;i++) {			
			graphics->drawTriangle(i*20,10,(i*20)-5,30,(i*20)+5,30, WHITE);
		}
		graphics->setCursor(400,20);
		graphics->printf("Frames = %d", frames);
		graphics->setCursor(360,40);
		graphics->printf("rockCount = %d", rockCount);
}

void drawShip() {
}

void drawShots() {
}

void drawRocks(rock_t *head) {
	//Get Position of every rock from linked list and draw it
	//Model handles the updating of position by using rock->p.x += rock->v.x etc.
	//I think iterate method has to go here, not in model
	//Pressing cntr on control should  draw new randomly moving rock on screen, and count++
}

void draw(void)
{	
		drawInfo();
		//drawShip();
		//drawShots();
		//drawRocks(rocks);
		swap_DBuffer();
}
