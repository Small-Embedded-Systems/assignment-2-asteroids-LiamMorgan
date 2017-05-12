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
			graphics->drawTriangle(i*15,22,(i*15)-5,42,(i*15)+5,42, WHITE);
		}
		graphics->setTextSize(1);
		graphics->setCursor(10,10);
		graphics->printf("Lives");
		graphics->setCursor(230,10);
		graphics->printf("Score");
		graphics->setCursor(240,22);
		graphics->printf("%d", score);
		graphics->setCursor(430,10);
		graphics->printf("Shields");
		for(int i=1;i<=shields;i++) {			
			graphics->drawCircle(i*22+400, 30, 8, BLUE);
		}
		graphics->setCursor(20,100);
		graphics->printf("Frames = %d", frames);
		graphics->setCursor(20,120);
		graphics->printf("rockCount = %d", rockCount);
		graphics->setCursor(20,140);
		graphics->printf("shotCount = %d", shotCount);
		graphics->setCursor(20,160);
		graphics->printf("Paused status = %d", paused);
}

void drawShip() {
	if(shields > 0) {
		for(int i = 0; i < shields; i++) {
			graphics->drawCircle(shipCX, shipCY, 20+(i*3), BLUE);
		}		
	}
	graphics->drawLine(shipX,shipY,shipXL,shipYL,WHITE); //Left
	graphics->drawLine(shipXL,shipYL,shipXR,shipYR,WHITE); ////Right
	graphics->drawLine(shipXR,shipYR,shipX,shipY,WHITE);//Bottom			
}

void drawShots(shot_t *head) {
	shot_t* current = head;
	while (current != NULL) {
		graphics->drawCircle(current->p.x,current->p.y ,2, WHITE);
		current = current->next;
  }
}

void drawRocks(rock_t *head) {
	rock_t* current = head;
	while (current != NULL) {
		graphics->drawBitmap(current->p.x,current->p.y,asteroid1, 16,16, WHITE);
		current = current->next;
  }
}

void draw(void)
{	
	drawInfo();
	drawShip();
	drawShots(shots);
	drawRocks(asteroids);
	swap_DBuffer();
}