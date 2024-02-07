#include <iostream>
#include <vector>

using namespace std;

// Ханойские башни 2
// https://new.contest.yandex.ru/48568/problem?id=215/2023_04_06/NQ3L2sn9W8
// Теперь головоломка состоит из четырех стержней, а цель головоломки — перенести все диски со стержня 1 на стержень 4.
// Найдите минимальное количество ходов, за которое можно решить головоломку.

// ======================================== АЛГОРИТМ РЕШЕНИЯ ========================================
// В решении нужно правильно вычислять количество дисков, которое будет перекладываться в рамках 3-х стержней (1 буферный).
// Оно определяется как "количество дисков / количество стержней + 1".
// Такой подход позволит перекладывать большую часть дисков, используя 2 буферных стержня, что сократит количество операций.

void SolveThreeHanoiTowers(int num_disk, int from, int to, int buf, int& count) {
    if (num_disk < 1) {
        return;
    }
    if (num_disk == 1) {
        ++count;
        return;
    }
    SolveThreeHanoiTowers(num_disk - 1, from, buf, to, count);
    SolveThreeHanoiTowers(1, from, to, buf, count);
    SolveThreeHanoiTowers(num_disk - 1, buf, to, from, count);
}

void SolveFourHanoiTowers(int num_disk, int from, int to, int first_buf, int second_buf, int& count) {
    if (num_disk < 1) {
        return;
    }
    if (num_disk == 1) {
        ++count;
        return;
    }
    static int constexpr kNumKernel = 4;
    int num_disks_in_second_part = num_disk / kNumKernel + 1;
    int num_disks_in_first_part = num_disk - num_disks_in_second_part - 1;
    SolveFourHanoiTowers(num_disks_in_first_part, from, first_buf, second_buf, to, count);
    SolveThreeHanoiTowers(num_disks_in_second_part, from, second_buf, to, count);
    // для перемещения одного диска буфферы могут быть любыми, т.к. они не будут использоваться
    SolveFourHanoiTowers(1, from, to, second_buf, first_buf, count);
    SolveThreeHanoiTowers(num_disks_in_second_part, second_buf, to, first_buf, count);
    SolveFourHanoiTowers(num_disks_in_first_part, first_buf, to, second_buf, from, count);
}

void Test() {
    vector<int> expected_answers{0,1,3,5,9,13,17,25,33,41,49,65,81,97,113};
    for (size_t i = 0; i < expected_answers.size(); ++i) {
        int count = 0;
        SolveFourHanoiTowers(i, 1, 4, 2, 3, count);
        if (expected_answers[i] != count) {
            cerr << count << " != "s << expected_answers[i] << '\t';
        } else {
            cerr << count << " == "s << expected_answers[i] << '\t';
        }
        cerr << i << " disks\n";
    }
    cerr << "Test passed\n"s;
}

int main() {
    Test();
    int num_disk = 0;
    cin >> num_disk;
    if (num_disk < 3 || num_disk > 10) {
        return 0;
    }
    int count = 0;
    SolveFourHanoiTowers(num_disk, 1, 4, 2, 3, count);
    cout << count << endl;
    return 0;
}
