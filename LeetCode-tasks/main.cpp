#include <iostream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;

// Быстрая сортировка.
// https://new.contest.yandex.ru/48570/problem?id=215/2023_04_06/qQS9a7rB0y

// Опорный элемент выбирается случайно. Решение для Random Access итераторов

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (int element : vec) {
        out << element << ' ';
    }
    return out;
}

int GetRandomValue(int left_bound, int right_bound) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> distrib(left_bound, right_bound);
    return distrib(gen);
}

template <typename Iterator>
Iterator FindBound(Iterator begin, Iterator end, size_t size) {
    using Type = typename iterator_traits<Iterator>::value_type;

    Iterator it_pivot = begin + GetRandomValue(0, size);
    const Type kPivot = *it_pivot;
    Iterator left_ptr = begin;
    Iterator right_ptr = prev(end);

    while (left_ptr <= right_ptr) {
        while (*left_ptr < kPivot) {
            ++left_ptr;
        }
        while (*right_ptr > kPivot) {
            --right_ptr;
        }
        if (left_ptr <= right_ptr) {
            swap(*left_ptr, *right_ptr);
            // чтобы не выйти за пределы диапазона
            if (left_ptr != prev(end)) {
                ++left_ptr;
            }
            if (right_ptr != begin) {
                --right_ptr;
            }
        }
    }
    return left_ptr;
}

template <typename Iterator>
void QuickSort(Iterator begin, Iterator end) {
    const size_t kSizeRange = distance(begin, end);
    if (kSizeRange < 2) {
        return;
    }
    Iterator bound = FindBound(begin, end, kSizeRange);
    QuickSort(begin, bound); // [begin, bound)
    QuickSort(bound, end); // [bound, begin)
}

namespace tests {
    void TestQuickSort() {
        {
            vector<int> seq{2,1};
            const vector<int> kExpectedSeq{1,2};
            QuickSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{3,1,2};
            const vector<int> kExpectedSeq{1,2,3};
            QuickSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{3,9,7,8,10,27};
            const vector<int> kExpectedSeq{3,7,8,9,10,27};
            QuickSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{2,12,5,48,0,4};
            const vector<int> kExpectedSeq{0,2,4,5,12,48};
            QuickSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{13,17,37,73,31,19,23};
            const vector<int> kExpectedSeq{13,17,19,23,31,37,73};
            QuickSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{18,20,3,17};
            const vector<int> kExpectedSeq{3,17,18,20};
            QuickSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{1,11,1};
            const vector<int> kExpectedSeq{1,1,11};
            QuickSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{5};
            const vector<int> kExpectedSeq(seq);
            QuickSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq;
            QuickSort(seq.begin(), seq.end());
            assert(seq.empty());
        }{
            vector<int> seq{5,5,5,5,5,5,5,5,5};
            const vector<int> kExpectedSeq(seq);
            QuickSort(seq.begin(), seq.end());
            assert(seq == kExpectedSeq);
        }
        cerr << "TestQuickSort passed"s << endl;
    }
} // namespace tests


int main() {
    tests::TestQuickSort();
    int size = 0;
    cin >> size;
    vector<int> seq(size);
    for (int& element : seq) {
        cin >> element;
    }
    QuickSort(seq.begin(), seq.end());
    cout << seq << endl;
    return 0;
}
