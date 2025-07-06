#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main(){
    // Create Node
    Node* node1 = malloc(sizeof(struct Node));
    Node* node2 = malloc(sizeof(struct Node));
    Node* node3 = malloc(sizeof(struct Node));
    
    // Create Input
    printf("Masukkan nilai untuk Node 1: ");
    scanf("%d", &node1->data);
    printf("Masukkan nilai untuk Node 2: ");
    scanf("%d", &node2->data);
    printf("Masukkan nilai untuk Node 3: ");
    scanf("%d", &node3->data);
    
    // Connect Node
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    
    // Output node
    Node* current = NULL;
    current = node1;
    printf("\nLinked List:");
    while (current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
    
    return 0;
};