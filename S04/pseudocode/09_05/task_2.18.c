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

// define some number to test with, eg 1 + 4 + 16 (*.*.)
// for each bit / lamp in the number / sequence
// ( ... this loop is for each line of output )
//      for each bit / lamp
//      ( ... this is for printing each lamp in this line )
//          if it's this lamp's turn, and it is switched on (bit is set in the number)
//              print an *
//          otherwise, print a .
//      print a newline and sleep
