// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    // Buat kotak
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    // Sambungkan kotak
    first->next = second;
    second->next = third;
    third->next = NULL;

    // input untuk letak dalam kotak
    printf("\nMasukkan dalam kotak pertama: ");
    scanf("%d", &first->data);

    printf("Masukkan dalam kotak kedua: ");
    scanf("%d", &second->data);

    printf("Masukkan dalam kotak ketiga: ");
    scanf("%d", &third->data);

    // output semua kotak
    printf("\nKotak pertama: %d", first->data);
    printf("\nKotak kedua: %d", second->data);
    printf("\nKotak ketiga: %d\n\n", third->data);

    return 0;
}