// main.cpp
#include <mpi.h>
#include <omp.h>
#include <iostream>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        #pragma omp critical
        std::cout << "Hello from thread " << tid << "/" << nthreads
                  << " on MPI rank " << rank << "/" << size << std::endl;
    }

    MPI_Finalize();
    return 0;
}
