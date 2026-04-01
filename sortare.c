#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *v = NULL;
int n = 0;

// initializare vector
void init_vector() {
    printf("Introdu dimensiunea vectorului: ");
    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));
    if(v == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        v[i] = rand() % 1000;
    }

    printf("Vector generat!\n");
}

// afisare vector
void print_vector() {
    if(v == NULL) {
        printf("Vectorul nu este initializat!\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// eliberare memorie
void free_vector() {
    free(v);
    v = NULL;
    printf("Memoria a fost eliberata!\n");
}

// Bubble Sort
void bubble_sort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Quick Sort
void quick_sort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while(i <= j) {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;

        if(i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if(left < j) quick_sort(arr, left, j);
    if(i < right) quick_sort(arr, i, right);
}

// rulare bubble sort cu masurare timp
void run_bubble_sort() {
    if(v == NULL) {
        printf("Vectorul nu este initializat!\n");
        return;
    }

    clock_t start = clock();
    bubble_sort(v, n);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort timp: %f secunde\n", time);
}

// rulare quick sort cu masurare timp
void run_quick_sort() {
    if(v == NULL) {
        printf("Vectorul nu este initializat!\n");
        return;
    }

    clock_t start = clock();
    quick_sort(v, 0, n - 1);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort timp: %f secunde\n", time);
}

// analiza empirica 
void analiza_sortare() {
    int dimensiuni[] = {100, 1000, 10000, 100000};

    printf("\nAnaliza empirica a sortarii:\n");
    printf("N\t\tBubble Sort\t\tQuick Sort\n");

    for(int k = 0; k < 4; k++) {
        int size = dimensiuni[k];

        // vector original random
        int *original = (int*)malloc(size * sizeof(int));
        int *copie1 = (int*)malloc(size * sizeof(int));
        int *copie2 = (int*)malloc(size * sizeof(int));

        if(original == NULL || copie1 == NULL || copie2 == NULL) {
            printf("Eroare la alocarea memoriei!\n");
            free(original);
            free(copie1);
            free(copie2);
            return;
        }

        for(int i = 0; i < size; i++) {
            original[i] = rand() % 1000;
        }

        // facem 2 copii identice ca ambele metode sa sorteze aceleasi date
        for(int i = 0; i < size; i++) {
            copie1[i] = original[i];
            copie2[i] = original[i];
        }

        // Bubble Sort
        clock_t start1 = clock();
        bubble_sort(copie1, size);
        clock_t end1 = clock();
        double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

        // Quick Sort
        clock_t start2 = clock();
        quick_sort(copie2, 0, size - 1);
        clock_t end2 = clock();
        double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

        printf("%d\t\t%f\t\t%f\n", size, time1, time2);

        free(original);
        free(copie1);
        free(copie2);
    }
}

// meniu
void menu() {
    int choice;

    do {
        printf("\nMENIU \n");
        printf("1. Initializare vector\n");
        printf("2. Afisare vector\n");
        printf("3. Bubble Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Eliberare memorie\n");
        printf("6. Analiza empirica\n");
        printf("0. Iesire\n");
        printf("Alege: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: init_vector(); break;
            case 2: print_vector(); break;
            case 3: run_bubble_sort(); break;
            case 4: run_quick_sort(); break;
            case 5: free_vector(); break;
            case 6: analiza_sortare(); break;
        }

    } while(choice != 0);
}

int main() {
    srand(time(NULL));
    menu();
    return 0;
}