#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

// Слияние сортированных последовательностей
// https://new.contest.yandex.ru/48569/problem?id=215/2023_04_06/RRehKswGis
// Задано n отсортированных по неубыванию последовательностей.
// Требуется найти отсортированную по неубыванию конкатенацию этих последовательностей.

vector<int> MergePairSeq(const vector<int>& lhs, const vector<int>& rhs) {
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

vector<int> MergeAllSeq(const vector<vector<int>>& vec) {
    if (vec.size() <= 1) {
        return vec.front();
    }
    vector<vector<int>> new_vec(ceil(vec.size() / 2.0));
    size_t counter = 0;
    for (size_t i = 0; i < vec.size() - 1; i += 2) {
        new_vec[counter++] = MergePairSeq(vec[i], vec[i + 1]);
    }
    if (vec.size() % 2) {
        new_vec.back() = vec.back();
    }
    return MergeAllSeq(new_vec);
}

vector<vector<int>> ReadSequences(istream& in) {
    int num_sequences = 0;
    in >> num_sequences;
    if (num_sequences < 1 || num_sequences > 20) {
        return {};
    }
    vector<vector<int>> sequences(num_sequences);
    for (vector<int>& seq : sequences) {
        int size = 0;
        in >> size;
        if (size < 1 || size > 1e5) {
            return {};
        }
        seq.resize(size);
        for (int& element : seq) {
            in >> element;
        } 
        sort(seq.begin(), seq.end()); // т.к. в тестах платформы ошибка
    }
    return sequences;
}

namespace tests {
    void TestMergePairSeq() {
        {
            vector<int> expected_seq{1,1,2,2,3};
            assert(MergePairSeq({1,2,3}, {1,2}) == expected_seq);
        }{
            vector<int> expected_seq{1,1,2,3,3,5,6,7};
            assert(MergePairSeq({1,2,3}, {1,3,5,6,7}) == expected_seq);
        }{
            vector<int> expected_seq{1,1,1,1,1,1,1,1};
            assert(MergePairSeq({1,1,1}, {1,1,1,1,1}) == expected_seq);
        }
        cerr << "TestMergePairSeq passed"s << endl;
    }

    void TestMergeAllSeq() {
        {
            istringstream in{
                "3\n"
                "3\n"
                "1 2 3\n"
                "2\n"
                "1 2\n"
                "4\n"
                "3 5 6 7\n"
            };
            vector<int> expected{1,1,2,2,3,3,5,6,7};
            assert(MergeAllSeq(ReadSequences(in)) == expected);
        }{
            istringstream in{
                "2\n"
                "2\n"
                "1 10\n"
                "3\n"
                "7 9 11\n"
            };
            vector<int> expected{1,7,9,10,11};
            assert(MergeAllSeq(ReadSequences(in)) == expected);
        }{
            istringstream in{
                "2\n"
                "2\n"
                "1 1\n"
                "3\n"
                "1 1 1\n"
            };
            vector<int> expected{1,1,1,1,1};
            assert(MergeAllSeq(ReadSequences(in)) == expected);
        }{
            istringstream in{
                "7\n"
                "1\n"
                "1\n"
                "2\n"
                "2 3\n"
                "3\n"
                "4 5 6\n"
                "4\n"
                "7 8 9 10\n"
                "5\n"
                "11 12 13 14 15\n"
                "3\n"
                "4 5 6\n"
                "3\n"
                "4 5 6\n"
            };
            vector<int> expected{1,2,3,4,4,4,5,5,5,6,6,6,7,8,9,10,11,12,13,14,15};
            assert(MergeAllSeq(ReadSequences(in)) == expected);
        }
        cerr << "TestMergeAllSeq passed"s << endl;
    }

    void RunAllTests() {
        TestMergePairSeq();
        TestMergeAllSeq();
        cerr << ">>> AllTests passed <<<"s << endl;
    }
} // namespace tests



int main() {
    tests::RunAllTests();
    vector<vector<int>> sequences = ReadSequences(cin);
    vector<int> merged_sequences = MergeAllSeq(sequences);
    for (int element : merged_sequences) {
        cout << element << ' ';
    }
    cout << endl;
    return 0;
}
