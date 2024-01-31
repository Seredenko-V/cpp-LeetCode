#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdint>

using namespace std;

// Бронирование переговорки
// https://new.contest.yandex.ru/48557/problem?id=215/2023_04_06/RdGbbmsLQn
// Задано n интервалов. Требуется найти максимальное количество взаимно непересекающихся интервалов.
// Два интервала пересекаются, если они имеют хотя бы одну общую точку.

// ================================= АЛГОРИТМ РЕШЕНИЯ =================================
// 1) Считываем все диапазоны в вектор, т.к. количество диапазонов известно заранее.
// 2) Сортируем диапазоны по времени завершения отрезка, удаляем дубликаты.
// 3) Ищем первый диапазон, время начала которого меньше, чем время завершения текущего диапазона.
//    Используется алгоритм двух указателей.

vector<pair<int, int>> ReadRanges(istream& in) {
    int num_ranges = 0;
    in >> num_ranges;
    vector<pair<int, int>> ranges(num_ranges);
    for (int i = 0; i < num_ranges; ++i) {
        in >> ranges[i].first >> ranges[i].second;
        if (ranges[i].first < 1 || ranges[i].first > ranges[i].second || ranges[i].second > 50) {
            return {};
        }
    }
    return ranges;
}

void PrepareRanges(vector<pair<int, int>>& ranges) {
    // сортировка по времени завершения отрезка (по возрастанию)
    sort(ranges.begin(), ranges.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second < rhs.second;
    });
    vector<pair<int, int>>::const_iterator last_unique = unique(ranges.begin(), ranges.end());
    ranges.erase(last_unique, ranges.cend());
}

uint32_t GetCountDisjointRanges(const vector<pair<int, int>>& ranges) {
    uint32_t num_disjoint_ranges = 1;
    uint32_t current_range = 0;
    for (size_t i = 1; i < ranges.size(); ++i) {
        // ищем первый диапазон, время начала которого меньше, чем время завершения текущего диапазона
        if (ranges[current_range].second < ranges[i].first) {
            ++num_disjoint_ranges;
            current_range = i;
        }
    }
    return num_disjoint_ranges;
}

namespace tests {
    void TestReadRanges() {
        istringstream input{
            "5\n"
            "1 3\n"
            "1 3\n"
            "2 3\n"
            "4 5\n"
            "4 5\n"
        };
        vector<pair<int, int>> expected_ranges{{1, 3}, {1, 3}, {2, 3}, {4, 5}, {4, 5}};
        vector<pair<int, int>> ranges = ReadRanges(input);
        assert(expected_ranges == ranges);
        cerr << "TestReadRanges passed\n";
    }

    void TestPrepareRanges() {
        {
            vector<pair<int, int>> expected_ranges{{1, 3}, {2, 3}, {4, 5}};
            vector<pair<int, int>> ranges = expected_ranges;
            PrepareRanges(ranges);
            assert(ranges == expected_ranges);
        }{
            vector<pair<int, int>> expected_ranges{{1, 3}, {2, 3}, {4, 5}};
            vector<pair<int, int>> ranges{{1, 3}, {1, 3}, {2, 3}, {4, 5}, {4, 5}};
            PrepareRanges(ranges);
            assert(ranges == expected_ranges);
        }{
            vector<pair<int, int>> expected_ranges{{1, 2}, {1, 3}, {4, 5}, {3, 7}, {6, 9}};
            vector<pair<int, int>> ranges{{1, 3}, {1, 2}, {3, 7}, {4, 5}, {6, 9}};
            PrepareRanges(ranges);
            assert(ranges == expected_ranges);
        }
        cerr << "TestPrepareRanges passed\n";
    }

    void TestsGetCountDisjointRanges() {
        {
            vector<pair<int, int>> ranges{{1, 3}, {2, 3}, {4, 5}};
            PrepareRanges(ranges);
            assert(GetCountDisjointRanges(ranges) == 2u);
        }{
            vector<pair<int, int>> ranges{{1, 2}, {2, 3}, {4, 5}, {4, 5}, {5, 6}};
            PrepareRanges(ranges);
            assert(GetCountDisjointRanges(ranges) == 2u);
        }{
            vector<pair<int, int>> ranges{{1, 50}, {49, 50}};
            PrepareRanges(ranges);
            assert(GetCountDisjointRanges(ranges) == 1u);
        }
        cerr << "TestsGetCountDisjointRanges passed\n";
    }

    void RunAllTests() {
        TestReadRanges();
        TestPrepareRanges();
        TestsGetCountDisjointRanges();
        cerr << "All tests passed\n"s;
    }
} // namespace tests


int main() {
    tests::RunAllTests();
    vector<pair<int, int>> ranges = ReadRanges(cin);
    PrepareRanges(ranges);
    cout << GetCountDisjointRanges(ranges) << endl;
    return 0;
}
