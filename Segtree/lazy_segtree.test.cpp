#define PROBLEM "https://atcoder.jp/contests/abc346/tasks/abc346_g"

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/mm/cf/dbg.h"
#else
#define dbg(...)
#define dbgarr(arr, n)
#endif

struct Mod {
    int added = 0;
};

struct Calc {
    int minn = 0;
    int mincnt = 1;
};

struct Segtree {
    int size;
    vector<Mod> mods;
    vector<Calc> calcs;
    Mod NEUTRAL_MOD = {0};
    // Should not affect the result when merging with another Calc
    Calc NEUTRAL_CALC = {numeric_limits<int>::max(), 0};

    Calc mod_op(const Calc& a, const Mod& b) {
        return {a.minn + b.added, a.mincnt};
    }

    // Merge two segments
    Calc calc_op(const Calc& a, const Calc& b) {
        if (a.minn == b.minn) {
            return {a.minn, a.mincnt + b.mincnt};
        }
        if (a.minn < b.minn) {
            return {a.minn, a.mincnt};
        }
        return {b.minn, b.mincnt};
    }

    void apply_mod_op(Calc& a, const Mod& b) { a = mod_op(a, b); }
    void apply_mod_op(Mod& a, const Mod& b) { a = {a.added + b.added}; }

    void build(int x, int lx, int rx, const vector<Calc>& a) {
        if (rx == lx + 1) {
            if (lx < (int)a.size()) calcs[x] = a[lx];
            return;
        }
        int m = midpoint(lx, rx);
        build(2 * x + 1, lx, m, a);
        build(2 * x + 2, m, rx, a);
        calcs[x] = calc_op(calcs[2 * x + 1], calcs[2 * x + 2]);
    }

    void init(int n, const vector<Calc>& a) {
        size = 1;
        while (size < n) size *= 2;
        mods.assign(2 * size, NEUTRAL_MOD);
        calcs.resize(2 * size);
        build(0, 0, size, a);
    }

    void modify(int l, int r, const Mod& v, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return;
        if (lx >= l && rx <= r) {
            apply_mod_op(mods[x], v);
            apply_mod_op(calcs[x], v);
            return;
        }
        int m = midpoint(lx, rx);
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        calcs[x] = calc_op(calcs[2 * x + 1], calcs[2 * x + 2]);
        apply_mod_op(calcs[x], mods[x]);
    }

    void modify(int l, int r, const Mod& v) { modify(l, r, v, 0, 0, size); }

    Calc calc(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return NEUTRAL_CALC;
        if (lx >= l && rx <= r) {
            return calcs[x];
        }
        int m = midpoint(lx, rx);
        auto m1 = calc(l, r, 2 * x + 1, lx, m);
        auto m2 = calc(l, r, 2 * x + 2, m, rx);
        auto res = calc_op(m1, m2);
        apply_mod_op(res, mods[x]);
        return res;
    }

    Calc calc(int l, int r) { return calc(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> left(n, 0);
    vector<int> right(n, n - 1);
    vector<int> last(n + 1, -1);
    for (int i = 0; i < n; i++) {
        left[i] = last[a[i]] + 1;
        last[a[i]] = i;
    }
    vector<int> tsal(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        right[i] = tsal[a[i]] - 1;
        tsal[a[i]] = i;
    }
    vector<vector<array<int, 2>>> start(n);
    vector<vector<array<int, 2>>> end(n);
    for (int i = 0; i < n; i++) {
        start[left[i]].push_back({i, right[i]});
        end[i].push_back({i, right[i]});
    }
    vector<Calc> c(n);
    Segtree segtree;
    segtree.init(n, c);
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        for (auto& st : start[i]) {
            segtree.modify(st[0], st[1] + 1, {1});
        }
        Calc cc = segtree.calc(0, n);
        if (cc.minn == 0)
            answer += n - cc.mincnt;
        else
            answer += n;
        for (auto& ed : end[i]) {
            segtree.modify(ed[0], ed[1] + 1, {-1});
        }
    }
    cout << answer << '\n';
    return 0;
}