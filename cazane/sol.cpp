#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector <int> cazane(N);

    for (auto& i : cazane) {
        cin >> i;
        assert(i >= 1 && i <= 1000);
    }

    sort(cazane.rbegin(), cazane.rend());

    for (auto i : cazane)
        assert(i >= 1 && i <= 1000);
    
    int poz = 0, folosit = 0;

    while (M--) {
        int act;
        cin >> act;
        folosit += act;
        while (poz < N && folosit > cazane[poz]) {
            folosit -= cazane[poz];
            poz++;
        }

        assert(poz < N);
        cout << poz + 1 << ' ';
    }
    return 0;
}