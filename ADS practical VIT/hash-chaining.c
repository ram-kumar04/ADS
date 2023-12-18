#include <stdio.h>
#include <stdlib.h>


// Define the size of the hash table
#define TABLE_SIZE 10


// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};


// Hash table structure
struct HashTable {
    struct Node* table[TABLE_SIZE];
};


// Initialize the hash table
void initializeHashTable(struct HashTable* hashTable) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
}


// Hash function to determine the index in the hash table
int hashFunction(int key) {
    return key % TABLE_SIZE;
}


// Insert a value into the hash table
void insert(struct HashTable* hashTable, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;


    // Calculate the hash value
    int index = hashFunction(value);


    // Insert the node into the linked list at the calculated index
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        // Handle collision by chaining
        struct Node* current = hashTable->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


// Display the contents of the hash table
void display(struct HashTable* hashTable) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* current = hashTable->table[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}


int main() {
    struct HashTable hashTable;
    initializeHashTable(&hashTable);


    // Insert values into the hash table
    insert(&hashTable, 12);
    insert(&hashTable, 22);
    insert(&hashTable, 42);
    insert(&hashTable, 7);
    insert(&hashTable, 17);
    insert(&hashTable, 27);
    insert(&hashTable, 37);


    // Display the hash table
    display(&hashTable);


    return 0;
}
