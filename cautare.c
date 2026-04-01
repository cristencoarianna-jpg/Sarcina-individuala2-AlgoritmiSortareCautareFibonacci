#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *v = NULL;
int n = 0;

// functie de comparare pentru qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Initializare vector
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

// Afisare vector
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

// Eliberare memorie
void free_vector() {
    free(v);
    v = NULL;
    printf("Memoria a fost eliberata!\n");
}

// Linear Search
int linear_search(int x) {
    for(int i = 0; i < n; i++) {
        if(v[i] == x) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binary_search(int x) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(v[mid] == x) {
            return mid;
        } else if(v[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// Masurare timp pentru linear search
void run_linear_search() {
    if(v == NULL) {
        printf("Vectorul nu este initializat!\n");
        return;
    }

    int x;
    printf("Introdu numarul cautat: ");
    scanf("%d", &x);

    clock_t start = clock();
    int pos = linear_search(x);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;

    if(pos != -1)
        printf("Numarul a fost gasit pe pozitia %d\n", pos);
    else
        printf("Numarul nu a fost gasit\n");

    printf("Linear search timp: %f secunde\n", time);
}

// Masurare timp pentru binary search
void run_binary_search() {
    if(v == NULL) {
        printf("Vectorul nu este initializat!\n");
        return;
    }

    int x;
    printf("Introdu numarul cautat: ");
    scanf("%d", &x);

    // sortam rapid vectorul pentru binary search
    qsort(v, n, sizeof(int), cmp);

    clock_t start = clock();
    int pos = binary_search(x);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;

    if(pos != -1)
        printf("Numarul a fost gasit pe pozitia %d\n", pos);
    else
        printf("Numarul nu a fost gasit\n");

    printf("Binary search timp: %f secunde\n", time);
}

// Analiza empirica
void analiza_cautare() {
    int dimensiuni[] = {100, 1000, 10000, 100000};

    printf("\nAnaliza empirica (1000000 cautari):\n");
    printf("N\t\tLinear Search\t\tBinary Search\n");

    for(int k = 0; k < 4; k++) {
        n = dimensiuni[k];

        free(v);
        v = (int*)malloc(n * sizeof(int));

        if(v == NULL) {
            printf("Eroare la alocarea memoriei!\n");
            return;
        }

        for(int i = 0; i < n; i++) {
            v[i] = rand() % 100000;
        }

        // Linear search
        clock_t start1 = clock();
        for(int i = 0; i < 1000000; i++) {
            int x = rand() % 100000;
            linear_search(x);
        }
        clock_t end1 = clock();
        double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

        // sortare rapida pentru binary search
        qsort(v, n, sizeof(int), cmp);

        // Binary search
        clock_t start2 = clock();
        for(int i = 0; i < 1000000; i++) {
            int x = rand() % 100000;
            binary_search(x);
        }
        clock_t end2 = clock();
        double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

        printf("%d\t\t%f\t\t%f\n", n, time1, time2);
    }
}

// Meniu
void menu() {
    int choice;

    do {
        printf("\n--- MENIU ---\n");
        printf("1. Initializare vector\n");
        printf("2. Afisare vector\n");
        printf("3. Linear search\n");
        printf("4. Binary search\n");
        printf("5. Eliberare memorie\n");
        printf("6. Analiza empirica\n");
        printf("0. Iesire\n");
        printf("Alege: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: init_vector(); break;
            case 2: print_vector(); break;
            case 3: run_linear_search(); break;
            case 4: run_binary_search(); break;
            case 5: free_vector(); break;
            case 6: analiza_cautare(); break;
        }

    } while(choice != 0);
}

int main() {
    srand(time(NULL));
    menu();
    return 0;
}