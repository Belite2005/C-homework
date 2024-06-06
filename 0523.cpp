#include <iostream>

template <typename T>
class Matrix {
private:
    T** data; // Pointer to 2D array
    int rows; // Number of rows
    int cols; // Number of columns

public:
    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T*[rows]; // Allocate memory for rows
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols]; // Allocate memory for columns
            for (int j = 0; j < cols; ++j) {
                data[i][j] = static_cast<T>(i * cols + j); // Fill matrix with sequential values
            }
        }
    }

    // Destructor
    ~Matrix() {
        // Free memory for each row
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        // Free memory for array of row pointers
        delete[] data;
    }

    // Print matrix dimensions
    void printMatrixDimensions() const {
        std::cout << "Matrix dimensions: " << rows << "x" << cols << std::endl;
    }

    // Print matrix
    void printMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create two matrices of different dimensions
    Matrix<int> matrix1(3, 4);
    Matrix<double> matrix2(2, 2);

    // Print matrix dimensions and contents
    matrix1.printMatrixDimensions();
    matrix1.printMatrix();
    std::cout << std::endl;

    matrix2.printMatrixDimensions();
    matrix2.printMatrix();

    return 0;
}
