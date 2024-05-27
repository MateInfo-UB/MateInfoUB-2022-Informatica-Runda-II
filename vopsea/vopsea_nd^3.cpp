#include <bits/stdc++.h>
using namespace std;

const int DMAX = 100;

bool dp[DMAX + 1][DMAX + 1][DMAX + 1];

int main()
{
    int N;
    cin >> N;

    vector <tuple <int, int, int>> v(N);

    int suma = 0, sumb = 0, sumc = 0;
    for (auto& [a, b, c] : v) {
        cin >> a >> b >> c;
        suma += a;
        sumb += b;
        sumc += c;
    }

    assert(suma <= DMAX && sumb <= DMAX && sumc <= DMAX);

    dp[0][0][0] = 1;

    for (auto [a, b, c] : v)
        for (int va = DMAX; va >= 0; va--)
            for (int vb = DMAX; vb >= 0; vb--)
                for (int vc = DMAX; vc >= 0; vc--)
                    if (dp[va][vb][vc]) // no need to check bounds because sum is at most DMAX
                        dp[va + a][vb + b][vc + c] = 1;

    int ans = 0;
    for (int i = 0; i <= DMAX; i++)
        if (dp[i][i][i])
            ans = 3 * i;

    cout << ans << '\n';

    return 0;
}