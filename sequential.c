#include <stdio.h>

// Fungsi Sequential Search
int sequentialSearch(int array[], int size, int target) {
    int i;
    for(i = 0; i < size; i++) {
        if(array[i] == target) {
            return i; // Jumpa di index ke-i
        }
    }
    return -1; // Tak jumpa
}

int main() {
    int array[100], saiz, cari, i;

    // Input saiz array
    printf("Masukkan bilangan elemen dalam array: ");
    scanf("%d", &saiz);

    // Input elemen satu per satu
    printf("Masukkan %d nombor:\n", saiz);
    for(i = 0; i < saiz; i++) {
        printf("Elemen ke-%d: ", i);
        scanf("%d", &array[i]);
    }

    // Input nilai yang nak dicari
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &cari);

    // Panggil fungsi
    int hasil = sequentialSearch(array, saiz, cari);

    // Papar hasil
    if(hasil != -1) {
        printf("Jumpa %d pada index %d\n", cari, hasil);
    } else {
        printf("Tak jumpa %d dalam array\n", cari);
    }

    return 0;
}