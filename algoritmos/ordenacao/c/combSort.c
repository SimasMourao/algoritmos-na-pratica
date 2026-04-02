#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
// #include <unistd.h> // linux
#define TAM 20

void drawBars(int arr[], int size, int i, int j)
{
    int k, h;

    system("cls"); // use "cls" no Windows
    //system("clear"); // linux

    printf("Comb Sort - Visualizacao\n\n");

    for (k = 0; k < size; k++)
    {
        printf("%2d: ", arr[k]);

        for (h = 0; h < arr[k]; h++)
        {
            if (k == i || k == j)
                printf("#"); // destaque

            else
                printf("|");
        }

        printf("\n");
    }
}

void combSort(int arr[], int size)
{
    int gap = size;
    int trocou = 1;
    int i, j;

    while (gap > 1 || trocou)
    {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        trocou = 0;

        for (i = 0; i < size - gap; i++)
        {
            j = i + gap;

            drawBars(arr, size, i, j);
            Sleep(150);
            //usleep(150000) linux/unix

            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                trocou = 1;

                drawBars(arr, size, i, j);
                Sleep(150);
                //usleep(150000) linux/unix
            }
        }
    }
}

void shuffle(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void buildVetor(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
}

int main()
{
    srand(time(NULL));

    int arr[TAM];
    int num;

    // criar vetor
    buildVetor(arr, TAM);
    
    // embaralhar vetor
    shuffle(arr, TAM);

    // ordenar vetor
    combSort(arr, TAM);

    printf("\nOrdenado!\n");

    return 0;
}