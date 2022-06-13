#include <stdio.h>

union FourBytes
{
    unsigned int u;
    signed int i;
    float f;
    unsigned char uc[4];
};

// struct:
// [ u  | i  | f  ]

// union:
// [uif ]

// 00000010 00000000 00000000 00000000

int main()
{
    union FourBytes bytes = { 2 };

    printf("%u %d %f\n", bytes.u, bytes.i, bytes.f);

    printf("%02x %02x %02x %02x\n", bytes.uc[0], bytes.uc[1], bytes.uc[2], bytes.uc[3]);

    printf("%d\n", (bytes.f == 0.0f));
}
