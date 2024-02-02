#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// Камни 2
// https://new.contest.yandex.ru/48558/problem?id=215/2023_04_06/HFqqJtCCRh
// Вы играете в игру <<Камни>>: игру для двух игроков с двумя наборами камней по n и m штук.
// С каждым ходом один игрок может забрать следующие комбинации камней:

// 1) Взять один камень из любого набора.
// 2) Взять два камня из какого-то одного набора
// 3) Взять два камня из одного и один из другого.

// Когда камень забрали, он выходит из игры. Побеждает игрок, который заберет последний камень. Первый ход за вами.
// Вы и ваш оппонент играете оптимально.

bool IsWinRocks(int n, int m) {
    if (n < 1 || n > 1000) {
        return false;
    }
    if (m < 1 || m > 1000) {
        return false;
    }
    return abs(n - m) % 3;
}

namespace tests {
    void RunAllTest() {
        assert(!IsWinRocks(4, 4));
        assert(IsWinRocks(7, 5));
        assert(IsWinRocks(17, 72));
        cerr << "All tests passed\n";
    }
} // namespace tests



int main() {
    tests::RunAllTest();
    int n, m;
    cin >> n >> m;
    cout << (IsWinRocks(n, m) ? "Win" : "Loose") << endl;
    return 0;
}
