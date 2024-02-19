#include <iostream>
#include <cassert>
#include <vector>
#include <cstdint>

using namespace std;

// A+B матрицы.
// https://new.contest.yandex.ru/42492/problem?id=6789665/2023_04_06/xWOwt1Aj4A

// Вычислить сумму двух матриц C = A + B.

template <typename T>
struct Matrix {
    Matrix(int num_str, int num_col)
        : str(num_str)
        , col(num_col) {
        if (!IsCorrect(str) || !IsCorrect(col)) {
            return;
        }
        elements.resize(str, vector<T>(col));
    }

    bool IsCorrect(int value) {
        return value >= 1 && value <= 10;
    }

    const uint16_t str = 0;
    const uint16_t col = 0;
    vector<vector<T>> elements;
};

template <typename T>
istream& operator>>(istream& in, Matrix<T>& matrix) {
    for (uint16_t i = 0; i < matrix.str; ++i) {
        for (uint16_t j = 0; j < matrix.col; ++j) {
            in >> matrix.elements[i][j];
        }
    }
    return in;
}

template <typename T>
ostream& operator<<(ostream& out, const Matrix<T>& matrix) {
    for (uint16_t i = 0; i < matrix.str; ++i) {
        for (uint16_t j = 0; j < matrix.col; ++j) {
            out << matrix.elements[i][j] << ' ';
        }
        out << endl;
    }
    return out;
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) {
    Matrix<T> result(lhs.str, lhs.col);
    for (size_t i = 0; i < result.str; ++i) {
        for (size_t j = 0; j < result.col; ++j) {
            result.elements[i][j] = lhs.elements[i][j] + rhs.elements[i][j];
        }
    }
    return result;
}

template <typename T>
bool operator==(const Matrix<T>& lhs, const Matrix<T>& rhs) {
    if (lhs.str != rhs.str || lhs.col != rhs.col) {
        return false;
    }
    return lhs.elements == rhs.elements;
}

namespace tests {
    void TestSumMatrix() {
        {
            const int kStr = 2;
            const int kCol = 3;
            Matrix<int> A(kStr, kCol);
            A.elements = {
                {1,2,3},
                {4,5,6}
            };
            Matrix<int> B(kStr, kCol);
            B.elements = {
                {-1,-2,-3},
                {-4,-5,-6}
            };
            Matrix<int> kExpected(kStr, kCol);
            kExpected.elements = {
                {0,0,0},
                {0,0,0}
            };
            assert(kExpected == A + B);
        }
        cerr << "TestSumMatrix passed"s << endl;
    }
} // namespace tests


int main() {
    tests::TestSumMatrix();
    int str = 0, col = 0;
    cin >> str >> col;
    Matrix<int> A(str, col);
    Matrix<int> B(str, col);
    cin >> A >> B;
    cout << A + B << endl;
    return 0;
}
