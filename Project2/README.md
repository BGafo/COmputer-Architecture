1. balanced: checking if braces are balanced or not using a stack
You may have noticed that your favorite text editor or integrated development environment (IDE) can help you check if open parentheses, brackets, and braces are properly closed. That is, whether each open '<', '(', '[', and '{' is properly closed with a corresponding '>', ')', ']', and '}' without any intervening open parentheses, brackets, or braces.

For example, these are balanced expressions:

<({})>

({<>(){}})

But these are not:

({)

<<>[<()>]

Your task in this part of the assignment is to write a C program using structs and pointers to build a stack data structure, and use that stack to check whether a string is properly balanced. Your program should take as a command line input the path to an input file:

./balanced tests/test0.txt
Your program should check whether the expression in the input file is balanced, and then print to the command line "yes" if the expression is balanced, and "no" if it is not.

2. bstLevelOrder: breadth-first level order traversal of a binary search tree using a queue 
Your task in this part of the assignment is to write a C program that constructs a binary search tree from a list of input numbers, and then print out the binary search tree in a level order, left-to-right, traversal of the tree. You may find it helpful to review the properties of a binary search tree, and the various flavors of tree traversal order. In a binary search tree, the key in each node is greater than all keys in its left subtree, and is lesser than all keys in its right subtree.

Your program should take as a command line input the path to an input file:

./bstLevelOrder tests/test0.txt
Each line of the input file lists a number to be inserted into the binary search tree. If a number has already been inserted, you can ignore the duplicate insertion. Since we are not performing tree balancing, everyone should arrive at the same binary search tree structure for any given input sequence. For example, an input sequence of 8,3,6,1,10,4,14,7,13 would lead to this unique binary search tree (image credit wikimedia):

Binary_search_tree.svg

Once the binary search tree is constructed, your program should print out the nodes in a level-order, left-to-right, traversal of the tree.  Such a traversal of the example tree above would return the numbers in this order: 8, 3, 10, 1, 6, 14, 4, 7, 13

The corresponding expected outputs are in the answers directory: answers/answer0.txt.

3. edgelist: Loading, representing, and printing an undirected unweighted graph 
Graphs are fundamental data structures. A graph consists of nodes and edges connecting pairs of nodes. A basic kind of graph is an undirected, unweighted graph, meaning that the edges are not directional, and each edge doesn't have any additional properties. Here is an example of an undirected, unweighted graph G=(V,E), V={0,1,2,3}, E={(0,1),(0,2),(0,3),(1,3)} of four nodes and four edges:

An undirected, unweighted graph of four nodes and four edges.

There are several important ways to represent graphs.

The first graph representation is an adjacency matrix Links to an external site.. The adjacency matrix of the above graph is:

0 1 1 1 
1 0 0 1 
1 0 0 0 
1 1 0 0
The 0, 1, 1, 1 in the first row of the matrix indicates the 0th node is connected to the 1st, 2nd, and 3rd nodes, and so on.

The second graph representation is an adjacency list Links to an external site.. For a graph consisting of N nodes, the adjacency list data structure is an array of N separate linked lists for each node p, where each link in the linked list records a node q if the edge (p,q) exists. For example, the adjacency list representation of the above graph is:

0->1->2->3->/
1->0->3->/
2->0->/
3->0->1->/
The ->/ indicates a null pointer terminating the linked list.

The third graph representation is by listing the edges of the graph. For example, the edge list of the above graph is:

0 2
0 3
0 1
1 3
In this part of the assignment, you will write a program that:

Loads an adjacency matrix representation of an undirected unweighted graph,
Holds that graph representation as a adjacency list data structure,
Prints out the edge list representation of the graph.
An important C header file, graphutils.h, is provided to you in 2022_0s_211/pa2/graphutils.h. This file offers ready-to-use functions for loading a adjacency matrix, creating an adjacency list data structure, and freeing the adjacency list. You should call these functions to simplify your code.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records the number of nodes N in the graph. Then, the adjacency matrix is recorded in the subsequent N rows of the file.

Output format
Expected outputs from your program for each test case are in the answers/ directory. You should print one line for each edge of the graph; each line should list the pair of nodes (separated by a space) constituting a graph edge.

This is an undirected graph, so the order of the nodes does not matter. The autograder will recognize re-ordering of the nodes as correct. The ordering of which edges are printed first also does not matter. The autograder will recognize re-ordering of the edges as correct.

4. isTree: Determining whether an undirected graph is a tree using depth-first search 
An undirected graph is a tree if and only if the graph contains no cycles. For example, this is a tree because it contains no cycles:

An undirected graph that is a tree.

While this graph contains cycles and therefore is not a tree:

An undirected graph that is not a tree.

In this part of the assignment, you will write a depth-first search through a graph to determine whether the graph contains cycle. A cycle is detected when depth-first search find a graph node that was already visited.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records the number of nodes N in the graph. Then, the adjacency matrix is recorded in the subsequent N rows of the file.

Output format
You should print "yes" if the graph is a tree, "no" if the graph is not a tree. Expected outputs from your program for each test case are in the answers/ directory.

5. mst: Finding the minimum spanning tree of a undirected weighted graph 
A weighted graph is a graph that has a numerical weight property on each edge. The minimum spanning tree (MST) of an undirected weighted graph is a tree that connects all nodes in the graph, and at the same time minimizing the sum of the weights of the tree's edges. Many important problems in computer networking and operations research boil down to finding MSTs on graphs. As an example, this is a undirected weighted graph:

An undirected weighted graph.

And this is its MST:

The minimum spanning tree of an undirected weighted graph.

The edges (0,1) and (1,2) connects all nodes in the graph, and picking these edges minimizes the total weight of the tree. If all the weights in an undirected weighted graph are unique, then the MST is also unique, meaning everyone will find the same MST for a given graph.

In this part of the assignment, you will write a program implementing another example of a greedy algorithm to find the MST. Several algorithms solve this problem, but Prim's algorithm Links to an external site.is likely the easiest to implement.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records the number of nodes N in the graph. Then, the adjacency matrix is recorded in the subsequent N rows of the file. This time, the adjacency matrix contains floating point numbers. 0.0 indicates no edge between two nodes. Any other value indicates an edge with the given value as the edge weight.

Output format
Expected outputs from your program for each test case are in the answers/ directory. You should print a list of edges that, taken together, form the MST of the input graph. Again, the ordering of the nodes in each edge does not matter. The ordering of the edges does not matter. 

6. findCycle: Finding a cycle in a directed graph using depth-first search 
A directed graph is a graph where edges are directional; that is, edges (p,q) and (q,p) are distinct. An important class of directed graphs are directed acyclic graphs (DAGs), which have broad applications in programming languages and compilers. A DAG is any directed graph with no cycles. For example, this is a directed graph:

A directed graph with cycles.

The above graph is not a DAG because it contains cycles. The cycles are:

1 2 
4 7 
4 5 7 
By extension, these rotated versions are also valid cycles of the above graph:

2 1 
7 4 
5 7 4 
7 4 5 
In this final part of the assignment, you will bring together ideas you have used throughout this assignment to find and print a cycle in a directed graph. If no cycles are found, your program will report that the graph is a DAG. You can use any algorithm for this task; either the DFS or the BFS approaches you have used in this assignment so far can be useful.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records the number of nodes N in the graph. Then, the adjacency matrix is recorded in the subsequent N rows of the file. This time, the adjacency matrix represents a directed graph.

Output format
You should print a single line of nodes (separated by spaces) that forms a cycle in the input directed graph. For example, for the example directed graph above you can print any one of the seven cycles listed above. This time, the ordering of the nodes does matter as this is a directed graph. If no cycles were found, your program should print "DAG". The known cycles for each test case are in the answers/ directory. You can print out rotated versions of the known cycles; the autograder will see that rotated cycles are equivalent.

Hint
Suppose you enter the graph from 0, and find a cycle by following the path

0->7->4->5->7
Upon seeing 7 again, you know you have detected a cycle. You have to carefully determine where the cycle begins and ends in the path you have traversed.
