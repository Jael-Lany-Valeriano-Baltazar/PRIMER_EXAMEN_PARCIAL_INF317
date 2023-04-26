#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
void llenado_matriz_ceros(int M[][], int n)
{
for (i=0;i<n;i++)
  for (j=0;j<n;j++)
  {
     M[i][j]=i;
  }
} 

llenado_matriz(A,n);
llenado_matriz(B,n);
llenado_matriz_ceros(C,n);

MPI_Init();
MPI_Comm_size(...);
MPI_Comm_rank(...);

nsize, nrank;

if (nrank==0)
{
  for (i=0;i<MAX;i++)
  {
   MPI_rec(vector, MAX, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
}

if (nrank==0)
{
  for (i=0;i<MAX;i++)
  {
   vector[MAX] = 0;
   for (i=0;i<MAX;i++)
   {
     for (j=0;j<MAX;j++)
   {
        vector[i] = A[i][j]*B[i][j];
   }
   }
   MPI_send(vector, MAX, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
}

return 0;
}