#include <iostream>
#include <vector>
using namespace std;

class MatrixInt {
private:
    vector<vector<int>> data;
    int rows;
    int cols;
public:
    MatrixInt(int r, int c) : rows(r), cols(c), data(r, vector<int>(c, 0)) {}

    int& operator()(int r, int c) {
        return data[r][c];
    }

    MatrixInt operator+(MatrixInt& other) {
        MatrixInt result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
    }
    MatrixInt& operator+=(MatrixInt& other) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; i++)
                this->data[i][j] += other.data[i][j];
        return *this;
    }
    MatrixInt operator~() {
        MatrixInt result(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = this->data[i][j];
        return result;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << "\t";
            cout << endl;
        }
    }
};

int main() {
    MatrixInt mat1(3, 4);
    mat1(0, 0) = 1;
    mat1(1, 1) = 2;
    mat1(2, 2) = 3;
    cout << "mat1 =" << endl;
    mat1.print();
    cout << endl;

    MatrixInt mat2(3, 4);
    mat2(0, 0) = 4;
    mat2(1, 1) = 5;
    mat2(2, 2) = 6;
    cout << "mat2 =" << endl;
    mat2.print();
    cout << endl;

    MatrixInt mat3 = mat1 + mat2;
    cout << "mat3 = mat1 + mat2" << endl;
    mat3.print();
    cout << endl;

    cout << "mat1 += mat3" << endl;
    mat1 += mat3;
    mat1.print();
    cout << endl;

    cout << "mat1 = -1*mat1" << endl;
    mat1 = -1 * mat1;
    mat1.print();
    cout << endl;

    MatrixInt mat4 = ~mat2;
    cout << "mat4 = ~mat2" << endl;
    mat4.print();
    cout << endl;

    MatrixInt mat5 = mat1 * mat4;
    cout << "mat5 = mat1 * mat4" << endl;
    mat5.print();
    cout << endl;

    return 0;
}

