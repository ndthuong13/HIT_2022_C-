#include <iostream>
#include <omp.h>
#include <cstdlib>

#define SIZE 1000

void generate_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % size;
        }
    }
}

void count_frequency(int **matrix, int *frequency, int size) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            #pragma omp atomic
            frequency[matrix[i][j]]++;
        }
    }
}

void multiply_matrices(int **A, int **B, int **C, int size) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void sum_matrices(int **A, int **B, int **C, long long &sumA, long long &sumB, long long &sumC, int size) {
    #pragma omp parallel for reduction(+:sumA, sumB, sumC) collapse(2)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sumA += A[i][j];
            sumB += B[i][j];
            sumC += C[i][j];
        }
    }
}

int main() {
    int **A = new int*[SIZE];
    int **B = new int*[SIZE];
    int **C = new int*[SIZE];
    int *frequency = new int[SIZE]();
    for (int i = 0; i < SIZE; i++) {
        A[i] = new int[SIZE];
        B[i] = new int[SIZE];
        C[i] = new int[SIZE];
    }

    generate_matrix(A, SIZE);
    generate_matrix(B, SIZE);

    long long sumA = 0, sumB = 0, sumC = 0;

    #pragma omp parallel sections
    {
        #pragma omp section
        multiply_matrices(A, B, C, SIZE);

        #pragma omp section
        sum_matrices(A, B, C, sumA, sumB, sumC, SIZE);

        #pragma omp section
        count_frequency(A, frequency, SIZE);
    }

    std::cout << "Sum of A: " << sumA << std::endl;
    std::cout << "Sum of B: " << sumB << std::endl;
    std::cout << "Sum of C: " << sumC << std::endl;

    for (int i = 0; i < SIZE; i++) {
        if (frequency[i] > 0) {
            std::cout << "Number " << i << " appears " << frequency[i] << " times." << std::endl;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] frequency;

    return 0;
}
