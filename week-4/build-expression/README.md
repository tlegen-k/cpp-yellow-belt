## Build expression

### Part 1

Implement the construction of an arithmetic expression according to the following scheme:

- initially there is an expression consisting of some integer x;
- at each step, a certain operation is applied to the current expression: adding a number, subtracting a number, multiplying by a number or dividing by a number; the expression must always be enclosed in parentheses before applying the operation.

### Input format

The first line contains the original integer x. The second line contains a non-negative integer N — the number of operations. Each of the next N lines contains the next operation:

- adding the number a: + a;
- or subtracting the number b: - b;
- or multiplication by the number c: * c;
- or division by d: / d.

The number of operations can be zero - in this case, you must display the original number.
### Output format

Print the only line - the constructed arithmetic expression.

Pay attention to the placement of spaces around the characters:

- each binary operation character (+, -, * or /) must be surrounded by exactly one space on each side: (8) * 3;
- the unary minus symbol (for negative numbers) does not need an extra space: -5;
- parentheses and numbers do not need extra spaces.

### Hint

To convert a number to a string, use the to_string function from the <string> library.

## Part 2. No extra brackets

Modify the solution of the previous part so that the previous expression is surrounded by parentheses only if necessary, that is, only if the next operation has higher priority than the previous one.
