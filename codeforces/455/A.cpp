#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;
typedef deque<i32> di32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front
#define TR(c, it) for (auto (it) = (c).begin(); (it) != (c).end(); (it)++)

i64 dp[(i32)1e5 + 1];

i32 main() {
  ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 t; cin >> t;
  unordered_map<i32, i64> nMap;
  REP(i, 0, t) {
    i32 num; cin >> num;
    nMap[num] += num;
  }

  dp[0] = 0; dp[1] = nMap[1];
  REP(i, 2, (i32)1e5 + 1) {
    dp[i] = max(dp[i - 1], nMap[i] + dp[i - 2]);
  }
  cout << dp[(i32)1e5] << endl;
}
