/**
 * Intended points: 60
 * Author: Theodor Moroianu
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <int> get_into(n + 1);
    vector <vector <int>> goes_to(n + 1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        goes_to[a].push_back(b);
    }

    long long intersections = 0;
    for (int i = 1; i <= n; i++) {
        auto& to = goes_to[i];
        sort(to.rbegin(), to.rend());
        
        // nr of intersections so far, pointer for counting sums
        int intersect_now = 0, last = n;

        // compute intersections
        for (auto x : to) {
            while (last > x)
                intersect_now += get_into[last], last--;
            intersections += intersect_now;
        }
        
        // mark intersections
        for (auto x : to)
            get_into[x]++;
    }

    cout << intersections << '\n';
}
