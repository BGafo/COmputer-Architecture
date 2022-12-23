#include <stdlib.h>
#include <stdio.h>

//#include "../graphutils.h" 

// A program to perform a LEVEL ORDER (BREADTH-FIRST) TRAVERSAL of a binary search tree

// BINARY SEARCH TREE

typedef struct BSTNode BSTNode;
struct BSTNode {
    int key;
    struct BSTNode* l_child; // nodes with smaller key will be in left subtree
    struct BSTNode* r_child; // nodes with larger key will be in right subtree
    struct BSTNode* next; 
    struct BSTNode* data;
};

// BFS requires using a queue data structure
typedef struct QueueNode {
    struct BSTNode* data;
    struct BSTNode* next;
} QueueNode;

struct Queue {
    struct BSTNode* front; // front (head) of the queue
    struct BSTNode* back; // back (tail) of the queue
};
typedef struct Queue Queue;

// Add new data to the BST using recursion
struct BSTNode* insert ( struct BSTNode* root, int key ) {

    // Base case: If the BSTNode here doesn't yet exist
    if (root==NULL) {
        root = malloc(sizeof(BSTNode));
        root->l_child = NULL;
        root->r_child = NULL;
        root->key = key;
    }

    // If the BSTNode already exists, then insert key in correct subtree
    if ( key<root->key ) {
        root->l_child = insert( root->l_child, key );
    } else if ( key==root->key ) {
        // duplicates are ignored
    } else { // key>root->key
        root->r_child = insert( root->r_child, key );
    }
    return root;
}

void depth_first ( struct BSTNode* root ) {
    if(root!=NULL) // checking if the root is not null
    {
        depth_first(root->r_child);// visiting right child
        printf(" %d ", root->key); // printing data at root
        depth_first(root->l_child); // visiting left child
    }
}

// Delete the BST using recursion
void delete_bst ( BSTNode* root ) {
    if ( root->r_child!=NULL ) {
        delete_bst (root->r_child);
    }
    if ( root->l_child!=NULL ) {
        delete_bst (root->l_child);
    }
    free (root);
}


// LINKED LIST IMPLEMENTATION OF QUEUE

// queue needed for level order traversal
/* ... */
// Append the new node to the back of the queue
void enqueue ( Queue* queue, struct BSTNode* data ) {
    BSTNode* queueNode = malloc(sizeof(BSTNode));
    queueNode -> data = data;
    queueNode -> next = NULL; // At back of the queue, there is no next node.

    if (queue->back==NULL) { // If the Queue is currently empty
        queue->front = queueNode;
        queue->back = queueNode;
    } else {
        queue->back->next = queueNode;
        queue->back = queueNode;
    }

    return;
}

// Remove a QueueNode from the front of the Queue
BSTNode* dequeue ( Queue* queue ) {

    if (queue->front==NULL) { // If the Queue is currently empty
        return '\0';
    } else {

        // The QueueNode at front of the queue to be removed
        BSTNode* temp = queue->front;
        BSTNode* data = temp->data;

        queue->front = temp->next;
        if (queue->back==temp) { // If the Queue will become empty
            queue->back = NULL;
        }

        free(temp);
        return data;
    }
}

int main ( int argc, char* argv[] ) {

    // READ INPUT FILE TO CREATE BINARY SEARCH TREE
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }
    BSTNode* root = NULL;
    int key;
    while ( fscanf(fp, "%d", &key)!=EOF ) {
        root = insert (root, key);
    }
    fclose(fp);

    // USE A QUEUE TO PERFORM LEVEL ORDER TRAVERSAL
    Queue queue = { .front=NULL, .back=NULL };
    BSTNode* currBSTNode = root;
    enqueue ( &queue, currBSTNode );

    do {
        BSTNode* current;
        if(queue.front != NULL){
            current = dequeue( &queue);
            printf(" %d\n ", current->key);
        }

        if(current->l_child != NULL){
            enqueue( &queue, current->l_child);  
        }

        if(current->r_child != NULL){
            enqueue( &queue, current->r_child);
        }
        currBSTNode = queue.front;  
    } while ( currBSTNode!=NULL );

    delete_bst(root);
    return EXIT_SUCCESS;
}
