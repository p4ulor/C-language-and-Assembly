#include <stdio.h> //functions that deal with standard input and output like printf()
#include <stdlib.h> //for malloc(), calloc(), free(), atoi(), rand(), etc
#include <string.h> //for strlen(), strcat(), memcpy(), memset(), etc

#define MAX = 100

// STRUCTS
// defining
struct Point1 {
    double x, y;
};

struct Point1 p1;

typedef struct Point1 PointFinal;

PointFinal p2;

typedef struct Point {
    double x, y;
} Point;

void deckaringStructs(){
    Point p;
    p.x = 2.0;
    p.y = 2.0;

    Point p2 = {
        p1.x = 1,
        .y = 2
    };

    Point* p3 = malloc(sizeof(Point));
}

Point getMiddlePoint(Point a, Point b){
    Point m;
    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;
    return m;
}

Point* getMiddlePointByReference(Point* a, Point* b){
    //Point m; //this will allocatted on the stack, which can lead to problems, so we need to use malloc()
    Point* m = malloc(sizeof(Point)); 
    m->x = (a->x + b->x) / 2;
    m->y = (a->y + b->y) / 2;
    return &m;
}

void getMiddlePointByReferenceV2(Point* a, Point* b, Point* m){
    m->x = (a->x + b->x) / 2;
    m->y = (a->y + b->y) / 2;
}

void testgetMiddlePoint(){
    Point p1 = {
        .x = 1,
        .y = 1
    };
    Point p2 = {
        .x = 3,
        .y = 3
    };

    Point middle = getMiddlePoint(p1, p2); //copies the values

    Point* middle2 = getMiddlePointByReference(&p1, &p2); //pass by reference
    free(middle2);

    Point middle3;
    getMiddlePointByReferenceV2(&p1, &p2, &middle);
}

int main(int argc, char* argv[]){

    return 0;
}
