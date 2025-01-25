// Merge Strings Alternatively
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void appendNode(Node** head, Node** tail, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed \n");
        exit(1);
    }

    newNode -> data = data;
    newNode -> next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail) -> next = newNode;
        *tail = newNode;
    }
}

char* ListToString(Node* head) {
    int length = 0;
    Node* current = head;

    while (current != NULL) {
        length ++;
        current = current -> next;
    }

    char* result = (char*)malloc((length + 1) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    current = head;
    int i = 0;
    while (current != NULL) {
        result[i++] = current -> data;
        current = current -> next;
    }
    result[i] = '\0';

    return result;
}

Node* mergeStrings(char* word1, char* word2){
    Node* head = NULL;
    Node* tail = NULL;
    int i = 0, j = 0;
    
    while (word1[i] != '\0' && word2[j] != '\0') {
        appendNode(&head, &tail, word1[i]);
        i++;

        appendNode(&head, &tail, word2[j]);
        j++;
    }

    while (word1[i] != '\0') {
        appendNode(&head, &tail, word1[i]);
        i++;
    }

    while (word2[j] != '\0') {
        appendNode(&head, &tail, word2[j]);
        j++;
    }

    return head;
}

void free_list(struct Node *head) {
    Node* current = head;
    Node* next;

    // Traverse the list and free each node
    while (current != NULL) {
        next = current -> next; // Save the pointer to the next node
        free(current);          // Free the current node
        current = next;         // Move to the next node
    }
}

char* mergeAlternately(char* word1, char* word2){
    Node* merged = mergeStrings(word1, word2);
    char* result = ListToString(merged);
    return result;
    free(result);
    free_list(merged);
}