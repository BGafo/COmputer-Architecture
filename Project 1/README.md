1. greedyScheduling: Using a greedy algorithm to optimally schedule as many jobs as possible
Greedy algorithms are a common and simple class of algorithms that always takes the most "optimal" decision in order to solve a problem. One example problem is in scheduling jobs such that as many jobs are scheduled in a given time period. Suppose you have a collection of jobs, and each job has a beginning time and an ending time. Two jobs that overlap in duration cannot be scheduled together. To schedule as many jobs as possible, a workable algorithm is to always pick a non-overlapping job that ends the earliest as the next job. Here, the algorithm is making a "greedy" choice (next job should be the one that ends the earliest), and the overall algorithm will arrive at an optimal sequence where as many jobs are scheduled as possible.

Input format
In the greedyScheduling/tests/ directory you have four given input test cases. In each test case file the format is as follows:

The first line is the number of jobs that needs to be scheduled. For example, "5" would mean there are five jobs {A,B,C,D,E} to be scheduled.
The second line is the maximum integer number of time periods available for scheduling. For example, "20" would mean that no jobs have an ending time greater than 20.
All subsequent lines contain a letter and two integer numbers. The letter is the name of the job ('A'). The first number is the beginning time of the job. The second number is the ending time of the job.
An example input file would look like:

5
5
A 1 2
B 2 3
C 3 5
D 4 5
E 3 5
Your program
You should write a C program that takes as a command line input the path to the test case file:

./greedyScheduling tests/test0.txt
Then, you should use a greedy algorithm to schedule as many jobs as possible without causing overlapping jobs:

If a job starts at time 0, it is invalid and should not be scheduled.
Jobs X and Y are considered overlapping if job X's beginning time is less than or equal to job Y's ending time (In the example above, jobs A and B overlap).
If multiple valid jobs have the same ending time, the one with the earliest non-overlapping beginning time is optimal (In the example above, after scheduling job A, jobs C, D, and E are all valid as they start after time 2. Jobs C and E are considered more optimal as they start earlier than job D).
If multiple optimal jobs have the same beginning time and ending times, the one that comes later in the input file should take precedent (In the example above, jobs C and E have the same beginning time and ending time; in these cases you should break the tie by selecting the last one in the file, job E). 
Expected output format
In the answers/ directory you have the corresponding expected answers. You should print to the command line the letter names of the jobs you schedule in sequence, each letter separated by a newline. For example, the expected output for the test case above is:

A
E
