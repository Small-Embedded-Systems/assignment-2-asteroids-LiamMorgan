/* Asteroids Model */
struct point {
    float x,y;
};

typedef struct point coordinate_t;
typedef struct point vector_t;

/* Some insitial struct types if you want to use them */
struct ship {
    coordinate_t p;
    vector_t     v;
};

/* initial struts for building linked lists */
typedef struct rock_t {
		coordinate_t p;
		vector_t v;
    struct rock_t* next;
} rock_t;

typedef struct shot_t {
    coordinate_t p;
		vector_t v;
		int age;
    struct shot_t* next;
} shot_t;


void physics(void);
void newShot(shot_t *head);
void moveShip();
void newRock(rock_t *head);
void updateRocks(rock_t *head);
extern float angle, angleMove;
extern double shipX, shipXL, shipXR, shipY, shipYL, shipYR, shipCX, shipCY;
extern float pi;
extern bool shipGo, shipRight, shipLeft;
