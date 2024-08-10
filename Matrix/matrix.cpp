#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

// Function to initialize a matrix with random values
void initialize_matrix(vector<vector<float>>& matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

// Function to perform matrix multiplication
void matrix_multiply(const vector<vector<float>>& a, const vector<vector<float>>& b, vector<vector<float>>& result, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to perform element-wise addition
void element_wise_add(const vector<vector<float>>& a, const vector<vector<float>>& b, vector<vector<float>>& result, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to perform element-wise multiplication
void element_wise_multiply(const vector<vector<float>>& a, const vector<vector<float>>& b, vector<vector<float>>& result, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
}

// Function to measure execution time of a function
double measure_time(void (*func)(const vector<vector<float>>&, const vector<vector<float>>&, 
                    vector<vector<float>>&, int),
                    const vector<vector<float>>& a, const vector<vector<float>>& b, 
                    vector<vector<float>>& result, int size) 
{

    auto start = chrono::high_resolution_clock::now();
    func(a, b, result, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

void compare_operations(int size) {
    // Initialize matrices
    vector<vector<float>> a(size, vector<float>(size));
    vector<vector<float>> b(size, vector<float>(size));
    vector<vector<float>> result(size, vector<float>(size));

    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));

    initialize_matrix(a, size);
    initialize_matrix(b, size);

    // Measure and perform matrix operations
    double mat_mult_time = measure_time(matrix_multiply, a, b, result, size);
    double elem_add_time = measure_time(element_wise_add, a, b, result, size);
    double elem_mult_time = measure_time(element_wise_multiply, a, b, result, size);

    // Print results
    cout << "Matrix multiplication: " << mat_mult_time << " ms" << endl;
    cout << "Element-wise addition: " << elem_add_time << " ms" << endl;
    cout << "Element-wise multiplication: " << elem_mult_time << " ms" << endl;
}

int main() {
    int matrix_size = 1000; // Adjust size as needed
    compare_operations(matrix_size);
    return 0;
}
