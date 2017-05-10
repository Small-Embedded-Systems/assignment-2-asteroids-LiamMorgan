/* Game state */

extern float elapsed_time; /* time this ship has been active */
extern int   score;        /* total score so far */
extern int   lives;       /* lives remaining */
extern struct ship player;
extern struct rock_t *asteroids; /* array of rocks / pointer to linked-list */
extern struct missile *shots;  /* array of missiles / pointer to linked-list */

extern const float Dt; /* Time step for physics, needed for consistent motion */
