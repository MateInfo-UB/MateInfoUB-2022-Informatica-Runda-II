#include <bits/stdc++.h>
using namespace std;

const int VMAX = 1000000;
mt19937 rnd;

/**
 * Sparge (suma, suma, suma) in N sume
 */ 
vector <int> Partition(int suma, int N)
{
    vector <int> v(N);
    int suma_init = suma;
    string s = string(suma, '0') + string(N - 1, '1');
    shuffle(s.begin(), s.end(), rnd);
    s.push_back('1');
    //cerr << "S = " << s << '\n';
    auto act = s.begin();
    for (int i = 0; i < N; i++) {
        auto nxt = find(act, s.end(), '1');
        int dist = nxt - act;
        assert(act != s.end());
        assert(dist >= 0);
        act = next(nxt);
        v[i] = dist;
        if (dist > 1'000'000) {
            cerr << "Forced to call again!\n";
            return Partition(suma, N);
        }
    }
    return v;
}

int Sol(vector <vector <int>> w)
{
    int N = w.size();
    vector <tuple <int, int, int>> v;
    for (auto i : w)
        v.push_back({ i[0], i[1], i[2] });

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
    return ans;
}

int main(int argc, char** argv)
{
    int test = stoi(argv[1]);
    int N = stoi(argv[2]);
    int suma = stoi(argv[3]);
    int answer = stoi(argv[4]);

    rnd = mt19937(test);

    assert(answer <= suma);


    while (1) {
        cerr << "ITERATION\n";
        vector<vector<int>> v(N, vector<int>(3));
        int sa = answer + rnd() % (suma - answer + 1);
        int sb = answer + rnd() % (suma - answer + 1);
        int sc = answer + rnd() % (suma - answer + 1);
        int K = rnd() % (N - 1) + 1;

        if (sa <= answer + 8 || sb <= answer + 8 || sc <= answer + 8)
            continue;
        
        // Build answer part
        {
            auto a = Partition(answer, K);
            auto b = Partition(answer, K);
            auto c = Partition(answer, K);
            for (int i = 0; i < K; ++i) {
                v[i][0] = a[i];
                v[i][1] = b[i];
                v[i][2] = c[i];
            }
        }
        // Build non answer part 
        {
            auto a = Partition(sa - answer, N - K);
            auto b = Partition(sb - answer, N - K);
            auto c = Partition(sc - answer, N - K);
            for (int i = 0; i < N - K; ++i) {
                v[i + K][0] = a[i];
                v[i + K][1] = b[i];
                v[i + K][2] = c[i];
            }
        }

        int actual = Sol(v) / 3;

        if (actual == answer) {
            shuffle(v.begin(), v.end(), rnd);
    
            cout << N << endl;
            for (int i = 0; i < N; ++i) {
                cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << '\n';
            }

            return 0;
        }

        cerr << "answer = " << answer << " actual = " << actual << endl;
    }
}