#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define PRECISION 1000

int main(int argc, char** argv) {
    int i, rank, size, iter_per_proc;
    double sum = 0.0, pi = 0.0, t_start, t_end, elapsed_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    iter_per_proc = 100000 / size; // número de iteraciones por proceso

    t_start = MPI_Wtime();

    for (i = rank * iter_per_proc + 1; i <= (rank + 1) * iter_per_proc; i++) {
        sum += pow(-1, i+1) / (2*i - 1);
    }

    MPI_Reduce(&sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    t_end = MPI_Wtime();
    elapsed_time = t_end - t_start;

    if (rank == 0) {
        pi *= 4.0;
        printf("Pi con %d decimales de precisión: %.1000f\n", PRECISION, pi);
        printf("Tiempo total: %.2f segundos\n", elapsed_time);
    }

    MPI_Finalize();
    return 0;
}
