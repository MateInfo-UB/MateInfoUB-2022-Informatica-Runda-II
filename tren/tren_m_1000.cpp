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

    vector <pair <int, int>> edges(m);
    for (auto& [a, b] : edges)
        cin >> a >> b;        

    long long intersections = 0;

    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if ((edges[i].first < edges[j].first && edges[i].second > edges[j].second)
                    || (edges[i].first > edges[j].first && edges[i].second < edges[j].second))
                intersections++;

    cout << intersections << '\n';
}
