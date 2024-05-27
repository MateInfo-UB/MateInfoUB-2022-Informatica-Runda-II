/**
 * Intended points: 20
 * Author: Theodor Moroianu
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> adj(n + 1, vector <int> (n + 1));

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a][b]++;
    }

    long long intersections = 0;

    for (int a1 = 1; a1 <= n; a1++)
        for (int a2 = a1 + 1; a2 <= n; a2++)
            for (int b1 = 1; b1 <= n; b1++)
                for (int b2 = 1; b2 < b1; b2++)
                    intersections += 1LL * adj[a1][b1] * adj[a2][b2];
    
    cout << intersections << '\n';
}
