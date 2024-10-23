#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void generate_matrix(int n, float p, int** adjacency_matrix) {
    
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
}


void print_matrix(int n, int** adjacency_matrix) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void counter_matrix(int n, int** adjacency_matrix)
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
}
void stat(int n, int** adjacency_matrix)
{
    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Ошибка при выделении памяти\n");
        return;
    }
    int* arra = (int*)malloc(n * sizeof(int));
    if (arra == NULL) {
        fprintf(stderr, "Ошибка при выделении памяти\n");
        return;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Ошибка при выделении памяти\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        array[i] = 0;
        arra[i] = 0;
        arr[i] = 0;
    }

    int counter = 0,f=0,g=0,h=0;


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
        if (counter == n-1)
        {
            arr[h] = i + 1;
			h++;
        }
		counter = 0;
    }
    printf("\nsolo: ");
    for (int i = 0;i < n;i++)
    {
        if(array[i] != 0)
		{
			printf("%i ",array[i]);
		}
    }

    printf("\none: ");
    for (int i = 0;i < n;i++)
    {
		if(arra[i] != 0)
		{
			printf("%i ",arra[i]);
		}
    }
    printf("\nall: ");
    for (int i = 0;i < n;i++)
    {
        if(arr[i] != 0)
		{
			printf("%i ",arr[i]);
		}
    }
}
int main() {
    int n; 
    float p; 
    
    
    srand(time(NULL));

    
    printf("Input count of peaks (no more % d) : ");
    scanf("%d", &n);
	int** matrix = (int**)malloc(n * sizeof(int*));
	for(int i=0;i<n;i++)
	{
		matrix[i]= (int*) malloc(n * sizeof(int));
	}
    printf("Enter the probability of having an edge (0.0 to 1.0):");
    scanf("%f", &p);
    if (p < 0.0 || p > 1.0) {
        printf("The probability should be in the range from 0.0 to 1.0.\n");
        return 1;
    }

    
    generate_matrix(n, p, matrix);

   
    print_matrix(n, matrix);
    counter_matrix(n, matrix);
    stat(n, matrix);
	getchar();
	getchar();
	getchar();
    return 0;
}