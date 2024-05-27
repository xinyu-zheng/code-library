---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ DSU/dsu.test.cpp: line 7: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#ifdef LOCAL\n#include \"/home/mm/cf/dbg.h\"\
    \n#else\n#define dbg(...)\n#define dbgarr(arr, n)\n#endif\n\nstruct DSU {\n  \
    \  vector<int> p;\n    vector<int> sz;\n    // vector<int> mmax;\n\n    void init(int\
    \ n) {\n        p.resize(n);\n        iota(p.begin(), p.end(), 0);\n        //\
    \ mmax.assign(n, 0);\n        sz.assign(n, 1);\n    }\n\n    int get(int a) {\
    \ return p[a] = (p[a] == a ? a : get(p[a])); }\n\n    void uni(int a, int b) {\n\
    \        a = get(a);\n        b = get(b);\n        if (a == b) return;\n     \
    \   if (sz[a] < sz[b]) {\n            swap(a, b);\n        }\n        p[b] = a;\n\
    \        sz[a] += sz[b];\n        // mmax[a] = max(mmax[a], mmax[b]);\n    }\n\
    };\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int n, q;\n    cin >> n >> q;\n    DSU dsu;\n    dsu.init(n);\n    while\
    \ (q--) {\n        int op;\n        cin >> op;\n        int u, v;\n        cin\
    \ >> u >> v;\n        if (op == 0) {\n            dsu.uni(u, v);\n        } else\
    \ {\n            cout << (dsu.get(u) == dsu.get(v)) << '\\n';\n        }\n   \
    \ }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: DSU/dsu.test.cpp
  requiredBy: []
  timestamp: '2024-05-27 10:21:49+10:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DSU/dsu.test.cpp
layout: document
redirect_from:
- /verify/DSU/dsu.test.cpp
- /verify/DSU/dsu.test.cpp.html
title: DSU/dsu.test.cpp
---
