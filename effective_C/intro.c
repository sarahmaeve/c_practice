#include <stdio.h>

typedef struct point_t {
    int x;
    int y;
    char z[30];
} point_t;

// memory layout functions from "Extreme C" p.45
void printSize(point_t* var) {
    printf("Size %lu bytes\n", sizeof(*var));
}

void printBytes(struct point_t* var) {
    unsigned char* ptr = (unsigned char*)var;
    for (int i = 0; i < sizeof(*var); i++, ptr++) {
        printf("%d ", (unsigned int) *ptr);
    }
}

int main() {
    point_t myPoint = {5, 10};
    point_t *ptrPoint = &myPoint;

    point_t *ptrSecondPoint = &(point_t) { 12, 24};

    printf("Point One: X: %d Y: %d\n", myPoint.x, myPoint.y);
    ptrPoint->x = 6;
    ptrPoint->y = 12;

    printf("Point One: X: %d Y: %d\n", myPoint.x, myPoint.y);

    printf("Point Two: X: %d, Y: %d\n", ptrSecondPoint->x, ptrSecondPoint->y);
    printSize(&myPoint);
    printBytes(ptrSecondPoint);
    return 0;
}