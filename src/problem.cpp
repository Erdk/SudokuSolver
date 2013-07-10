#include <problem.h>
#include <sudoku_constants.h>

#include <cstdio>
#include <cstring>

/*
 * Checks if numbers in each row are uniqe and non-0
 * return error count
 */
unsigned E_rows (unsigned* sudoku) {
    
    unsigned ret = 0;
    unsigned sum = 0;
    unsigned repetitions[10];
    memset (repetitions, 0, 10 * sizeof (unsigned));
    
    for (unsigned i = 0; i < SUDOKU_ELEMENTS; i += SUDOKU_COLUMNS) {
        for (unsigned j = i; j < (i / 9 + 1) * SUDOKU_COLUMNS; j++) {
            sum += sudoku[j];
            repetitions[sudoku[j]]++;
        }

        if (sum != 45)
            ret++;
        else {
            unsigned repetitions_sum = 0;
            if (repetitions[0] != 0)
                repetitions_sum++;
            else 
                for (unsigned j = 1; j < 10; j++)
                    if (repetitions[j] != 1)
                        repetitions_sum++;
           
            if (repetitions_sum != 0)
                ret++;
        }        
        sum = 0;
        memset (repetitions, 0, 10 * sizeof (unsigned));
    }
    
    printf ("END E_rows: %d\n", ret);
    return ret;
}

/*
 * Checks if numbers in each column are uniqe and non-0
 *
 * return error count
 */
unsigned E_columns (unsigned* sudoku) {

    unsigned ret = 0;
    unsigned sum = 0;
    unsigned repetitions[10];
    memset (repetitions, 0, 10 * sizeof (unsigned));

    for (unsigned i = 0; i < SUDOKU_COLUMNS; i++) {
        for (unsigned j = i; j <= SUDOKU_ELEMENTS + i - SUDOKU_COLUMNS; j += SUDOKU_ROWS) {
            sum += sudoku[j];
            repetitions[sudoku[j]]++;
        }

        if (sum != 45)
            ret++;
        else {
            unsigned repetitions_sum = 0;
            if (repetitions[0] > 0)
                repetitions_sum++;
            else
                for (unsigned j = 1; j < 10; j++)
                    if (repetitions[j] != 1)
                        repetitions_sum++;

            if (repetitions_sum != 0)
                ret++;
        }        
        sum = 0;
        memset (repetitions, 0, 10 * sizeof (unsigned));
    }

    printf ("END E_columns: %d\n", ret);
    return ret;
}

/*
 * Checks if numbers in each block are uniqe and non-0
 * return error count
 */
unsigned E_blocks (unsigned* sudoku) {
    
    unsigned ret = 0;
    unsigned sum = 0;
    unsigned repetitions[10];
    memset (repetitions, 0, 10 * sizeof (unsigned));

    // 0:  0  1  2  
    //     9 10 11 
    //    18 19 20
    //
    // 1:  3  4  5 
    //    12 13 14 
    //    21 22 23
    //
    // 2:  6  7  8 
    //    15 16 17 
    //    24 25 26
    //////////////
    // 3: 27 28 29 
    //    36 37 38 
    //    45 46 47
    //
    // 4: 30 31 32 
    //    39 40 41 
    //    48 49 50
    //
    // 5: 33 34 35 
    //    42 43 44 
    //    51 52 53
    //////////////
    // 6: 54 55 56 
    //    63 64 65 
    //    72 73 74
    //
    // 7: 57 58 59
    //    66 67 68
    //    75 76 77
    //
    // 8: 60 61 62
    //    69 70 71
    //    78 79 80
    //
    for (unsigned i = 0; i < SUDOKU_BLOCKS; i++) {
        unsigned new_j = ((i + 1) % 3) * SUDOKU_BLOCK_LENGTH + (i / 3 * 27);
        for (unsigned j = new_j; j < (new_j + SUDOKU_BLOCK_LENGTH * (SUDOKU_ROWS - 2)); j += SUDOKU_ROWS)
            for (unsigned k = j; k < j + SUDOKU_BLOCK_LENGTH; k++) {
                sum += sudoku[k];           
                repetitions[sudoku[k]]++;
            }

        if (sum != 45)
            ret++;
        else {
            unsigned repetitions_sum = 0;
            if (repetitions[0] > 0)
                repetitions_sum++;
            else
                for (unsigned j = 1; j < 10; j++)
                    if (repetitions[j] != 1)
                        repetitions_sum++;

            if (repetitions_sum != 0)
                ret++;
        }        
        sum = 0;
        memset (repetitions, 0, 10 * sizeof (unsigned));
    }

    printf ("END E_blocks: %d\n", ret);
    return ret;
}

/*
 * Cost function for algorithm, tells how bad are current solution
 * return sum of error counts
 */
unsigned cost_function (unsigned* sudoku) {
    return E_rows (sudoku) + E_columns (sudoku) + E_blocks (sudoku);
}
