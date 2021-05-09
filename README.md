
COEN244.Assignment(3)    Due date: Feb. 29th, 2016

Calculators 
===========

Design, implement and test vector and matrix classes (and a test program), classes that support a variety of mathematical operations. In particular, the basic binary operators should be supported for various vector and matrix 
interactions. You must be able to add, subtract, and multiply vectors and matrices, and scale vectors. You should also 
be able to access elements of a vector or a matrix by their row and column indices. You should be able to initialize and
reset all elements of a vector or a matrix to a specific value.

Your program should check if the conditions for a particular operation (e.g., matrix multiplication) are satisfied before
executing the operation. If the operation is not possible then your program should not carry out the operation and report
back the reason to the user. If the operation is possible then the results should be output-ed in a comprehensible fashion.

You are required to build an inheritance hierarchy involving matrix and vector classes, as well as use operator over-loading
in this assignment. Examples of operations follow. If you do not remember then refer to a Linear Algebra textbook for
exact definitions of the various vector and matrix operations (or simply Google them).


Vector Examples
---------------

Vector vec1(20, 2.0) ;     	// creates a 20-element vector, initializing every one of its elements to 2.0
Vector vec2(20,-4.0) ;     	// creates a 20-element vector, initializing every one of its elements to -4.0

Vector vec3 = vec1 + vec2 ;  	// creates vec3 and set it equal to the summation of vec1 and vec2 
vec3 = vec1 - vec2 ;   	   	// vec3 := the difference between vec1 and vec2 
vec3 = vec1 * vec2 ; 	   	// vec3 := the cross product of vec1 and vec2
vec3 = vec1 ^ vec2 ;         	// vec3 := the dot product of vec1 and vec2
vec3.scale(8);	 		// vector scaling; every element in vec3 is multiplied by 8 

vec3(0) = 9;			// sets to 9 the first element of vec3
vec3.reset(0);			// sets every element of vec3 to 0


Matrix Examples 
---------------

Matrix mat1(20, 20, 2.0) ; 	// creates a 20x20 matrix, initializing all its elements to 2.0
Matrix mat2(20, 20, 4.0) ; 	// creates a 20x20 matrix, initializing all its elements to 4.0

Matrix mat3 = mat1 + mat2 ; 	// creates and sets mat3 equal to the summation of mat1 and mat2
mat3 = mat1 - mat2 ; 		// sets mat3 equal to the difference between mat1 and mat2
mat3 = mat1 * mat2 ;		// sets mat3 equal to the matrix multiplication of mat1 and mat2

mat3(0,0) = 7; 			// sets the (0,0) element of mat3 to 7
mat3.reset(1);			// sets all elements of mat3 to 1

Testing
-------

It is important to test your program to provide strong empirical evidence that (a) the program gives 
correct outputs to valid inputs; (b) the program does not crash easily, as in response to expect-able
incorrect inputs (e.g., additional spaces or letters); (c) the program meets (or exceeds) the specifications, 
as explained here. 


// end.

