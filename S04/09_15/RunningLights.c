/* 
Упражнение 18* Направете бягаща светлина, като приемете, че всеки бит от
дадена променлива, е свързан с лампа (или светодиод). Когато битът е
нула, лампата не свети, когато е единица свети.
Примерно, ако генерирате последователност:
1, 2, 3, 4, се получава следното:
1 *....................
2 .*...................
4 ..*..................
8 ...*................. ...
За да генерирате закъснение, използвайте следната функция от C runtime:
#include <unistd.h>
unsigned int sleep(unsigned int seconds);
 */

#include <stdio.h>
#include <unistd.h>

int main()
{
    unsigned int number = 246529873;
    const int bits_per_byte = 8;
    const int bits_in_number = sizeof(number) * bits_per_byte;

    for (int i = bits_in_number - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            putchar('.');
        }

        // Option 1
        // if (number & (1 << i))
        // {
        //     putchar('*');
        // }
        // else
        // {
        //     putchar('.');
        // }

        // Option 2
        // putchar((number & (1 << i)) ? '*' : '.');

        // Option 3
        const char lamp_state = (number & (1 << i)) ? '*' : '.';
        putchar(lamp_state);

        for (int j = i + 1; j < bits_in_number; j++)
        {
            putchar('.');
        }
        putchar('\n');
        sleep(1);
    }

    return 0;
}
