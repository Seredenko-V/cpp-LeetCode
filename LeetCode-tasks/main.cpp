#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdint>

using namespace std;

// Камни
// https://new.contest.yandex.ru/48558/problem?id=215/2023_04_06/lX20wNIqZg
// Вы играете в игру <<Камни>>: игру для двух игроков с двумя наборами камней по n и m штук.
// С каждым ходом один игрок может взять один камень (из любого набора) или два камня (по одному из обоих).
// Когда камень забрали, он выходит из игры. Побеждает игрок, который заберет последний камень. Первый ход за вами.
// Вы и ваш оппонент играете оптимально.

bool IsWinRocks(int n, int m) {
    if (n < 1 || n > 10) {
        return false;
    }
    if (m < 1 || m > 10) {
        return false;
    }
    return n % 2 || m % 2;
}

void Test() {
    assert(!IsWinRocks(10, 2));
    assert(!IsWinRocks(6, 8));
    assert(IsWinRocks(4, 5));
    assert(IsWinRocks(3, 9));
    cerr << "Test passed\n";
}

int main() {
    Test();
    int n, m;
    cin >> n >> m;
    cout << (IsWinRocks(n, m) ? "Win" : "Loose") << endl;
    return 0;
}
