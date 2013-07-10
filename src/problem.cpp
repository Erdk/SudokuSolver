#include <problem.h>
#include <sudoku_constants.h>

#include <cstdio>

unsigned E_columns (unsigned* sudoku) {
    return 0;
}

unsigned E_rows (unsigned* sudoku) {
    return 0;
}

unsigned E_blocks (unsigned* sudoku) {
    return 0;
}

unsigned cost_function (unsigned* sudoku) {
    return E_columns (sudoku) + E_rows (sudoku) + E_blocks (sudoku);
}
