Problem
=======

- Fixed set {1, 2, 3, 4, 5, 6, 7, 8, 9}
- In all columns numbers must be different
- In all rows numbers must be different
- in each (fixed) 3x3 block numbers must be different

Optimization function:
X - 9x9 matrix
C(X) = Erows + Ecolumns + Eblocks
Ecolumns - for each column compute: |45 - $colsum|, return sum
Erows - for each row compute: |45 - $rowsum|, return sum
Eblocks - for each block compute: |45 - $blocksum|, return sum

