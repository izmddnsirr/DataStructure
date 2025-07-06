#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node
struct Node {
    char name[100];
    int age;
    struct Node* next;
};

// Insert di depan
void insertFront(struct Node** head, char name[], int age) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = *head;
    *head = newNode;
}

// Insert di belakang
void insertLast(struct Node** head, char name[], int age) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Cetak senarai
void printList(struct Node* node) {
    printf("\nSenarai Pelajar:\n");
    printf("-----------------------------\n");
    while (node != NULL) {
        printf("Nama : %s\n", node->name);
        printf("Umur : %d\n", node->age);
        printf("-----------------------------\n");
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    int pilihan;
    char nama[100];
    int umur;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Masukkan di depan\n");
        printf("2. Masukkan di belakang\n");
        printf("3. Papar senarai\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // buang newline

        switch (pilihan) {
            case 1:
                printf("Nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;

                printf("Umur: ");
                scanf("%d", &umur);
                getchar();

                insertFront(&head, nama, umur);
                break;

            case 2:
                printf("Nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;

                printf("Umur: ");
                scanf("%d", &umur);
                getchar();

                insertLast(&head, nama, umur);
                break;

            case 3:
                printList(head);
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak sah.\n");
        }

    } while (pilihan != 0);

    return 0;
}