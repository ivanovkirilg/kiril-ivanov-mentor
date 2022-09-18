/*
Задача 12 Напишете програма на C, която с помощта на цикъл while намира gcd(a,b) – найголемият общ делител на две числа a и b, които се въвеждат.
За целта използвайте алгоритъма на Паскал
Ако двете числа са равни, то всяко от тях е НОД, иначе от по-голямото изваждаме по-малкото,
докато двете станат равни.
*/

// gcd()
// take two numbers as parameters
//      while they are different
//          if the first one is larger,
//              subtract the second one from it
//          otherwise subtract it from the second one
//          (on other words, subtract the smaller from the larger)
//      return either one of them (they must now be the same)

// main()
//      check the result of gcd():
//          numbers     expected result
//          1   1       1   (this is called a sanity check)
//          8   2       2
//          9   4       1
//          15  6       3
//          6   15      3
//      what happens if one of the numbers is 0?
//          what can we do about this?
//          is this the only problematic input?
