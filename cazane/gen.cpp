#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    int test = stoi(argv[1]);
    int N = stoi(argv[2]);
    int M = stoi(argv[3]);
    int a_constant = stoi(argv[4]);
    int a_max = stoi(argv[5]);

    vector <int> a(N), p(M);
    mt19937 rnd(test);

    int dif = 0;

    for (auto& i : a) {
        i = (a_constant ? a_constant : rnd() % a_max + 1);
        dif += i;
    }

    for (auto& i : p) {
        i = rnd() % 1000 + 1;
        dif -= i;
    }

    while (dif < 0) {
        int x = rnd() % N;
        if (p[x] > 1)
            p[x]--, dif++;
    }

    cout << N << ' ' << M << '\n';
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
    for (auto i : p)
        cout << i << ' ';
    cout << '\n';
    return 0;
}