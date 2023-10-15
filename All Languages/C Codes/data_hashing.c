#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

typedef struct Node {
    char key[100];
    char value[100];
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

// Hash function
unsigned int hash(char* key) {
    unsigned int hashValue = 0;
    for (int i = 0; i < strlen(key); i++) {
        hashValue = hashValue * 31 + key[i];
    }
    return hashValue % HASH_TABLE_SIZE;
}

// Insert key-value pair into the hash table
void insert(char* key, char* value) {
    unsigned int index = hash(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // Collision handling: simple chaining
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

// Search for a value based on the key
char* search(char* key) {
    unsigned int index = hash(key);

    Node* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return "Key not found";
}

int main() {
    // Example usage
    insert("name", "John");
    insert("age", "25");
    insert("city", "New York");

    printf("Value for key 'name': %s\n", search("name"));
    printf("Value for key 'age': %s\n", search("age"));
    printf("Value for key 'city': %s\n", search("city"));
    printf("Value for key 'gender': %s\n", search("gender"));

    return 0;
}
