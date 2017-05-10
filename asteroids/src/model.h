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
    rock_t *next;
} rock_t;

struct missile {
    coordinate_t p;
    struct missile *next;
};


void physics(void);

extern int rockCount;
void addRockEnd(rock_t *head);
