#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>

using namespace std;

// Сортировка слиянием
// https://new.contest.yandex.ru/48569/problem?id=215/2023_04_06/xwt1i1wLpb

vector<int> Merge(const vector<int>& lhs, const vector<int>& rhs) {
    vector<int> result_seq(lhs.size() + rhs.size());
    size_t counter_lhs = 0;
    size_t counter_rhs = 0;
    while (counter_lhs != lhs.size() && counter_rhs != rhs.size()) {
        if (lhs[counter_lhs] < rhs[counter_rhs]) {
            result_seq[counter_lhs + counter_rhs] = lhs[counter_lhs];
            ++counter_lhs;
        } else {
            result_seq[counter_lhs + counter_rhs] = rhs[counter_rhs];
            ++counter_rhs;
        }
    }
    while (counter_lhs != lhs.size()) {
        result_seq[counter_lhs + counter_rhs] = lhs[counter_lhs];
        ++counter_lhs;
    }
    while (counter_rhs != rhs.size()) {
        result_seq[counter_lhs + counter_rhs] = rhs[counter_rhs];
        ++counter_rhs;
    }
    return result_seq;
}

void MergeSort(vector<int>& seq) {
    if (seq.size() < 2) {
        return;
    }
    vector<int> lhs(seq.size() / 2);
    vector<int> rhs(seq.size() / 2 + seq.size() % 2);
    copy(seq.begin(), seq.begin() + lhs.size(), lhs.begin());
    copy(seq.begin() + lhs.size(), seq.end(), rhs.begin());
    MergeSort(lhs);
    MergeSort(rhs);
    seq = Merge(lhs, rhs);
}

vector<int> ReadSequence(istream& in) {
    int size = 0;
    in >> size;
    if (size < 1 || size > 1e5) {
        return {};
    }
    vector<int> sequence(size);
    for (int& element : sequence) {
        in >> element;
        if (element < 0 || element > 1e9) {
            return {};
        }
    }
    return sequence;
}

namespace tests {
    void TestMergeSort() {
        {
            vector<int> seq{13,17,37,73,31,19,23};
            const vector<int> kExpectedSeq{13,17,19,23,31,37,73};
            MergeSort(seq);
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{18,20,3,17};
            const vector<int> kExpectedSeq{3,17,18,20};
            MergeSort(seq);
            assert(seq == kExpectedSeq);
        }{
            vector<int> seq{0,11,0};
            const vector<int> kExpectedSeq{0,0,11};
            MergeSort(seq);
            assert(seq == kExpectedSeq);
        }
        cerr << "TestMergeSort passed"s << endl;
    }
} // namespace tests



int main() {
    tests::TestMergeSort();
    vector<int> seq = ReadSequence(cin);
    MergeSort(seq);
    for (int element : seq) {
        cout << element << ' ';
    }
    cout << endl;
    return 0;
}
