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

const colour_t background = rgb(0,0,0); /* Black */

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

void draw_sidebar(int score, int elapsed_time, int lives) {
		graphics->fillScreen(background);
		graphics->fillRect(0,0,480,22,WHITE);
		graphics->drawRect(0,0,480,272,WHITE);
}

void drawMissiles(void) {
}

void drawRocks(void) {
	
}

void drawShip(ship player) {
}

void draw(void)
{
	
		draw_sidebar(score, elapsed_time, lives );
		drawMissiles();
		drawRocks();
		drawShip(player);

		swap_DBuffer();
}
