#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk sehelai kertas pelajar
struct Node
{
    char nama[50];     // Bahagian nama di kertas
    int umur;          // Bahagian umur di kertas
    struct Node *next; // Bahagian stapler ke kertas seterusnya
};

int main()
{
    struct Node *head = NULL;    // Fail kosong, belum ada kertas
    struct Node *current = NULL; // Tangan yang pegang kertas sekarang

    int bil;

    printf("Berapa orang pelajar nak dimasukkan? ");
    scanf("%d", &bil);

    for (int i = 0; i < bil; i++)
    {
        // 1️⃣ Cipta kertas baru
        struct Node *baru = (struct Node *)malloc(sizeof(struct Node));
        // Kertas kosong: [ NAMA: ___ ][ UMUR: ___ ][ NEXT: NULL ]

        printf("\nPelajar ke-%d\n", i + 1);

        // 2️⃣ Tulis nama di kertas
        printf("Nama: ");
        fgets(baru->nama, sizeof(baru->nama), stdin);

        // 3️⃣ Tulis umur di kertas
        printf("Umur: ");
        scanf("%d", &baru->umur);

        // 4️⃣ Stapler belum sambung ke sesiapa lagi
        baru->next = NULL;

        // 5️⃣ Letak kertas dalam fail
        if (head == NULL)
        {
            // Kalau fail kosong, kertas ni jadi kertas pertama (head)
            head = baru;
            current = head;
        }
        else
        {
            // Staplerkan kertas sekarang ke kertas baru
            current->next = baru;

            // Pegang kertas baru untuk sambungan seterusnya nanti
            current = current->next;
        }
    }

    // 6️⃣ Baca satu-satu semua kertas dalam fail
    printf("\nIsi Fail Pelajar:\n");
    current = head;
    while (current != NULL)
    {
        printf("Nama: %s, Umur: %d\n", current->nama, current->umur);
        current = current->next; // Pindah ke kertas seterusnya
    }

    return 0;
}