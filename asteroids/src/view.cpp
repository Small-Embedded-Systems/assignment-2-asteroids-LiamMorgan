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
		graphics->setCursor(400,20);
		graphics->printf("Frames = %d", frames);
		graphics->setCursor(360,40);
		graphics->printf("rockCount = %d", rockCount);
		graphics->setCursor(360,60);
		graphics->printf("shotCount = %d", shotCount);
}

void drawShip() {
	graphics->fillTriangle(
	player.p.x,player.p.y,player.p.x-5,player.p.y+20,player.p.x+5,player.p.y+20, WHITE);
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

void endScreen() {
	graphics->fillScreen(BLACK);
	graphics->drawRect(0,0,480,272,WHITE);
	graphics->setCursor(20, 136);
	graphics->setTextSize(4);
	graphics->printf("Game over.");
	graphics->setCursor(20, 200);
	graphics->setTextSize(2);
	graphics->printf("Press start to play again.");
}

void draw(void)
{	
	drawInfo();
	drawShip();
	drawShots(shots);
	drawRocks(asteroids);
	swap_DBuffer();
}
