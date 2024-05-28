---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc346/tasks/abc346_g
    links:
    - https://atcoder.jp/contests/abc346/tasks/abc346_g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Segtree/lazy_segtree.test.cpp: line 7: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc346/tasks/abc346_g\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#ifdef LOCAL\n#include \"/home/mm/cf/dbg.h\"\
    \n#else\n#define dbg(...)\n#define dbgarr(arr, n)\n#endif\n\nstruct Mod {\n  \
    \  int added = 0;\n\n    bool operator==(const Mod&) const = default;\n};\n\n\
    struct Calc {\n    int minn = 0;\n    int mincnt = 1;\n};\n\nstruct Segtree {\n\
    \    int size;\n    vector<Mod> mods;\n    vector<Calc> calcs;\n    // Should\
    \ not affect the result when merging with another Calc\n    Mod NEUTRAL_MOD =\
    \ {0};\n    // Should not affect the result when merging with another Calc\n \
    \   Calc NEUTRAL_CALC = {numeric_limits<int>::max(), 0};\n\n    Calc mod_op(const\
    \ Calc& a, const Mod& b) {\n        return {a.minn + b.added, a.mincnt};\n   \
    \ }\n\n    // Merge two segments\n    Calc calc_op(const Calc& a, const Calc&\
    \ b) {\n        if (a.minn == b.minn) {\n            return {a.minn, a.mincnt\
    \ + b.mincnt};\n        }\n        if (a.minn < b.minn) {\n            return\
    \ {a.minn, a.mincnt};\n        }\n        return {b.minn, b.mincnt};\n    }\n\n\
    \    void apply_mod_op(Calc& a, const Mod& b) { a = mod_op(a, b); }\n    void\
    \ apply_mod_op(Mod& a, const Mod& b) { a = {a.added + b.added}; }\n\n    void\
    \ build(int x, int lx, int rx, const vector<Calc>& a) {\n        if (rx == lx\
    \ + 1) {\n            if (lx < (int)a.size()) calcs[x] = a[lx];\n            return;\n\
    \        }\n        int m = midpoint(lx, rx);\n        build(2 * x + 1, lx, m,\
    \ a);\n        build(2 * x + 2, m, rx, a);\n        calcs[x] = calc_op(calcs[2\
    \ * x + 1], calcs[2 * x + 2]);\n    }\n\n    void init(int n, const vector<Calc>&\
    \ a) {\n        size = 1;\n        while (size < n) size *= 2;\n        mods.assign(2\
    \ * size, NEUTRAL_MOD);\n        calcs.resize(2 * size);\n        build(0, 0,\
    \ size, a);\n    }\n\n    void modify(int l, int r, const Mod& v, int x, int lx,\
    \ int rx) {\n        if (r <= lx || l >= rx) return;\n        if (lx >= l && rx\
    \ <= r) {\n            apply_mod_op(mods[x], v);\n            apply_mod_op(calcs[x],\
    \ v);\n            return;\n        }\n        int m = midpoint(lx, rx);\n   \
    \     modify(l, r, v, 2 * x + 1, lx, m);\n        modify(l, r, v, 2 * x + 2, m,\
    \ rx);\n        calcs[x] = calc_op(calcs[2 * x + 1], calcs[2 * x + 2]);\n    \
    \    apply_mod_op(calcs[x], mods[x]);\n    }\n\n    void modify(int l, int r,\
    \ const Mod& v) { modify(l, r, v, 0, 0, size); }\n\n    Calc calc(int l, int r,\
    \ int x, int lx, int rx) {\n        if (r <= lx || l >= rx) return NEUTRAL_CALC;\n\
    \        if (lx >= l && rx <= r) {\n            return calcs[x];\n        }\n\
    \        int m = midpoint(lx, rx);\n        auto m1 = calc(l, r, 2 * x + 1, lx,\
    \ m);\n        auto m2 = calc(l, r, 2 * x + 2, m, rx);\n        auto res = calc_op(m1,\
    \ m2);\n        apply_mod_op(res, mods[x]);\n        return res;\n    }\n\n  \
    \  Calc calc(int l, int r) { return calc(l, r, 0, 0, size); }\n};\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int n;\n   \
    \ cin >> n;\n    vector<int> a(n);\n    for (int i = 0; i < n; i++) {\n      \
    \  cin >> a[i];\n    }\n    vector<int> left(n, 0);\n    vector<int> right(n,\
    \ n - 1);\n    vector<int> last(n + 1, -1);\n    for (int i = 0; i < n; i++) {\n\
    \        left[i] = last[a[i]] + 1;\n        last[a[i]] = i;\n    }\n    vector<int>\
    \ tsal(n + 1, n);\n    for (int i = n - 1; i >= 0; i--) {\n        right[i] =\
    \ tsal[a[i]] - 1;\n        tsal[a[i]] = i;\n    }\n    vector<vector<array<int,\
    \ 2>>> start(n);\n    vector<vector<array<int, 2>>> end(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        start[left[i]].push_back({i, right[i]});\n       \
    \ end[i].push_back({i, right[i]});\n    }\n    vector<Calc> c(n);\n    Segtree\
    \ segtree;\n    segtree.init(n, c);\n    long long answer = 0;\n    for (int i\
    \ = 0; i < n; i++) {\n        for (auto& st : start[i]) {\n            segtree.modify(st[0],\
    \ st[1] + 1, {1});\n        }\n        Calc cc = segtree.calc(0, n);\n       \
    \ if (cc.minn == 0)\n            answer += n - cc.mincnt;\n        else\n    \
    \        answer += n;\n        for (auto& ed : end[i]) {\n            segtree.modify(ed[0],\
    \ ed[1] + 1, {-1});\n        }\n    }\n    cout << answer << '\\n';\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: Segtree/lazy_segtree.test.cpp
  requiredBy: []
  timestamp: '2024-05-28 19:39:34+10:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Segtree/lazy_segtree.test.cpp
layout: document
redirect_from:
- /verify/Segtree/lazy_segtree.test.cpp
- /verify/Segtree/lazy_segtree.test.cpp.html
title: Segtree/lazy_segtree.test.cpp
---
