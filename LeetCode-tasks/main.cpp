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

ostream& operator<<(ostream& out, const vector<vector<bool>>& vec) {
    for (const vector<bool>& str : vec) {
        for (bool elem : str) {
            cout << elem << ' ';
        }
        cout << endl;
    }
    cout << "=========================\n";
    return out;
}

vector<vector<bool>> CreateMatrix(int n, int m) {
    vector<vector<bool>> matrix(n, vector<bool>(m, true));
    for (int i = 0; i < n; i += 3) {
        matrix[i][0] = false;
    }
    for (int j = 0; j < m; j += 3) {
        matrix[0][j] = false;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (matrix[i - 1][j] && matrix[i][j - 1] && matrix[i - 1][j - 1]) {
                matrix[i][j] = false;
            }
        }
    }
    return matrix;
}

bool IsWinRocks(int n, int m) {
    if (n < 1 || n > 1000) {
        return false;
    }
    if (m < 1 || m > 1000) {
        return false;
    }
    vector<vector<bool>> matrix = CreateMatrix(n, m);
    return matrix.back().back();
}

namespace tests {
    void TestCreateMatrix() {
        {
            vector<vector<bool>> expected_matrix{
                {0, 1},
                {1, 1}
            };
            vector<vector<bool>> matrix = CreateMatrix(2, 2);
            assert(expected_matrix == matrix);
        }{
            vector<vector<bool>> expected_matrix{
                {0, 1, 1},
                {1, 1, 0},
                {1, 0, 1},
            };
            vector<vector<bool>> matrix = CreateMatrix(3, 3);
            assert(expected_matrix == matrix);
        }
        cerr << "TestCreateMatrix passed\n";
    }

    void RunAllTest() {
        TestCreateMatrix();
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
