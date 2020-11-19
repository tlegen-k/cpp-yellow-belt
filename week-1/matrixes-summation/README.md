## Matrixes summation

If you are not sure whether you should first take our first course, or if you have enough knowledge to start with the Yellow Belt, try to solve this problem. If you do not understand its condition or cannot quickly decide, most likely, you must first go through the "White Belt"
Condition

In this task, you need to develop a Matrix class to represent an integer matrix. In more detail, the Matrix class should have:

+ default constructor that creates a matrix with zero rows and zero columns
+ constructor from two integer parameters: num_rows and num_cols, - which specify the number of rows and columns of the matrix, respectively
+ the Reset method, which takes two integer parameters that specify the new number of rows and columns of the matrix, respectively; the Reset method changes the dimensions of the matrix to the given ones and resets all its elements
+ constant method At, which takes a row number and a column number (in that order; row and column numbering starts from zero) and returns the value in the corresponding matrix cell
+ non-constant At method with the same parameters, but returning a link to the value in the corresponding matrix cell
+ constant methods GetNumRows and GetNumColumns, which return the number of rows and columns of the matrix, respectively

If the number of rows or the number of columns passed to the constructor of the Matrix class or the Reset method is negative, the standard out_of_range exception should be thrown.

The At method should throw the same exception if the cell passed to it goes beyond the boundaries of the matrix.

In addition, the following operators must be defined for the Matrix class:

+ operator input from the stream istream; the input format is simple - first the number of rows and columns is specified (in that order), and then all the elements of the matrix: first the element of the first row and first column, then the element of the first row and second column, and so on
+ output operator to the stream ostream; it should output the matrix in the same format in which the input operator reads it — the number of rows and columns in the first row, the elements of the first row in the second, the elements of the second row in the third, etc.
+ equality check operator (==): it should return true if the matrices being compared are the same size and all their corresponding elements are equal to each other, otherwise it should return false.
+ addition operator: it must take two matrices and return a new matrix, which is their sum; if the transmitted matrices have different sizes, this operator should throw a standard invalid_argument exception.

You are given a draft solution, as well as an example of input and output. When you implement the Matrix class, you can use this example to make sure your code is working correctly.

Important! The example does not verify that all the requirements specified in the condition are met.

Problem Author - Dmitry Minchenko
