#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdlib>

#define SIZE 10000000

void generate_numbers(std::vector<int>& vec) {
    for (int& num : vec) {
        num = rand() % SIZE;
    }
}

void count_frequency(const std::vector<int>& vec, std::vector<int>& frequency) {
    #pragma omp parallel for
    for (size_t i = 0; i < vec.size(); i++) {
        #pragma omp atomic
        frequency[vec[i]]++;
    }
}

void bubble_sort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; i++) {
        for (size_t j = 0; j < vec.size() - 1 - i; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::vector<int> array(SIZE);
    std::vector<int> frequency(SIZE, 0);
    long long sum = 0;

    generate_numbers(array);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            #pragma omp parallel for reduction(+:sum)
            for (size_t i = 0; i < array.size(); i++) {
                sum += array[i];
            }
            std::cout << "Sum: " << sum << std::endl;
        }

        #pragma omp section
        {
            bubble_sort(array);
            std::cout << "Array sorted." << std::endl;
        }

        #pragma omp section
        {
            count_frequency(array, frequency);
            std::cout << "Frequency count done." << std::endl;
        }
    }

    // Display frequency
    for (size_t i = 0; i < frequency.size(); i++) {
        if (frequency[i] > 0) {
            std::cout << "Number " << i << " appears " << frequency[i] << " times." << std::endl;
        }
    }

    return 0;
}
