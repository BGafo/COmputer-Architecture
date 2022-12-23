#include "../graphutils.h" // header for functions to load and free adjacencyList

// A program to find the minimum spanning tree of a weighted undirected graph using Prim's algorithm

int main ( int argc, char* argv[] ) {

    // READ INPUT FILE TO CREATE GRAPH ADJACENCY LIST
    //AdjacencyListNode* adjacencyList;
    AdjacencyListNode* adjacencyList = NULL;
    size_t graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);
    /* ... */

    

    // An array that keeps track of who is the parent node of each graph node we visit
    // In Prim's algorithm, this parents array keeps track of what is the edge that connects a node to the MST.
    graphNode_t* parents = calloc( graphNodeCount, sizeof(graphNode_t) );
    for (size_t i=0; i<graphNodeCount; i++) {
        parents[i] = -1; // -1 indicates that a nodes is not yet visited; i.e., node not yet connected to MST.
    }


    // added array to check if a node has already been processed or not
    graphNode_t* check = calloc( graphNodeCount, sizeof(graphNode_t) );
    for (size_t i=0; i<graphNodeCount; i++) {
        check[i] = 0; // -1 indicates that a nodes is not yet visited; i.e., node not yet connected to MST.
    }


    graphNode_t root = rand()%graphNodeCount;
    parents[root] = root;

    // Prim's algorithm:
    // A greedy algorithm that builds the minimum spanning tree.
    // For a graph with N nodes, the minimum spanning tree will have N-1 edges spanning all nodes.
    // Prim's algorithm starts with all nodes unconnected.
    // At each iteration of Prim's algorithm, the minimum weight node that connects 
    // an unconnected node to the connected set of nodes is added to the MST.
    for (unsigned iter=0; iter<graphNodeCount-1; iter++) {

        double minWeight = DBL_MAX; // If we find an edge with weight less than this minWeight, 
        // and edge connects a new node to MST, then mark this as the minimum weight to beat.
        graphNode_t minSource = -1;
        graphNode_t minDest = -1;
        unsigned int count = 0;
        for (graphNode_t source=0; source<graphNodeCount; source++) {
            if (parents[source]!=-1) { // if already visited
             /* ... */
                continue;
            }
                else {
                AdjacencyListNode* dest = adjacencyList[source].next;
                // list iterator
                while (dest) {
                    //AdjacencyListNode* temp = dest;
                    if(dest->weight < minWeight){
                        minWeight = dest->weight;
                        minSource = adjacencyList[source].graphNode;
                        minDest =  dest->graphNode;
                    }
                    dest = dest->next; // iterator moves to next
                    if(count == 0){
                    parents[minDest]=minSource; // we found the minimum weight
                    count++;
                    } else if(count > 0 && check[minDest] == 0){
                        parents[minDest]=minSource;
                    }
                    //free(temp);
                }
                check[minDest] = 1;
                minWeight = DBL_MAX;
            }
        }
       
    }

    // Using the fully populated parents array, print the edges in the MST.
    /* ... */
    for(unsigned int i = 0; i < graphNodeCount; i++){
        if(parents[i] != -1){
        printf("%ld %d\n", parents[i], i);
        }
    }

    free (parents);
    freeAdjList ( graphNodeCount, adjacencyList );

    return EXIT_SUCCESS;
}
