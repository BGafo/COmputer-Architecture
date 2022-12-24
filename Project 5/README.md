1. comparator.v: A digital circuit that compares two 4-bit numbers for equality (easy) (25 points)
Your task in this assignment part is to create a digital circuit consisting of basic gates that compares if two 4-bit numbers are equal.

The .v circuit file format
In the 2022_0s_211/pa6/comparator/ folder you will see comparator_provided.v which currently implements a 2-bit comparator. The circuit file is written in a format as follows:

The first set of lines are input lines. If inputs have multiple bits, the range of bit indices are listed in square brackets. For example, the line "input [1:0] a;" indicates a 2-bit input variable named a, consisting of two bits named a[1] and a[0].
The second set of lines are output lines. If outputs have multiple bits, the range of bit indices are listed in square brackets. If it is a single-bit output, then the brackets are omitted. For example, the line "output equal;" indicates a single bit output variable named equal.
The third set of lines are wire lines. These are intermediate bit values that are neither inputs nor outputs. The square bracket notation does not apply to wire lines. If you need multiple wires, you will have to name them on multiple lines.
The fourth and final set of lines are assign lines. These lines use single or double input basic digital gates to assign values to wires or outputs. There are three types of assign lines:
Identity lines simply assign values from inputs or wires to outputs or other wires without modifying the Boolean value. For example, the line "assign equal = a[0];" copies the Boolean value from the 0th bit of a to equal.
Negation lines assign the negated Boolean value from inputs or wires to outputs or other wires. For example, the line "assign equal = ~ a[1];" copies the negated Boolean value from the 1st bit of a to equal.
In addition to the single input-digital gates in the previous two types of assign lines, there are also assign lines that specify two-input digital gates. The line "assign equal = bit_1_equal & bit_0_equal;" is one such example. The valid gates are:
"&" AND
"~&" NAND
"|" OR
"~|" NOR
"^" XOR
"~^" XNOR
Calling the circuitSimulator executable
In the 2022_0s_211/pa6/ director you will find a binary executable called circuitSimulator. The arguments to circuitSimulator should be as follows:

Usage: ./circuitSimulator <circuit_file> <input_value_1> <input_value_2> ...

The <circuit_file> should be the path to a properly formatted .v circuit file.
Following the path to the circuit file, there should be a sequence of integers, the number of those integers should be equal to the number of input lines specified in the circuit file. These will be the input Boolean values to the circuit.
For example, calling:

 ../circuitSimulator comparator_provided.v 1 3
Read 2 input lines.
Read 1 output lines.
equal = 0

Will simulate the 2-bit comparator in comparator_provided.v with the values 1 and 3 as the input variables a and b. The simulator will report that the single output variable named equal takes the value of 0, indicating that a and b and not equal.

Your task

Your task is to create a 4-bit comparator in a file called comparator.v that compares if two 4-bit numbers are equal. If and only if the numbers are equal should the single bit output variable "equal" have the value 1. You can invoke the autograder script via ./autograder which will test your digital circuit against a randomized set of inputs.

Test cases and expected answers

The inputs for each test case are recorded in the tests/ directory. Corresponding expected answers are recorded in the answers/ directory.

How to compile, run, and test your code
Instructions from Programming Assignment 1, 2, 3, and 5 carry over.
The autograder.py scripts for this assignment only work with Python version 3 on the ilab machines. This means that the correct way to invoke the autograder script is through either of these two commands:
./autograder.py
or
python3 autograder.py
2. sevenSegmentDisplayE.v: A digital circuit that drives a segment of a seven-segment decimal display (easy) (25 points)
Your task

Your task in this assignment part is to create a digital circuit that decides whether the left-bottom segment of a seven-segment decimal display should light up. See this diagram for reference:

https://en.wikipedia.org/wiki/Seven-segment_display#/media/File:7_Segment_Display_with_Labeled_Segments.svgLinks to an external site.

The segment in question is labeled 'E', and it should light up for the digits 0, 2, 6, and 8.

Input format

The inputs of the circuit consist of a single four-bit number called "numeral_bit" that has 10 possible decimal values ranging from 0 to 9. For example, if the input to the circuit is the decimal value 8, then the bit values of numeral_bit will be:

numeral_bit[3] = 1

numeral_bit[2] = 0

numeral_bit[1] = 0

numeral_bit[0] = 0

Output format

The output of the circuit is a single bit called 'e' that is 1 if and only if numeral_bit is 0, 2, 6, or 8.

Test cases and expected answers

The inputs for each test case are recorded in the tests/ directory. Corresponding expected answers are recorded in the answers/ directory.

Hints

Since the number of cases for which 'e' is 1 are relatively few (just four cases), it is suggested you implement this circuit as a sum-of-products, sum-of-minterms, also known as OR-of-ANDs approach.

3. sevenSegmentDisplayC.v: A digital circuit that drives a segment of a seven-segment decimal display (medium) (25 points)
Your task

Your task in this assignment part is to create a digital circuit that decides whether the right-bottom segment of a seven-segment decimal display should light up. See this diagram for reference:

https://en.wikipedia.org/wiki/Seven-segment_display#/media/File:7_Segment_Display_with_Labeled_Segments.svgLinks to an external site.

