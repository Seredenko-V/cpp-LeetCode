#include <iostream>
#include <vector>
#include <cassert>
#include <cstdint>

using namespace std;

// A(x) + B(x).
// https://new.contest.yandex.ru/42492/problem?id=215/2022_11_08/r1Y2AFKOd5

// Вычислить сумму многочленов
// A(x) = a_n * x^n + ... + a_1 * x + a_0
// B(x) = b_m * x^m + ... + b_1 * x + b_0

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (T element : vec) {
        out << element << ' ';
    }
    return out;
}

template <typename T>
istream& operator>>(istream& in, vector<T>& vec) {
    size_t size = 0;
    in >> size;
    vec.resize(size + 1); // с учетом 0-й степени
    for (T& element : vec) {
        in >> element;
    }
    return in;
}

template <typename T>
vector<T> PolynomialSum(const vector<T>& lhs, const vector<T>& rhs) {
    assert(lhs.size() >= rhs.size());
    vector<T> polynom_sum = lhs;
    for (size_t i = lhs.size() - rhs.size(), j = 0; i < lhs.size(); ++i, ++j) {
        polynom_sum[i] += rhs[j];
    }
    return polynom_sum;
}

template <typename T>
vector<T> operator+(const vector<T>& lhs, const vector<T>& rhs) {
    return lhs.size() > rhs.size() ? PolynomialSum(lhs, rhs) : PolynomialSum(rhs, lhs);
}


namespace tests {
    void TestPolynomialSum() {
        {
            vector<int> A{1,2,3,4};
            vector<int> B{1,0,0};
            vector<int> expected_sum{1,3,3,4};
            assert(A + B == expected_sum);
        }{
            vector<int> A{1};
            vector<int> B{1,2,3,4,5,6,7,8,9,0};
            vector<int> expected_sum{1,2,3,4,5,6,7,8,9,1};
            assert(A + B == expected_sum);
        }{
            vector<int> A{1,1};
            vector<int> B = A;
            vector<int> expected_sum{2,2};
            assert(A + B == expected_sum);
        }{
            vector<int> A{-100};
            vector<int> B = A;
            vector<int> expected_sum{-200};
            assert(A + B == expected_sum);
        }{
            vector<int> A{-100, 100};
            vector<int> B{100, -150};
            vector<int> expected_sum{0, -50};
            assert(A + B == expected_sum);
        }{
            vector<int> A;
            vector<int> B;
            assert((A + B).empty());
        }{
            vector<int> A;
            vector<int> B{1,2,4,6,7,9};
            assert(A + B == B);
        }
        cerr << "TestPolynomialSum passed"s << endl;
    }
} // namespace tests


int main() {
    tests::TestPolynomialSum();
    vector<int> A;
    vector<int> B;
    cin >> A >> B;
    vector<int> C = A + B;
    !C.size() ? cout << 0 : cout << C.size() - 1;
    cout << endl;
    cout << C << endl;
    return 0;
}
