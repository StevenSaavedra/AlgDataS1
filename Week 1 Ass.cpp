#include <iostream>

class Matrix {
    private:
     int rows, cols;
     int** data;
    public:
     Matrix(int r, int c) : rows(r), cols(c) {
            data = new int*[rows];
            for(int i = 0; i < rows; i++) {
                data[i] = new int[cols]();
            }
        }
        ~Matrix() {
            for(int i = 0; i < rows; i++) {
                    delete[] data[i];
                }
                delete[] data;
            }
        Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}
        
      void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                std::cout << data[i][j] << " ";
            std:: cout << std::endl;
        }
    }
    void input() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                std::cin >> data[i][j];
    }
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cout << "Error: Matrices dimensions do not match for addition." << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                transposed.data[j][i] = data[i][j];
        return transposed;
    }
    



};



int main() {
    int r,c;

    std::cout << "Enter number of rows: ";
    std::cin >> r;
    std::cout << "Enter number of columns: ";
    std::cin >> c;

    Matrix m1(r, c);
    Matrix m2(r, c);
    std::cout << "Matrix 1:\n";
    m1.input();
    m1.print();

    std::cout << "Matrix 2:\n";
    m2.input();
    m2.print();

    Matrix sum = m1.add(m2);
    Matrix t1 = m1.transpose();
    Matrix t2 = m2.transpose();

    std::cout << "Sum of matrices:\n";
    sum.print();
    std::cout << "Transposed matrix 1:\n";
    t1.print();
    std::cout << "Transposed matrix 2:\n";
    t2.print();


    return 0;
}

// Encapsulation makes the code easier to maintain and update without breaking other parts of the program.
// It also helps in preventing unintended interference and misuse of the data.
// The Matrix class can be easily extended with more functionalities like subtraction, multiplication, etc., without affecting the existing code.