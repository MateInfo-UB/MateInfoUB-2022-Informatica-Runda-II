/**
 * Indended points: 100
 * Author: Theodor Moroianu
 */

#include <bits/stdc++.h>
using namespace std;

#define lsb(x) ((x) & -(x))

struct Aib
{
    vector <int> aib;
    int n;

    void update(int poz) {
        while (poz <= n)
            aib[poz]++, poz += lsb(poz);
    }

    int query(int poz) {
        int ans = 0;
        while (poz)
            ans += aib[poz], poz -= lsb(poz);
        return ans;
    }

    Aib(int n) : aib(n + 1), n(n) { }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> goes_to(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        goes_to[a].push_back(b);
    }

    Aib aib(n);

    long long intersections = 0, right_points = 0;
    for (int i = 1; i <= n; i++) {
        for (auto to : goes_to[i])
            intersections += right_points - aib.query(to);
        for (auto to : goes_to[i])
            right_points++, aib.update(to);
    }

    cout << intersections << '\n';
}
