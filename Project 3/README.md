1. toHex: Converting signed integers to binary and hexadecimal representation 
Computers represent numbers using a base-2 binary number system to represent integers. And in order to represent both positive and negative numbers, they use a two's complement number system that overflows (wraps around) nicely and has simple rules for carrying out addition and subtraction. Because binary numbers are unwieldy for human beings to read and write, we use hexadecimal notation to make the representation more compact.

In this part of the assignment, you will take positive and negative integers that can be represented using signed short (16-bit) integer data types and print out their hexadecimal representation.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case there is a single integer, written in base-10, that is within the range of the signed short int data type (-32,768 to +32,767).

Output format
Expected outputs from your program for each test case are in the answers/ directory. You should print a four-character hexadecimal number corresponding to the binary representation of the input number. In your hexadecimal representation, the digits that would be represented using letters (A-F) should be printed in uppercase.

For example, the base-10 number -4319 has a binary two's complement representation of 1110_1111_0010_0001, which you should print out in hexadecimal notation as EF21.

How to compile, run, and test your code
Instructions from Programming Assignment 1 and 2 carry over.

This means that the correct way to invoke the autograder script is through either of these two commands:

./autograder.py
or

python3 autograder.py
2. binSub: Finding the difference of two signed integers via operations on binary numbers 
In computer processors all arithmetic operations are carried out as basic logical operations on binary numbers. In this part of the assignment you will perform subtraction on signed char (8-bit) integers, where positive and negative numbers are encoded in the two's complement number system. Recall that for subtraction operations:

minuend - subtrahend = difference
To perform subtraction, you will negate the binary representation of the subtrahend, and then add that negated number to the minuend to find the difference. You may also want to review how to add two binary numbers using a carry bit. Your output should also be a signed char (8-bit) integer, so any overflow should wrap around and stay within the limits of the signed char data type.

It is good practice (and certainly more interesting) for you to perform this calculation on the binary numbers directly in this assignment. That is to say, you should not convert the binary numbers into integer data types and perform subtraction using the '-' operator.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records the signed 8-bit two's complement minuend (the number to be subtract from). The second line records the signed 8-bit two's complement subtrahend (the number to subtract).

Output format
You should print the difference of the two inputs as a sequence of eight binary digits, overflowing if needed to stay within the limits of the signed char data type. Expected outputs from your program for each test case are in the answers/ directory.

3. rootFinder: Binary search along the real number line to find the n-th root of a number 
Many mathematical functions outside of the fundamental ones (add, subtract, multiply, divide, exp, square root) are implemented as numerical algorithms. In this part of the assignment, you will gain experience in using floating point numbers and try a hand at writing your first numerical algorithm. The task is to find the n-th root of a number:


Where you are given n and x, and your task is to find r. In this assignment, n will be a positive integer, and x will be a positive floating point value.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records x. The second line records n. The third line records the level of precision (difference between the true value and your solution) to which you should find the answer for r. 

Output format
You should print a single number which is your estimate of r. Expected outputs from your program for each test case are in the answers/ directory: in each file, the first line records the expected value of r. The second line records the level of precision desired to help the autograder check your answer.

4. binToFloat: Finding the value of a floating point number binary representation 
In this part of the assignment, you will decode the 32-bit binary representation of an IEEE 754 single-precision float point number. You may wish to review how floating point numbers are encoded using the class lecture slides, the textbook, and supplementary reading material, among other resources. You should decode the sign, exponent, and mantissa portions of the floating point number to reconstruct the number's value. You may not use memory operations and pointer referencing and dereferencing to cast the bitstring into a float. This restriction has also been noted in the binToFloat_provided.c code.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. Each test case consists of a string of 32 1's and 0's giving the binary representation of a floating point number. The sign bit is given in the leftmost position in the string.

Output format
You should print the value of the floating point number. You can use the "%f" (for floats) and "%e" (for floats in scientific notation) printf format specifiers for printing. The autograder will be able to recognize both formats. Expected outputs from your program for each test case are in the answers/ directory.

5. doubleToBin: Find the binary representation of a double-precision floating point number 
In this fifth part of the assignment, you will encode a given real number as a IEEE 754 double-precision floating point number, and print out its 64-bit binary bitstream. This type of engineering task would be important and typical in developing testbenches that help validate whether computer hardware designs for field-programmable gate arrays (FPGAs) and application-specific integrated circuits (ASICs) are functioning correctly.

You may want to use trial division to find the exponent value such that mantissa of the floating point number is in its normalized range of:

1.0 <= mantissa < 2.0
If you are able to find the correct exponent and print the correct numbers for the exp field, you will receive partial credit for passing a portion of the given test cases. To complete this part of the assignment, you need to also properly encode the mantissa in the frac field of the floating point number. For maximum points, you will also have to pass test cases for encoding denormalized numbers, and special cases in the floating point format such as +0.0 and -0.0. You may not use memory operations and pointer referencing and dereferencing to cast the float into a bitstream. This restriction has also been noted in the doubleToBin_provided.c code. The provided code also has suggested assertion statements that help you validate that your encoding adheres to the IEEE 754 specification.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. Each test case consists of a positive or negative real number that can be encoded as an IEEE 754 double-precision floating point number. 

Output format
You should print the 64-bit binary representation of the double-precision floating point number that encodes the given floating point number. Expected outputs from your program for each test case are in the answers/ directory. You may add '_' underscore characters to your printout to aid yourself in reading the bitstream. The autograder will automatically ignore these characters.

6. floatMul: Finding the product of two single-precision floating numbers via operations in binary 
In this sixth and final part of the assignment, you will bring together ideas you have used throughout this assignment to implement floating point multiplication. Floating point multiplication is a foundational arithmetic operation that underpins science simulations, machine learning, and nearly every computer science discipline. The ability to perform floating point multiplication in hardware is measured in floating point operations per second, or FLOPS. The world leading supercomputers are pushing 500 petaFLOPS (10^15 FLOPS), while even in consumer hardware one can purchase computers capable of 10 teraFLOPS (10^12 FLOPS).

It is good practice (and certainly more interesting) for you to perform this calculation on the binary numbers directly in this assignment. You may want to review the class lecture slides, the posted supplementary reading, and the textbook to understand how floating point multiplication works—treating the exp and the frac fields separately. An alternative approach would be to decode the input bitstreams into a floating point representation, then use the '*' multiplication operator in the C language to perform the calculation, and re-encode the floating point number to a bitstream. The only approach that is not permitted is to use memory operations and pointer referencing and dereferencing to cast between floats and bitstreams. This restriction has also been noted in the floatMul_provided.c code.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records a multiplier as a 32-bit floating point number binary representation. The second line records a multiplicand as a 32-bit floating point number binary representation. The sign bit is given in the leftmost positions in the strings.

Output format
You should print the 32-bit binary representation of a single-precision floating point number that encodes the product of the inputs.. Expected outputs from your program for each test case are in the answers/ directory. You may add '_' underscore characters to your printout to aid yourself in reading the bitstream. The autograder will automatically ignore these characters.

