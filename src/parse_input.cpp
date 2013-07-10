#include <parse_input.h>
#include <sudoku_constants.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

void print_sudoku (unsigned* sudoku) {
    for (unsigned i = 0; i < SUDOKU_ELEMENTS; i++) {       
       if (i % 9 == 0) {
           if (i % 27 == 0 && i != 0) 
               printf ("\n------ ------- ------\n%d ", sudoku[i]);
           else 
               printf ("\n%d ", sudoku[i]);
       } else if (i % 3 == 0) {
           printf ("| %d ", sudoku[i]);
       } else {
           printf ("%d ", sudoku[i]);
       }
    }
    printf ("\n\n");
}

unsigned* parse_input (char* input) {
    unsigned position = 0;
    unsigned* sudoku = (unsigned*) malloc (SUDOKU_ELEMENTS * sizeof (unsigned));
    memset (sudoku, 0, SUDOKU_ELEMENTS * sizeof (unsigned));

    int read_number;
    char* buffor = strtok (input, ",");
    while (buffor != NULL) {
        read_number = atoi (buffor);
        if (read_number < 0 || read_number > 9) {
            printf ("Wrong number in sudoku! %d\n", read_number);
            free (sudoku);
            exit (2);
        } else {
            sudoku[position] = read_number;
            position++;
        }

        buffor = strtok (NULL, ",");
    }
    
    print_sudoku (sudoku);
    return sudoku;
}
