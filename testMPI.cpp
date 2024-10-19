#include <mpi.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    const int n = 1000; // Matrix size
    std::vector<int> matrix;

    // Only the root process initializes the complete matrix
    if (world_rank == 0) {
        matrix.resize(n * n);
        std::srand(std::time(0));
        for (int i = 0; i < n * n; ++i) {
            matrix[i] = std::rand() % 100; // Random number between 0 and 99
        }
    }

    // Calculate the number of rows each process will handle
    int rows_per_process = n / world_size;
    std::vector<int> sub_matrix(rows_per_process * n);

    // Scatter the rows of the matrix to all processes
    MPI_Scatter(matrix.data(), rows_per_process * n, MPI_INT, sub_matrix.data(), rows_per_process * n, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process calculates the sum of its sub-matrix
    int local_sum = 0;
    for (int i = 0; i < rows_per_process * n; ++i) {
        local_sum += sub_matrix[i];
    }

    // The root process collects the local sums from all processes
    int global_sum = 0;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // The root process prints the total sum
    if (world_rank == 0) {
        std::cout << "Total sum of matrix elements: " << global_sum << std::endl;
    }

    MPI_Finalize();
    return 0;
}