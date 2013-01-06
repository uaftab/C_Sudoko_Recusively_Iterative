Sudoku Solver
Recursion Iterative Brute-Force Algorithm
 
Logic:
1. User Inputs puzzle ; which is loaded in to a matrix.
2. Zero (0) is used to denote the blank spaces in the grid.
3. The algorithm flags cells of unsolved puzzle as fixed (for numbers for 1 to 9 ) and non-fixed (zero).
4. It searches row wise for the first non-fixed cell.
5. Now that we have our cell- co-ordinates it assumes the value to be 1. 
6. Then it checks the corresponding row, column, and sub- 3x3 grid.
7. If above step is true. It proceeds to the next empty cell and assumes it value as 1.
8. If puzzle check fails, it increments the value of cell by one till puzzle is satisfied. 
9. If all values for cell from 1 to 9 have been tried it resets the cell to zero and moves to the previous cell where it increments the value by one. 
10. It recessives till the check function returns true for every value.
11. When the it reaches the last blank cell it 
12. All in all the solver must perform 80 correct loops to get to the last value for solving a puzzle (80 successful loops for a blank puzzle). 


Result:
A Sudoku is Solved very fast.

