#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/mm/cf/dbg.h"
#else
#define dbg(...)
#define dbgarr(arr, n)
#endif

struct DSU {
    vector<int> p;
    vector<int> sz;
    // vector<int> mmax;

    void init(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        // mmax.assign(n, 0);
        sz.assign(n, 1);
    }

    int get(int a) { return p[a] = (p[a] == a ? a : get(p[a])); }

    void uni(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) return;
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        p[b] = a;
        sz[a] += sz[b];
        // mmax[a] = max(mmax[a], mmax[b]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    DSU dsu;
    dsu.init(n);
    while (q--) {
        int op;
        cin >> op;
        int u, v;
        cin >> u >> v;
        if (op == 0) {
            dsu.uni(u, v);
        } else {
            cout << (dsu.get(u) == dsu.get(v)) << '\n';
        }
    }
    return 0;
}