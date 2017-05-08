/* Asteroids model */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "model.h"
#include "utils.h"
#include "asteroids.h"


/* If you want to initialise a linked list:
    You'll have to replace node_t with the right type
*/
typedef struct shots {
    struct shots *next;
} shots_t;
const size_t MAXSize = 10;
shots_t data[MAXSize];
shots_t *initialise()
{
    int c;
    for(c=0 ; c<(MAXSize-1) ; c++){
        data[c].next = &data[c+1];
    }
    data[c].next = NULL;
    return data;
}

void physics(void)
{
    if(xRock >= 490) {
			xRock = 0;
		}
}

