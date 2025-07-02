#include <stdio.h>
#include <string.h>

struct Pelajar
{
    char nama[50];
    int umur;
    float gpa;
};

int main()
{
    struct Pelajar pelajar[2];

    printf("Masukkan maklumat pelajar 1:\n");
    printf("Nama: ");
    scanf("%s", pelajar[0].nama);
    printf("Umur: ");
    scanf("%d", &pelajar[0].umur);
    printf("GPA: ");
    scanf("%f", &pelajar[0].gpa);

    printf("\nNama dia: %s\n", pelajar[0].nama);

    strcpy(pelajar[1].nama, "Shafawati");
    pelajar[1].umur = 22;
    pelajar[1].gpa = 3.75;

    printf("Nama: %s\n", pelajar[0].nama);
    printf("Umur: %d\n", pelajar[0].umur);
    printf("GPA: %.2f\n\n", pelajar[0].gpa);

    printf("Nama: %s\n", pelajar[1].nama);
    printf("Umur: %d\n", pelajar[1].umur);
    printf("GPA: %.2f\n", pelajar[1].gpa);
}