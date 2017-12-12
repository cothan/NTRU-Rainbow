#include "randombytes.h"

void randombytes(int size, int q)
{
    srand(time(0));
    unsigned char *r = (unsigned char *)calloc(size, sizeof(unsigned char));
    int i;
    for (i = 0; i < size; i++)
    {
        r[i] = (unsigned char)(rand() % q);
    }
    return r;
}