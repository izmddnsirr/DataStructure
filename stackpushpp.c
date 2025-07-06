#include <stdio.h>
#include <stdlib.h>

// Struktur Node (pinggan)
struct Node
{
    int data;
    struct Node *next;
};

// Fungsi push - letak pinggan atas rak
void push(struct Node **top, int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));                // buat pinggan baru
    newNode->data = value;                                             // isi nombor pinggan
    newNode->next = *top;                                              // sambung pinggan baru ke pinggan lama
    *top = newNode;                                                    // jadikan pinggan baru sebagai paling atas
}

// Fungsi pop - ambil pinggan atas rak
void pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack kosong!\n");
        return;
    }

    struct Node *temp = *top;        // pegang pinggan atas
    printf("Pop: %d\n", temp->data); // tunjuk nombor pinggan
    *top = (*top)->next;             // tukar atas kepada pinggan bawah
    free(temp);                      // buang pinggan atas
}

// Fungsi cetak isi Stack
void printStack(struct Node *top)
{
    printf("Isi Stack: ");
    while (top != NULL)
    {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

// Fungsi utama
int main()
{
    struct Node *stack = NULL; // rak mula-mula kosong

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(stack); // 30 -> 20 -> 10

    pop(&stack); // Keluarkan 30
    pop(&stack); // Keluarkan 20
    pop(&stack); // Keluarkan 10
    pop(&stack); // Stack kosong

    printStack(stack); // Kosong

    return 0;
}
