#include <iostream>
#include <cassert>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <ctime>

using namespace std;

// Максимальное произведение.
// https://new.contest.yandex.ru/42734/problem?id=215/2022_11_08/wGEXsFgrcB

// Вычислить максимальное произведение двух чисел из последовательности.
// i != j, но допускается a_i == a_j

template <typename T>
istream& operator>>(istream& in, vector<T>& vec) {
    for (T& element : vec) {
        in >> element;
    }
    return in;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (const T& element : vec) {
        out << element << ' ';
    }
    return out;
}

uint64_t MaxMult(vector<int>& seq) {
    sort(seq.begin(), seq.end());
    return static_cast<uint64_t>(seq[seq.size() - 1]) * static_cast<uint64_t>(seq[seq.size() - 2]);
}

uint64_t MaxPairwiseProduct(const std::vector<int>& numbers) {
    uint64_t max_product = 0;
    int n = numbers.size();
    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product, static_cast<uint64_t>(numbers[first]) * static_cast<uint64_t>(numbers[second]));
        }
    }
    return max_product;
}

namespace tests {
    void TestMaxMult() {
        {
            vector<int> seq{1,2,3};
            assert(MaxMult(seq) == 6u);
        }{
            vector<int> seq{2,0};
            assert(MaxMult(seq) == 0);
        }
        cerr << "TestMaxMult passed"s << endl;
    }

    void StressTest(int num_elems, int max_value) {
        constexpr int kBeginRange = 2;
        assert(num_elems >= kBeginRange);
        while (true) {
            int size = 0;
            if (num_elems != kBeginRange) {
                size = rand() % (num_elems - kBeginRange) + kBeginRange;
            } else {
                size = kBeginRange;
            }

            vector<int> seq(size);
            for (int& elem : seq) {
                if (max_value) {
                    elem = rand() % max_value;
                } else {
                    elem = 0;
                }
            }
            //cerr << seq << endl;
            uint64_t resutl_1 = MaxPairwiseProduct(seq);
            uint64_t resutl_2 = MaxMult(seq);
            if (resutl_1 != resutl_2) {
                cerr << "Wrong answer. "s << resutl_1 << "!="s << resutl_2 << endl;
                break;
            }
            cerr << "OK"s << endl;
        }
    }
} // namespace tests


int main() {
    tests::TestMaxMult();
//    tests::StressTest(1000, 2e5);
    int size = 0;
    cin >> size;
    vector<int> seq(size);
    cin >> seq;
    cout << MaxMult(seq) << endl;
    return 0;
}
