#include<float.h>    // for easier comparison
#include<math.h>    // for distance measuring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>    // for random
#define MEMORY_ALLOCATION_ERROR "\n\nError occurred during memory allocation...\n\n"

struct Point {
    double x;
    double y;
    double z;
    double mass;
};

typedef struct Point Point;

Point *points;

/* main functions */
void gen_array(int);

int find_min(int n);

int find_nearest(int, int);

double dist_3d(double x1, double y1, double z1, double x2, double y2, double z2);

void add_mass(int old_index, int new_index);

void del_point(int, int);

// for easier testing the program
void debug(int n);

double rand_double(double, double);

void point_info(int);

// for easier input
int enter_int(char *);

double enter_double(char *);

void result();

int main() {
    int round_index = 0;
    int min_p_index;
    int nearest_point_index;

    // prep for generating really random numbers
    srand((unsigned int) time(NULL));

    // make while cycle where suggest a person to add some points
    printf("PointTask\n");


    // enter amount of points
    int count = enter_int("How many points do you want to generate?\n> ");
    if (count <= 1) {
        printf("Too small an amount was enterred.\n");
        return 1;
    }