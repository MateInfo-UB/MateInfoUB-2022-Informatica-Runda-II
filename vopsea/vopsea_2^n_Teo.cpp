#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector <tuple <int, int, int>> v(N);
    for (auto& [a, b, c] : v)
        cin >> a >> b >> c;

    int ans = 0;

    for (int mask = 0; mask < (1 << N); mask++) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                a += get<0>(v[i]);
                b += get<1>(v[i]);
                c += get<2>(v[i]);
            }
        }

        if (a == b && b == c)
            ans = max(ans, a + b + c);
    }

    cout << ans << '\n';

    return 0;
}