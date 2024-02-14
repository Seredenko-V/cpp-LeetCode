#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Быстрая сортировка.
// https://new.contest.yandex.ru/48570/problem?id=215/2023_04_06/qQS9a7rB0y

// Опорный элемент всегда последний. Решение не проходит по скорости

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (int element : vec) {
        out << element << ' ';
    }
    return out;
}

template <typename Iterator>
void QuickSort(Iterator begin, Iterator end) {
    using Type = typename iterator_traits<Iterator>::value_type;
    const size_t kSizeRange = distance(begin, end);
    if (kSizeRange < 2) {
        return;
    }

    Iterator it_pivot = prev(end);
    const Type kPivot = *it_pivot;
    Iterator it = begin;
    while (it != prev(it_pivot)) {
        if (*it > kPivot) {
            swap(*it_pivot, *prev(it_pivot));
            swap(*it, *(it_pivot--));
        } else {
            ++it;
        }
    }
    // чтобы не менять дважды местами одни и те же числа
    if (*it > kPivot) {
        swap(*it, *(it_pivot--));
    }
    QuickSort(begin, it_pivot);
    QuickSort(next(it_pivot), end);
}

namespace tests {
    void TestQuickSort() {
        {
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
    ctime(NULL);
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
