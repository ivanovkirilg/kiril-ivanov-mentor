#include <stdio.h>
#include <unistd.h>

int main()
{
    while (1)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                putchar((i == j) ? '*' : '.');
            }

            fflush(stdout);
            sleep(1);

            putchar('\r');
        }
    }

    return 0;
}
