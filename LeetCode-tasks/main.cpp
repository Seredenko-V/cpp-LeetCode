#include <iostream>
#include <cassert>
#include <vector>
#include <cstdint>
#include <numeric>
#include <cmath>

using namespace std;

// Максимальное произведение — контрпример.
// https://new.contest.yandex.ru/42734/problem?id=215/2022_11_08/5Ai6zd8L0B

// Определите, можно ли построить такой пример входных данных, чтобы количество
// сравнений в алгоритме MaxPairwiseProduct было больше 1.5n.

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (const T& element : vec) {
        out << element << ' ';
    }
    return out;
}

vector<int> CreateSequence(int size) {
    vector<int> seq(size);
    seq[0] = size - 1;
    iota(next(seq.begin()), seq.end(), 0);
    return seq;
}

size_t FindNumChecksInMaxPairwiseProduct(const vector<int>& numbers) {
    assert(numbers.size() > 1);
    int m1 = numbers[0];
    int m2 = numbers[1];
    if (m2 > m1) {
        swap(m1, m2);
    }
    size_t count_checks = 1;
    for (size_t i = 2; i < numbers.size(); ++i) {
        ++count_checks;
        if (numbers[i] > m1) {
            m2 = m1;
            m1 = numbers[i];
        } else {
            ++count_checks;
            if (numbers[i] > m2) {
                m2 = numbers[i];
            }
        }
    }
    return count_checks;
}

bool IsFoundSequence(int size, vector<int>& numbers) {
    numbers = CreateSequence(size);
    return FindNumChecksInMaxPairwiseProduct(numbers) > size * 1.5;
}

namespace tests {
    void TestCreateSequence() {
        {
            const vector<int> seq = CreateSequence(10);
            const vector<int> expected{9,0,1,2,3,4,5,6,7,8};
            assert(seq == expected);
        }{
            const vector<int> seq = CreateSequence(2);
            const vector<int> expected{1,0};
            assert(seq == expected);
        }
        cerr << "TestCreateSequence passed"s << endl;
    }

    void TestFindNumChecksInMaxPairwiseProduct() {
        {
            const vector<int> seq{9,0,1,2,3,4,5,6,7,8};
            assert(FindNumChecksInMaxPairwiseProduct(seq) == 17);
        }{
            const vector<int> seq{99,0};
            assert(FindNumChecksInMaxPairwiseProduct(seq) == 1);
        }
        cerr << "TestFindNumChecksInMaxPairwiseProduct passed"s << endl;
    }

    void TestIsFoundSequence() {
        {
            vector<int> seq;
            assert(!IsFoundSequence(2, seq));
        }{
            vector<int> seq;
            assert(IsFoundSequence(10, seq));
            const vector<int> expected{9,0,1,2,3,4,5,6,7,8};
            assert(seq == expected);
        }
        cerr << "TestIsFoundSequence passed"s << endl;
    }

    void RunAllTests() {
        TestCreateSequence();
        TestFindNumChecksInMaxPairwiseProduct();
        TestIsFoundSequence();
        cerr << ">>> All Tests passed<<< "s << endl;
    }
} // namespace tests


int main() {
    tests::RunAllTests();
    int size = 0;
    cin >> size;
    vector<int> seq;
    if (IsFoundSequence(size, seq)) {
        cout << "Yes" << endl << seq;
    } else {
        cout << "No";
    }
    return 0;
}
