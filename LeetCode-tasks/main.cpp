#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>

using namespace std;

// Слияние сортированных последовательностей
// https://new.contest.yandex.ru/48569/problem?id=215/2023_04_06/RRehKswGis
// Задано n отсортированных по неубыванию последовательностей.
// Требуется найти отсортированную по неубыванию конкатенацию этих последовательностей.

// =============================== АЛГОРИТМ РЕШЕНИЯ ================================

vector<int> Merge(const vector<vector<int>>& vec) {

}

vector<vector<int>> ReadSequences(istream& in) {
    int num_sequences = 0;
    in >> num_sequences;
    vector<vector<int>> sequences(num_sequences);
    for (vector<int>& seq : sequences) {
        int size = 0;
        in >> size;
        seq.resize(size);
        for (int& element : seq) {
            in >> element;
        }
    }
    return sequences;
}

void Test() {
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
        assert(Merge(ReadSequences(in)) == expected);
    }{
        istringstream in{
            "2\n"
            "2\n"
            "1 10\n"
            "3\n"
            "7 9 11\n"
        };
        vector<int> expected{1,7,9,10,11};
        assert(Merge(ReadSequences(in)) == expected);
    }
    cerr << "Test passed\n"s;
}

int main() {
    Test();
    vector<vector<int>> sequences = ReadSequences(cin);
    vector<int> merged_sequences = Merge(sequences);
    for (int element : merged_sequences) {
        cout << element << ' ';
    }
    cout << endl;
    return 0;
}
