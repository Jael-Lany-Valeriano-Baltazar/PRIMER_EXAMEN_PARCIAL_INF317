#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
  int rank, size;
  char word[] = "anitalavalatina"; // palabra a verificar
  int n = strlen(word);
  int is_palindrome = 1; // asumimos que la palabra es un palindromo
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (rank == 0) {
    for (int i = 0; i < n / 2; i++) {
      if (word[i] != word[n - i - 1]) {
        is_palindrome = 0; // si los caracteres no coinciden, no es un palindromo
        break;
      }
    }
  }
  int global_is_palindrome;
  MPI_Bcast(&is_palindrome, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Reduce(&is_palindrome, &global_is_palindrome, 1, MPI_INT, MPI_LAND, 0, MPI_COMM_WORLD);
  if (rank == 0) {
    if (global_is_palindrome) {
      printf(" > %s es un palindromo\n", word);
    } else {
      printf(" > %s no es un palindromo\n", word);
    }
  }
  MPI_Finalize();
  return 0;
}

//COMPILAR CON 4 PROCESADORES:
//  mpiexec --use-hwthread-cpus -n 4 ./ejecutable


//librería para VSCode, MPI: /usr/lib/x86_64-linux-gnu/openmpi/include/