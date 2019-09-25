# Rabin-Miller
Implementation of Rabin-Miller algorithm in C.
The program takes 2 parameter (n, t)
1. n, the integer to be tested
2. t, number of test trials

and output the
- "Composite", if n is not a prime 
- "Inconclusive", if n is most likely a prime

# Installation
Simply execute **make** inside the source folder will build the binary. The binary is named **rabinMiller** by default.

# Usage
Feed both *n* and *t* as command line parameters to the program,
```
#./rabinMiller 43 10
Inconclusive
#./rabinMiller 27 10
Composite
```
