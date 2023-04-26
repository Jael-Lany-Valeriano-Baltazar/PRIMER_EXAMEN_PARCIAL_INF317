#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 100 // número de decimales a sumar

int main()
{
int i, j, k = 1;
double a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

#pragma omp for private(i)
for (i=0;i<MAX;i++)
  for (j=0;j<MAX;j++)
  {
     a[i][j]=k;
   b[i][j]=k;
   k++;
  }
  

#pragma omp for private(i)
for (i=0;i<MAX;i++)
  for (j=0;j<MAX;j++)
  {
     c[i][j]=c[i][j]+a[i][j]*b[i][j];
  }

    #pragma omp for private(i)
// imprimir resultado
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%f ", c[i][j]);
        }
        printf("\n");
    }

return 0;
}

//Compilar:
//  gcc -fopenmp EJERCICIO_6_OPEN.c -o e6_open
//Ejecutar:
//  ./e6_open