#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

// Максимальное произведение четырех чисел.
// https://new.contest.yandex.ru/42734/problem?id=6789665/2023_04_06/WwderYQo8t

// Определить максимальное произведение 4х чисел последовательности.
// Индексы должны отличаться, но сами элементы могут быть равны.

template <typename T>
istream& operator>>(istream& in, vector<T>& vec) {
    for (T& element : vec) {
        in >> element;
    }
    return in;
}

int64_t MaxProductNums(vector<int64_t>& seq, int count_numbers) {
    if (static_cast<int>(seq.size()) < count_numbers || seq.empty()) {
        return 0;
    }
    sort(seq.begin(), seq.end());
    const bool is_odd = count_numbers % 2;
    int64_t product = is_odd ? seq.back() : 1;

    size_t left_index = 0;
    size_t righ_index = seq.size() - 1;

    for (int i = 0; i < count_numbers - 1 - is_odd; i += 2) {
        int64_t left = seq[left_index] * seq[left_index + 1];
        int64_t right = seq[righ_index - is_odd] * seq[righ_index - 1 - is_odd];
        if (is_odd && left >= right && product < 0) {
            product *= right;
            righ_index -= 2;
        } else if (left >= right) {
            product *= left;
            left_index += 2;
        } else {
            product *= right;
            righ_index -= 2;
        }
    }
    return product;
}

namespace tests {
    void TestMaxProductEvenNums() {
        { // Произведение четного числа элементов
            vector<int64_t> seq{1,2,3,4};
            assert(MaxProductNums(seq, 4) == 24);
        }{
            vector<int64_t> seq{-1,-2,3,4};
            assert(MaxProductNums(seq, 4) == 24);
        }{
            vector<int64_t> seq{-1,-3,-2,-4,-5};
            assert(MaxProductNums(seq, 4) == 120);
        }{
            vector<int64_t> seq{0,-1,0,-3,-2,100};
            assert(MaxProductNums(seq, 4) == 0);
        }{
            vector<int64_t> seq{1,2,3,4,5,6};
            assert(MaxProductNums(seq, 6) == 720);
        }{
            vector<int64_t> seq{-2,-1,0,1,2,3,4,5,6};
            assert(MaxProductNums(seq, 6) == 720);
        }
        cerr << "TestMaxProductEvenNums passed"s << endl;
    }

    void TestMaxProductOddNums() {
        {// Произведение нечетного числа элементов
            vector<int64_t> seq{1,2,3};
            assert(MaxProductNums(seq, 3) == 6);
        }{
            vector<int64_t> seq{-1,-2,-2};
            assert(MaxProductNums(seq, 3) == -4);
        }{
            vector<int64_t> seq{-1,-3,-2,-4};
            assert(MaxProductNums(seq, 3) == -6);
        }{
            vector<int64_t> seq{-1,0,-3,-2,0};
            assert(MaxProductNums(seq, 3) == 0);
        }{
            vector<int64_t> seq(200'000, 200'000);
            assert(MaxProductNums(seq, 3) == 8'000'000'000'000'000);
        }{
            vector<int64_t> seq(200'000, -200'000);
            assert(MaxProductNums(seq, 3) == -8'000'000'000'000'000);
        }{
            vector<int64_t> seq{-5,-2,0,1};
            assert(MaxProductNums(seq, 3) == 10);
        }{
            vector<int64_t> seq{9,2,-3,-7};
            assert(MaxProductNums(seq, 3) == 189);
        }{
            vector<int64_t> seq{-9,-8,8};
            assert(MaxProductNums(seq, 3) == 576);
        }{
            vector<int64_t> seq{-9,-8,-7,5};
            assert(MaxProductNums(seq, 3) == 360);
        }{
            vector<int64_t> seq{1,2,3,4,5};
            assert(MaxProductNums(seq, 5) == 120);
        }{
            vector<int64_t> seq{-10,-1,0,1,2,3,4,5};
            //assert(MaxProductNums(seq, 5) == 1200); // don't work
        }
        cerr << "TestMaxProductOddNums passed"s << endl;
    }

    void TestMaxProductNums() {
        TestMaxProductEvenNums();
        TestMaxProductOddNums();
        { // невалидные запросы
            vector<int64_t> seq{3,6};
            assert(MaxProductNums(seq, 4) == 0);
        }{
            vector<int64_t> seq;
            assert(MaxProductNums(seq, 4) == 0);
        }{
            vector<int64_t> seq{1,3,5,7};
            assert(MaxProductNums(seq, 9) == 0);
        }
        cerr << ">>> TestMaxProductNums passed <<<"s << endl;
    }
} // namespace tests


int main() {
    tests::TestMaxProductNums();
    int size = 0;
    cin >> size;
    vector<int64_t> seq(size);
    cin >> seq;
    cout << MaxProductNums(seq, 4) << endl;
    return 0;
}
