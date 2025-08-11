#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

// Node structure for chaining in our HashMap
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Hash table array
Node* table[SIZE];

// Hash function: ensures non-negative index
int hasfunc(int key) {
    if (key < 0) {
        key = -key; // Convert negative keys to positive
    }
    return key % SIZE; // Simple modulo hashing
}

// Insert or update a key-value pair
void inserth(int key, int value) {
    int idx = hasfunc(key);
    Node* cur = table[idx];

    // If key already exists, update it
    while (cur) {
        if (cur->key == key) {
            cur->value = value;
            return;
        }
        cur = cur->next;
    }

    // Otherwise, create a new node and insert at head
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->value = value;
    n->next = table[idx];
    table[idx] = n;
}

// Get value by key (returns -1 if not found)
int geth(int key) {
    int idx = hasfunc(key);
    Node* cur = table[idx];
    while (cur) {
        if (cur->key == key) {
            return cur->value;
        }
        cur = cur->next;
    }
    return -1;
}

// Delete a key-value pair if it exists
void delh(int key) {
    int idx = hasfunc(key);
    Node* cur = table[idx];
    Node* prev = NULL;

    while (cur) {
        if (cur->key == key) {
            if (prev) {
                prev->next = cur->next;
            } else {
                table[idx] = cur->next;
            }
            free(cur); // Free memory
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

// Process multiple queries
int* processQueries(int queries[][3], int n, int* returnSize) {
    *returnSize = 0;
    int* results = (int*)malloc(n * sizeof(int)); // Enough space for all gets

    // Initialize hash table
    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }

    // Loop through all queries
    for (int i = 0; i < n; i++) {
        int type = queries[i][0];
        int key = queries[i][1];
        int value = queries[i][2];

        if (type == 1) {           // Insert
            inserth(key, value);
        } else if (type == 2) {    // Get
            results[*returnSize] = geth(key);
            (*returnSize)++;
        } else if (type == 3) {    // Delete
            delh(key);
        }
    }

    return results; // FIX: Now we actually return the results array
}

int main() {
    int n;
    scanf("%d", &n);
    int queries[n][3];

    // Reading queries from input
    for (int i = 0; i < n; ++i) {
        scanf("%d", &queries[i][0]);
        if (queries[i][0] == 1) { // Insert
            scanf("%d %d", &queries[i][1], &queries[i][2]);
        } else { // Get or Delete
            scanf("%d", &queries[i][1]);
            queries[i][2] = 0;
        }
    }

    int returnSize;
    int* results = processQueries(queries, n, &returnSize);

    // Output results of type 2 queries
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\n", results[i]);
    }

    free(results);
    return 0;
}
