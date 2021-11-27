_____________________________________________________

+****************************+
|Author: John Bryan Valle    |
|Jahrgang: IC21              |
|Project: matrix_arr         |
+****************************+

This Project aimes to demonstrate the averaging algorithm for 2 dimensional
matrices
- the project is implemented in a basic file system:
/matrix_arr:
|
+-----> /matrix_arr/src: *.c, .exe/.elf, Makefile (Important for Build!)
|               |
|               +----> /matrix_arr/src/obj: *.o
|
|-----> README.txt
|
|
+-----> /matrix_arr/include: *.h

Features:
1. Generates averaged 2-dimension-array
2. The Sorting Algorithm is demonstrated in an increasing and decreasing order

+*****Building Process & Execution:***********************+
|                                                         |
| 1. Build Project from matrix_arr/src/ directory:        |
| ~ this building process also runs program automatically |
| :$ make                                                 |
|                                                         |
| 2. Execute main program manually:                       |
| :$ ./main < input.txt                                   |
|                                                         |
| 3. Type matrix dimensions Format: (ROWSxCOLUMNS         |
| i.e. :$ 3x4                                             |
|                                                         |
| 4. Type floating point values of matrix                 |
| i.e. :$                                                 |
|   4.5 1.0 2.0 6.0                                       |
|   1.0 1.5 3.0 4.5                                       |
|   0.5 2.0 2.0 10.5                                      |
+*********************************************************+
