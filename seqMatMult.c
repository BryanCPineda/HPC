#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0

void printMatrix(int *matriz, int n);
void MatrixMultiply(int n, int *a, int *b, int *c);
int *arrayToMatrix(int r, int c);
void fillInMatriz(int *arr, int r, int c);

int *a;
int *b;
int *c;

void MatrixMultiply(int n, int *a, int *b, int *c)
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                c[i * n + j] += a[i * n + k] * b[k * n + j];
}

void printMatrix(int *matriz, int n)
{
    int i;
    int j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", matriz[i * n + j]);
        }
        printf("\n");
    }
}

int main()
{

    struct timeval start, stop;
    int tam;
    printf("Introduzca el tamano de la matriz\n");
    scanf("%d", &tam);
    srand(time(NULL));

    a = arrayToMatrix(tam, tam);
    b = arrayToMatrix(tam, tam);
    c = arrayToMatrix(tam, tam);

    fillInMatriz(&a[0], tam, tam);
    fillInMatriz(&b[0], tam, tam);

    /* Si queremos imprimir las matrices A y B */
    if(tam <=10)
    {
        printf("Matriz 1 \n");
        printMatrix(&a[0], tam);
        printf("Matriz 2 \n");
        printMatrix(&b[0], tam);
    }
    /* Mide el tiempo de la multiplicacion */
    gettimeofday(&start, 0);
    MatrixMultiply(tam, a, b, c);
    gettimeofday(&stop, 0);
    /* Si queremos podemos imprimir el resultado */
    if (tam <= 10)
    {
        printf("Matriz Resultado \n");
        printMatrix(&c[0], tam);
    }
    // Se detiene el tiempo y se muestran los resultados
    fprintf(stdout, "%0.10f\n",(stop.tv_sec + stop.tv_usec * 1e-6) - (start.tv_sec + start.tv_usec * 1e-6));

    return 0;
}


int *arrayToMatrix(int r, int c)
{
    int *mat = calloc(r * c, sizeof(int));
    return mat;
}

void fillInMatriz(int *arr, int r, int c)
{
    int j;
    for (j = 0; j < r * c; j++)
    {
        arr[j] = rand() % 10000;
    }
}


