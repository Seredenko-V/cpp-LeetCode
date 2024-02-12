#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Сортировка выбором
// https://new.contest.yandex.ru/48569/problem?id=215/2023_04_06/08fmDTMXQZ

// =============================== АЛГОРИТМ РЕШЕНИЯ ================================
// N/2 раз ищем минимальный элемент в последовательности и ставим его на i-ю позицию

template <typename Type>
void SelectionSort(vector<Type>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        size_t min_pos = i;
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[min_pos] > vec[j]) {
                min_pos = j;
            }
        }
        swap(vec[i], vec[min_pos]);
    }
}

void Test() {
    {
        vector<int> sequence{13, 17, 37, 73, 31, 19, 23};
        vector<int> expected_sequence{13, 17, 19, 23, 31, 37, 73};
        SelectionSort(sequence);
        assert(sequence == expected_sequence);
    }{
        vector<int> sequence{12, 18, 7, 11, 5, 17};
        vector<int> expected_sequence{5, 7, 11, 12, 17, 18};
        SelectionSort(sequence);
        assert(sequence == expected_sequence);
    }{
        vector<int> sequence{1, 2, 3};
        vector<int> expected_sequence = sequence;
        SelectionSort(sequence);
        assert(sequence == expected_sequence);
    }{
        vector<int> sequence{8};
        vector<int> expected_sequence = sequence;
        SelectionSort(sequence);
        assert(sequence == expected_sequence);
    }
    cerr << "Test passed\n"s;
}

int main() {
    Test();
    int size = 0;
    cin >> size;
    vector<int> sequence(size);
    for (int& element : sequence) {
        cin >> element;
    }
    SelectionSort(sequence);
    for (int element : sequence) {
        cout << element << ' ';
    }
    cout << endl;
    return 0;
}
