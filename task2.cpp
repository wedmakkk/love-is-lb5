#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VERTICES 100  



void generate_matrix(int n, float p, int** adjacency_matrix, int** matrixs) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)rand() / RAND_MAX < p) {
                adjacency_matrix[i][j] = 1;
                adjacency_matrix[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrixs[i][j] = 0;
        }
    }
    int f = 0, h = 0,z=0;

    for (int i = 0; i < n; i++) {

        for (int j = z; j < n; j++) {
            
            if (adjacency_matrix[i][j] == 1)
            {
                matrixs[i][f] = 1;
                matrixs[j][f] = 1;
                f++;
               
            }
        }
        z++;
    }
}


void print_matrix(int n, int** adjacency_matrix, int** matrixs) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrixs[i][j]);
        }
        printf("\n");
    }
}

void counter_matrix(int n, int** adjacency_matrix, int** matrixs)
{
    int counter = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < i + 1;j++)
        {
            if (adjacency_matrix[i][j] == 1)
            {
                counter++;
            }
        }
    }
    printf("ribs: %i\npeaks: %i\n", counter, n);
    counter = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (matrixs[j][i] == 1)
            {
                counter++;
                break;
            }
        }
    }
    printf("\nribs2: % i\n", counter);
}
void stat(int n, int** adjacency_matrix, int**  matrixs)
{
    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "                           \n");
        return;
    }
    int* arra = (int*)malloc(n * sizeof(int));
    if (arra == NULL) {
        fprintf(stderr, "                           \n");
        return;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "                           \n");
        return;
    }

    for (int i = 0; i < n; i++) {
        array[i] = 0;
        arra[i] = 0;
        arr[i] = 0;
    }

    int counter = 0, f = 0, g = 0, h = 0;


    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n + 1;j++)
        {
            if (adjacency_matrix[i][j] == 1)
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            array[f] = i + 1;
            f++;
        }
        if (counter == 1)
        {
            arra[g] = i + 1;
            g++;
        }
        if (counter == n - 1)
        {
            arr[h] = i + 1;
            h++;
        }
        counter = 0;
    }
    printf("\nalone: ");
    for (int i = 0;i < n;i++)
    {
        if (array[i] != 0)
        {
            printf("%i ", array[i]);
        }
    }

    printf("\none: ");
    for (int i = 0;i < n;i++)
    {
        if (arra[i] != 0)
        {
            printf("%i ", arra[i]);
        }
    }
    printf("\nall: ");
    for (int i = 0;i < n;i++)
    {
        if (arr[i] != 0)
        {
            printf("%i ", arr[i]);
        }
    }
 

    for (int i = 0; i < n; i++) {
        array[i] = 0;
        arra[i] = 0;
        arr[i] = 0;
    }

    counter = 0, f = 0, g = 0, h = 0;


    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n + 1;j++)
        {
            if (matrixs[i][j] == 1)
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            array[f] = i + 1;
            f++;
        }
        if (counter == 1)
        {
            arra[g] = i + 1;
            g++;
        }
        if (counter == n - 1)
        {
            arr[h] = i + 1;
            h++;
        }
        counter = 0;
    }

    printf("\nstats2:\n");
    printf("\nalone: ");
    for (int i = 0;i < n;i++)
    {
        if (array[i] != 0)
        {
            printf("%i ", array[i]);
        }
    }

    printf("\none: ");
    for (int i = 0;i < n;i++)
    {
        if (arra[i] != 0)
        {
            printf("%i ", arra[i]);
        }
    }
    printf("\nall: ");
    for (int i = 0;i < n;i++)
    {
        if (arr[i] != 0)
        {
            printf("%i ", arr[i]);
        }
    }
    free(array);
    free(arra);
    free(arr);
}
int main() {
    int n;
    float p;


    srand(time(NULL));


    printf("Input count of peaks (no more % d) : ", MAX_VERTICES);
    scanf("%d", &n);
    if (n > MAX_VERTICES) {
        printf("Count of peaks then max count.\n");
        return 1;
    }
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0;i < n;i++)
    {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    printf("Enter the probability of having an edge (0.0 to 1.0):");
    scanf("%f", &p);
    if (p < 0.0 || p > 1.0) {
        printf("The probability should be in the range from 0.0 to 1.0.\n");
        return 1;
    }

    int** matrixs = (int**)malloc(n * sizeof(int*));
    for (int i = 0;i < n;i++)
    {
        matrixs[i] = (int*)malloc(n * sizeof(int));
    }
    generate_matrix(n, p, matrix,matrixs);


    print_matrix(n, matrix,matrixs);
    counter_matrix(n, matrix, matrixs);
    stat(n, matrix, matrixs);
    getchar();
    getchar();
    getchar();
    return 0;
}