The segment in question is labeled 'C', and it should light up for the digits 0, 1, 3, 4, 5, 6, 7, 8, and 9. In other words 'C' lights up for all digits except 2.

Input format

The inputs of the circuit consist of a single four-bit number called "numeral_bit" that has 10 possible decimal values ranging from 0 to 9. For example, if the input to the circuit is the decimal value 2, then the bit values of numeral_bit will be:

numeral_bit[3] = 0

numeral_bit[2] = 0

numeral_bit[1] = 1

numeral_bit[0] = 0

Output format

The output of the circuit is a single bit called 'c' that is 0 if and only if numeral_bit is 2.

Test cases and expected answers

The inputs for each test case are recorded in the tests/ directory. Corresponding expected answers are recorded in the answers/ directory.

Hints

Since the number of cases for which 'c' is 0 are relatively few (just one case), it is suggested you implement this circuit as a product-of-sums, product-of-maxterms, also known as AND-of-ORs approach.

EC. sevenSegmentDisplay.v: A digital circuit that drives all segments of a seven-segment decimal display (hard) (extra credit 25 points)
Your task

Your task in this assignment part is to create a digital circuit that decides whether the segments of a seven-segment decimal display should light up. See this diagram for reference:

https://en.wikipedia.org/wiki/Seven-segment_display#/media/File:7_Segment_Display_with_Labeled_Segments.svg Links to an external site.(Ignore the decimal point labeled 'DP')

Test cases and expected answers

The inputs for each test case are recorded in the tests/ directory. Corresponding expected answers are recorded in the answers/ directory.

Hints

You can go about this challenging extra credit task in two different ways. In approach one, you can follow a combination of techniques introduced in the previous two parts to complete this task. In approach two, you can read how to systematically factor and simplify digital logic using Karnaugh maps, which would lead to an implementation consisting of fewer lines of code.

4. fullyAssociative.v: A digital circuit that implements the read-hit logic of a fully associative cache (medium) (25 points)
Your task

Your task in this assignment part is to create a digital circuit that decides whether a read address given to a cache is a read-hit, and if it is, provides the single-byte data block as output. The cache in question is a E=2 way fully-associative cache, with m=2 bit addresses, t=2 bit tags, s=0 bit set indices as it is a fully associative cache, b=0 bit block offsets such that data blocks are just one byte providing no support for data locality. The total capacity of the cache is just S*E*B = 1*2*1 = 2 bytes.

Input format

The interface to the cache logic is given in fullyAssociative_provided.v. The address to be read from is given to the cache in read_address. The state of the cache (stored in SRAM sequential logic) is recorded in inputs called line_0_valid, line_0_tag, line_0_block, and line_1_valid, line_1_tag, line_1_block.

Output format

The circuit has two outputs. The output "read_hit" is true if and only if the address to be read matches the tag in either line, and that said line is valid. The output "read_byte" contains the 8-bit block data of the line if the address is a read-hit, otherwise its value is ignored.

Test cases and expected answers

The inputs for each test case are recorded in the tests/ directory. Corresponding expected answers are recorded in the answers/ directory.

Hints

The 2-bit comparator from part 1 should be useful. The logic for this part can be completed in under 100 lines of code.

5. setAssociative.v: A digital circuit that implements the read-hit logic of a set associative cache (hard) (25 points)
Your task

Your task in this assignment part is to create a digital circuit that decides whether a read address given to a cache is a read-hit, and if it is, provides the single-byte data block as output. The cache in question is a E=2 way set-associative cache, with m=2 bit addresses, t=1 bit tags, s=1 bit set indices for S=2 sets, b=0 bit block offsets such that data blocks are just one byte providing no support for data locality. The total capacity of the cache is S*E*B = 2*2*1 = 4 bytes.

Input format

The interface to the cache logic is given in setAssociative_provided.v. The address to be read from is given to the cache in read_address. The state of the cache (stored in SRAM sequential logic) is recorded in the rest of the inputs.

Output format

The circuit has two outputs. The output "read_hit" is true if and only if the address to be read matches the tag in either line of the correct set, and that said line is valid. The output "read_byte" contains the 8-bit block data of the line if the address is a read-hit, otherwise its value is ignored.

Test cases and expected answers

The inputs for each test case are recorded in the tests/ directory. Corresponding expected answers are recorded in the answers/ directory.

Hints

The 2-bit comparator from part 1 should be useful. The demonstration code for the digital logic for a directMapped cache in the directMapped/ directory should also be useful. The logic for this part can be completed in under 250 lines of code.

6. binSub.v: A digital circuit that subtracts two 8-bit 2's complement numbers (hard) (25 points)
Your task

Your task in this assignment part is to create a digital circuit that calculates difference = minuend - subtrahend for three numbers minuend, subtrahend, and difference all encoded as 8-bit 2's complement numbers.

Input and output format

The interface to the binary subtraction logic is given in binSub_provided.v. 

Test cases and expected answers

The inputs for each test case are recorded in the tests/ directory. Corresponding expected answers are recorded in the answers/ directory.

Hints

The demonstration code for a 8-bit negator that finds the negated value of a 8-bit 2's complement number in the negator/ directory should be useful. You may also want to read about half-adders and full-adders for additional hints for this part. The logic for this part can be completed in under 150 lines of code.

