#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector <int> cazane(N);

    for (auto& i : cazane)
        cin >> i;

    int last = 0;
    while (M--) {
        int act;
        cin >> act;
        last += act;

        cout << (last + cazane[0] - 1) / cazane[0] << ' ';
    }
    return 0;
}