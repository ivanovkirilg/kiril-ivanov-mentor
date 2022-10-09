/*
Task: Modify this code so that the `names' and `candidates' arrays get sorted.
      Sort the candidates by vote count, and then separately by name.

      Also implement a print_array() function that follows the design principles
      of sort_array(). Think about where this function should be defined.
*/

#include <stddef.h>

#include "Sort.h"

int compare_int(const void *lhs, const void *rhs)
{
    const int *lhs_int = lhs;
    const int *rhs_int = rhs;

    return (*rhs_int) - (*lhs_int);
}

struct Candidate
{
    char name[32];
    unsigned long vote_count;
};

int main()
{
    int numbers[] = {
        18, 21315, 6, 8841, -1235, 0, 6, 2, -300
    };
    size_t number_size = sizeof numbers[0];
    size_t numbers_count = sizeof numbers / number_size;

    const char *names[] = {
        "Pesho", "Gosho", "Marcus", "Angela"
    };
    size_t name_size = sizeof names[0];
    size_t names_count = sizeof names / name_size;

    struct Candidate candidates[] = {
        { "Philip", 20000 },
        { "Andrea", 45020 },
        { "Aabria", 30008 },
        { "Zigette", 1300 },
    };
    size_t candidate_size = sizeof candidates[0];
    size_t candidates_count = sizeof candidates / candidate_size;

    sort_array(numbers, number_size, numbers_count, compare_int);
    // print_array
    sort_array(names, name_size, names_count, NULL);
    // print_array

    // Sort by vote count
    sort_array(candidates, candidate_size, candidates_count, NULL);
    // print_array
    // Sort by name (alphabetically)
    sort_array(candidates, candidate_size, candidates_count, NULL);
    // print_array
}
