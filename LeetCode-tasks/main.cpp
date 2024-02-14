#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

// Разбиение Ломуто.
// https://new.contest.yandex.ru/48570/problem?id=215/2023_04_06/onaxya4yqZ
// Постройте разбиение Ломуто относительно первого числа.
// В тестах хендбука ошибка. Данное решение является верным

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (int element : vec) {
        out << element << ' ';
    }
    return out;
}

template <typename Iterator>
void BubbleSort(Iterator begin, Iterator end) {
    for (Iterator it_external = begin; it_external != end; ++it_external) {
        Iterator it_end = prev(end);
        for (Iterator it_internal = begin; it_internal != it_end; ++it_internal) {
            if (*it_internal > *next(it_internal)) {
                swap(*it_internal, *next(it_internal));
            }
        }
        --it_end;
    }
}

void LomutoSplit(vector<int>& seq) {
    constexpr size_t kIndexPivot = 0;
    size_t index_last_less_elem = 1;
    for (size_t i = index_last_less_elem; i < seq.size(); ++i) {
        if (seq[i] < seq[kIndexPivot]) {
            swap(seq[i], seq[index_last_less_elem++]);
        }
    }
    BubbleSort(seq.begin(), seq.begin() + index_last_less_elem);
}

namespace tests {
    void TestBubbleSorting() {
        { // весь диапазон
            vector<int> seq{3,4,6,1};
            const vector<int> kExpectedSeq{1,3,4,6};
            BubbleSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{3,4,7,17};
            const vector<int> kExpectedSeq(seq);
            BubbleSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{ // часть диапазона
            vector<int> seq{4,3,2,1,7,5,8,9,6};
            const vector<int> kExpectedSeq{1,2,3,4,7,5,8,9,6};
            BubbleSort(seq.begin(), seq.begin() + 4);
            assert(seq == kExpectedSeq);
        }
        cerr << "TestBubbleSorting passed"s << endl;
    }

    void TestLomutoSplitting() {
        {
            vector<int> seq{4,7,2,5,3,1,8,9,6};
            const vector<int> kExpectedSeq{1,2,3,4,7,5,8,9,6};
            LomutoSplit(seq);
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{3,4,7,17};
            const vector<int> kExpectedSeq(seq);
            LomutoSplit(seq);
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{1,3,2,9,10};
            const vector<int> kExpectedSeq(seq);
            LomutoSplit(seq);
            assert(seq == kExpectedSeq);
        }
        cerr << "TestLomutoSplitting passed"s << endl;
    }

    void RunAllTests() {
        TestBubbleSorting();
        TestLomutoSplitting();
        cerr << ">>> AllTests passed <<<"s << endl;
    }
} // namespace tests


int main() {
    tests::RunAllTests();
    int size = 0;
    cin >> size;
    vector<int> seq(size);
    for (int& element : seq) {
        cin >> element;
    }
    LomutoSplit(seq);
    cout << seq << endl;
    return 0;
}
