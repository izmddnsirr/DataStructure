#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Masukkan ke dalam queue
void enqueue(int data) {
    if(rear == MAX - 1) {
        printf("Queue penuh!\n");
    } else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = data;
        printf("Masuk: %d\n", data);
    }
}

// Keluarkan dari queue
void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue kosong!\n");
    } else {
        printf("Keluar: %d\n", queue[front]);
        front++;
    }
}

// Tengok depan queue
void peek() {
    if(front == -1 || front > rear) {
        printf("Queue kosong!\n");
    } else {
        printf("Depan: %d\n", queue[front]);
    }
}

// Papar semua isi queue
void display() {
    if(front == -1 || front > rear) {
        printf("Queue kosong!\n");
    } else {
        printf("Isi Queue: ");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    peek();
    display();
    dequeue();
    display();
    return 0;
}