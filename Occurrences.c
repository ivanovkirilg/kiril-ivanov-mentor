/* 
17.05.2022
4. Напишете програма, която да брои колко пъти се среща едно число в даден масив
от цели числа. Масивът трябва да бъде въведен от клавиатурата. Принтирайте
резултатите.
*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

bool isFirstOccurence(int numbers[], int index);
void countOccurrences(int numbers[]);

int main()
{
    int numbers[SIZE] = { 0, 0, 2, 8, 5, 2, 3, 2 };

    countOccurrences(numbers);
}

void countOccurrences(int numbers[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (isFirstOccurence(numbers, i))
        {
            int occurrences = 1;

            for (int j = i + 1; j < SIZE; j++)
            {
                if (numbers[i] == numbers[j])
                {
                    occurrences++;
                }
            }

            if (occurrences == 1)
            {
                printf("%d occurs once.\n", numbers[i]);
            }
            else
            {
                printf("%d occurs %d times.\n", numbers[i], occurrences);
            }
        }
    }
}

bool isFirstOccurence(int numbers[], int index)
{
    for (int i = 0; i < index; i++)
    {
        if (numbers[i] == numbers[index])
        {
            return false;
        }
    }

    return true;
}
