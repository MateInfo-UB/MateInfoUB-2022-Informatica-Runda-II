#include <bits/stdc++.h>
using namespace std;

const int VMAX = 300'000;
mt19937 rnd;


void Subtask(int N, int M)
{
    uniform_int_distribution<int> distr(1, N);
    set <pair <int, int>> generated;

    cout << N << ' ' << M << '\n';
    for (int i = 0; i < M; i++) {
        int a = distr(rnd), b = distr(rnd);
        if (generated.count({ a, b })) {
            i--;
            continue;
        }
        generated.insert({ a, b });
        cout << a << ' ' << b << '\n';
    }
}

int main(int argc, char** argv)
{
    int test = stoi(argv[1]);
    int N = stoi(argv[2]);
    int M = stoi(argv[3]);

    rnd = mt19937(test);

    Subtask(N, M);
}