#include <stdio.h>

// Fungsi Binary Search
int binarySearch(int array[], int size, int target) {
    int kiri = 0;
    int kanan = size - 1;
    int tengah;

    while(kiri <= kanan) {
        tengah = (kiri + kanan) / 2;

        if(array[tengah] == target) {
            return tengah; // Jumpa
        } else if(array[tengah] < target) {
            kiri = tengah + 1; // Cari di kanan
        } else {
            kanan = tengah - 1; // Cari di kiri
        }
    }

    return -1; // Tak jumpa
}

int main() {
    int array[100], saiz, cari, i;

    // Input saiz array
    printf("Masukkan bilangan elemen dalam array (susun dalam naik): ");
    scanf("%d", &saiz);

    // Input elemen satu per satu
    printf("Masukkan %d nombor dalam susunan menaik:\n", saiz);
    for(i = 0; i < saiz; i++) {
        printf("Elemen ke-%d: ", i);
        scanf("%d", &array[i]);
    }

    // Input nilai yang nak dicari
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &cari);

    // Panggil fungsi
    int hasil = binarySearch(array, saiz, cari);

    // Papar hasil
    if(hasil != -1) {
        printf("Jumpa %d pada index %d\n", cari, hasil);
    } else {
        printf("Tak jumpa %d dalam array\n", cari);
    }

    return 0;
}