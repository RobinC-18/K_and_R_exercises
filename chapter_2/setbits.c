#include <stdlib.h>
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    y = (~(~0 << n) & y) << (p+1-n);

    x = ~(~(~0 << n) << (p+1-n)) & x;

    return x | y;

}

unsigned rightrot(unsigned x, int n) {
    return (x >> n) | (x << ((sizeof(unsigned) * 8)-n));
}

unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p+1-n));
}

int main(int argc, char *argv[]) {

    unsigned x_rightrot = 7;
    unsigned x_invert = 255;
    unsigned x = 4;
    unsigned y = 3;
    int p = 1;
    int n = 2;
    unsigned res = setbits(x, p, n, y);

    printf("%u \n", res);

    printf("%u \n", invert(x_invert, 1, 2));

    printf("%u \n", rightrot(x_rightrot, 2));


}