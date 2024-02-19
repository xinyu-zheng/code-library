#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/mm/cf/dbg.h"
#else
#define dbg(...)
#define dbgarr(arr, n)
#endif

vector<int> z_function(string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    z[0] = n;
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> z = z_function(s);
    for (int i = 0; i < n; i++) {
        cout << z[i];
        if (i != n - 1) cout << ' ';
    }
    cout << '\n';
    return 0;
}