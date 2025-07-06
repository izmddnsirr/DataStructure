#include <stdio.h>

int main() {
    int array[] = {6, 1, 7, 5, 0};
    int n = 5;
    
    int i, j, temp;
    
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    printf("Nilai tersusun: ");
    for(int k = 0; k < n; k++) {
        printf("%d, ", array[k]);
    }
}