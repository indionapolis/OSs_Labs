#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int x = INT_MAX;
    float y = FLT_MAX;
    double z = DBL_MAX;

    printf("INT_MAX = %d\n", x);
    printf("SIZE_OF_INT_MAX = %lu (bite)\n", (unsigned long) sizeof(x));
    printf("FLT_MAX = %e\n", y);
    printf("SIZE_OF_FLT_MAX = %lu (bite)\n", (unsigned long) sizeof(y));
    printf("DBL_MAX = %e\n", z);
    printf("SIZE_OF_DBL_MAX = %lu (bite)\n", (unsigned long) sizeof(z));


    return 0;
}