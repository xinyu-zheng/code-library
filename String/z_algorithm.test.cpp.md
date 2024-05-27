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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ String/z_algorithm.test.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#ifdef LOCAL\n#include \"/home/mm/cf/dbg.h\"\
    \n#else\n#define dbg(...)\n#define dbgarr(arr, n)\n#endif\n\nvector<int> z_function(string&\
    \ s) {\n    int n = s.size();\n    vector<int> z(n);\n    int l = 0, r = 0;\n\
    \    for (int i = 1; i < n; i++) {\n        if (i < r) {\n            z[i] = min(r\
    \ - i, z[i - l]);\n        }\n        while (i + z[i] < n && s[z[i]] == s[i +\
    \ z[i]]) {\n            z[i]++;\n        }\n        if (i + z[i] > r) {\n    \
    \        l = i;\n            r = i + z[i];\n        }\n    }\n    z[0] = n;\n\
    \    return z;\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    string s;\n    cin >> s;\n    int n = (int)s.size();\n    vector<int> z =\
    \ z_function(s);\n    for (int i = 0; i < n; i++) {\n        cout << z[i];\n \
    \       if (i != n - 1) cout << ' ';\n    }\n    cout << '\\n';\n    return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: String/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2024-02-19 22:41:13+11:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: String/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/String/z_algorithm.test.cpp
- /verify/String/z_algorithm.test.cpp.html
title: String/z_algorithm.test.cpp
---
