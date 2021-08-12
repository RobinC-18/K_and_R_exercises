#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

int fasterbinsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high && mid != x) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    if (x == v[mid]) 
        return mid;
    else 
        return -1;
}

int main(int argc, char *argv[]) {
    int v[] = {1, 2, 3, 4, 5, 6, 8, 9}; 

    int x = 1;
    
    clock_t start_time, end_time;
    start_time = clock();
    int res_slow = binsearch(x, v, 8);
    end_time = clock();
    double time_taken;
    time_taken = (double) (end_time - start_time)/CLOCKS_PER_SEC;

    if (res_slow == -1) {
        printf("No value found \n");
    } else {
        printf("%d has been found at position %d \n", x, res_slow);
        printf("Slow bin search took %f \n", time_taken);
    }

    start_time = clock();
    int res_fast = binsearch(x, v, 8);
    end_time = clock();

    time_taken = (double) (end_time - start_time)/CLOCKS_PER_SEC;

    if (res_slow == -1) {
        printf("No value found \n");
    } else {
        printf("%d has been found at position %d \n", x, res_fast);
        printf("Slow bin search took %f \n", time_taken);
    }

}