#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// A+B строки.
// https://new.contest.yandex.ru/42492/problem?id=6789665/2023_04_06/GWcZqPTpiJ

// Вычислить "кривую" сумму двух строк A и B одинаковой длины.
// "Кривой" суммой двух строк называется операция следующего вида:
// C = A + B = A1B1A2B2...AnBn


istream& ReadString(istream& in, string& str) {
    for (char& symbol : str) {
        in >> symbol;
    }
    return in;
}

string SumCurve(const string& lhs, const string& rhs) {
    if (lhs.size() != rhs.size()) {
        return {};
    }
    string result_sum(lhs.size() * 2, '#');
    // можно ввести дополнительную переменную внутри цикла, чтобы не умножать i
    for (size_t i = 0; i < lhs.size(); ++i) {
        result_sum[i * 2] = lhs[i];
        result_sum[i * 2 + 1] = rhs[i];
    }
    return result_sum;
}


namespace tests {
    void TestSumCurve() {
        {
            const string kLhs = "abc"s;
            const string kRhs = "def"s;
            const string kExpected = "adbecf"s;
            assert(kExpected == SumCurve(kLhs, kRhs));
        }{
            const string kLhs = "abaca"s;
            const string kRhs = "bdaef"s;
            const string kExpected = "abbdaaceaf"s;
            assert(kExpected == SumCurve(kLhs, kRhs));
        }{
            const string kLhs = "y"s;
            const string kRhs = "z"s;
            const string kExpected = "yz"s;
            assert(kExpected == SumCurve(kLhs, kRhs));
        }{ // разные размеры
            const string kLhs = "yfasgfag"s;
            const string kRhs = "z"s;
            assert(SumCurve(kLhs, kRhs).empty());
        }{ // пустые строки
            const string kLhs;
            const string kRhs;
            assert(SumCurve(kLhs, kRhs).empty());
        }
        cerr << "TestSumCurve passed"s << endl;
    }
} // namespace tests


int main() {
    tests::TestSumCurve();
    int size = 0;
    cin >> size;
    string A(size, '#');
    string B(size, '#');
    ReadString(cin, A);
    ReadString(cin, B);
    cout << SumCurve(A, B) << endl;
    return 0;
}
