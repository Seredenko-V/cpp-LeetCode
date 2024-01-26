#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Бронирование переговорки
// https://new.contest.yandex.ru/48557/problem?id=215/2023_04_06/RdGbbmsLQn
// Задано n интервалов. Требуется найти максимальное количество взаимно непересекающихся интервалов.
// Два интервала пересекаются, если они имеют хотя бы одну общую точку.

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
    sort(ranges.begin(), ranges.end());
    vector<pair<int, int>>::const_iterator last_unique = unique(ranges.begin(), ranges.end());
    ranges.erase(last_unique, ranges.cend());
    return ranges;
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
        vector<pair<int, int>> expected_ranges{{1, 3}, {2, 3}, {4, 5}};
        vector<pair<int, int>> ranges = ReadRanges(input);
        assert(expected_ranges == ranges);
        cerr << "TestReadRanges passed\n";
    }

    void RunAllTests() {
        TestReadRanges();
        cerr << "All tests passed\n"s;
    }
} // namespace tests



int main() {
    tests::RunAllTests();

    return 0;
}
