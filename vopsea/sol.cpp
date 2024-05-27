#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector <tuple <int, int, int>> v(N);
    for (auto& [a, b, c] : v)
        cin >> a >> b >> c;

    vector <tuple <int, int, int>> left(v.begin(), v.begin() + N / 2);
    vector <tuple <int, int, int>> right(v.begin() + N / 2, v.end());

    map <pair <int, int>, int> left_masks;
    left_masks[{ 0, 0 }] = 0;

    for (int mask = 0; mask < (1 << left.size()); mask++) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < (int)left.size(); i++) {
            if (mask & (1 << i)) {
                a += get<0>(left[i]);
                b += get<1>(left[i]);
                c += get<2>(left[i]);
            }
        }
        int suma = a + b + c;
        b -= a, c -= a;
        left_masks[{ b, c }] = max(left_masks[{ b, c }], suma);
    }

    int ans = 0;

    for (int mask = 0; mask < (1 << right.size()); mask++) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < (int)right.size(); i++) {
            if (mask & (1 << i)) {
                a += get<0>(right[i]);
                b += get<1>(right[i]);
                c += get<2>(right[i]);
            }
        }

        int suma = a + b + c;
        b -= a, c -= a;
        if (left_masks.count({ -b, -c })) {
            int act = suma + left_masks[{ -b, -c }];
            ans = max(ans, act);
        }
    }

    cout << ans << '\n';

    return 0;
}