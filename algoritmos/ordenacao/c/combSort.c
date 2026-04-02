#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // usleep
void drawBars(int arr[], int size, int i, int j) {
    int k, h;
    //system("cls"); // use "cls" no Windows
    //system("clear") // linux
    system("\033[H\033[J"); // GDB
    printf("Comb Sort - Visualizacao\n\n");
    for (k = 0; k < size; k++) {
        printf("%2d: ", arr[k]);
        for (h = 0; h < arr[k]; h++) {
            if (k == i || k == j) printf("#"); // destaque
            else printf("|");
        }
        printf("\n");
    }
}
void combSort(int arr[], int size) {
    int gap = size;
    int trocou = 1;
    int i, j;
    while (gap > 1 || trocou) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;
        trocou = 0;
        for (i = 0; i < size - gap; i++) {
            j = i + gap;
            drawBars(arr, size, i, j);
            usleep(150000);
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                trocou = 1;
                drawBars(arr, size, i, j);
                usleep(300000);
            }
        }
    }
}
int exist(int arr[], int index, int num){
    for(int i = 0; i < index; i++){
        if(arr[i] == num){
            return 1;
        }
    }
    return 0;
}
int main() {
    srand(time(NULL));
    int tam = rand()%20 + 5;
    int arr[tam];
    int num;
    for(int i = 0; i < tam; i++){
        do{
            num = rand()%30 + 1;
        }
        while(exist(arr, i, num));
            arr[i] = num;
    }
    combSort(arr, tam);
    printf("\nOrdenado!\n");
    return 0;
}