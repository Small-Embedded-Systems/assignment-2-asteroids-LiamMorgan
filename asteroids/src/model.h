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
extern double shipX, shipXL, shipXR, shipY, shipYL, shipYR;
extern float pi;
