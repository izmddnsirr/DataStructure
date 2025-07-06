#include <stdio.h>
#include <stdlib.h>

// Struktur Node (orang beratur)
struct Node {
    int data;
    struct Node* next;
};

// Fungsi enqueue - masuk barisan di belakang
void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL) {
        // Barisan kosong
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode; // sambung ke belakang
        *rear = newNode;         // jadikan dia yang paling belakang
    }
}

// Fungsi dequeue - keluar barisan dari depan
void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue kosong!\n");
        return;
    }

    struct Node* temp = *front;
    printf("Dequeue: %d\n", temp->data);
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL; // kalau lepas keluar, tiada siapa dalam barisan
    }

    free(temp);
}

// Fungsi cetak Queue
void printQueue(struct Node* front) {
    printf("Isi Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}

// Fungsi utama
int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    printQueue(front); // 10 -> 20 -> 30

    dequeue(&front, &rear); // Keluarkan 10
    dequeue(&front, &rear); // Keluarkan 20
    dequeue(&front, &rear); // Keluarkan 30
    dequeue(&front, &rear); // Queue kosong

    printQueue(front); // Kosong

    return 0;
}
