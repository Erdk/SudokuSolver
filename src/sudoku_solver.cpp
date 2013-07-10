#include <parse_input.h>
#include <problem.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main (int argc, const char* argv[]) {

    if (argc != 2) {
        printf ("\nWrong input! %s\n\n", argv[1]);
        printf ("\nUsage: %s <comma separated list of sudoku numbers>\n\n", argv[0]);
        exit (1);
    }

    char* input = (char*) malloc (strlen (argv[1]) * sizeof (char));
    strcpy (input, argv[1]);

    unsigned* sudoku = parse_input (input);
    free (input);

    unsigned weight_sum = cost_function (sudoku);

    printf ("Sudoku fit: %d\n", weight_sum);

    free (sudoku);
    return 0;
}
