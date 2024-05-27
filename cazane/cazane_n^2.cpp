#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector <int> cazane(N);

    for (auto& i : cazane)
        cin >> i;

    sort(cazane.rbegin(), cazane.rend());

    for (auto i : cazane)
        assert(i >= 0 && i <= 1000);
    
    int last = 0;
    while (M--) {
        int act;
        cin >> act;
        act += last;
        last = act;
        
        int ans = 0;
        while (act > 0)
            act -= cazane[ans], ans++;

        cout << ans << ' ';
        
    }
    return 0;
}