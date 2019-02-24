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
#define PRINT(x) cout << #x ": " << (x) << endl;
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)
#define MAX_PRECISION cout << setprecision(numeric_limits<double>::max_digits10);

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 total = 1;
  i32 oldA = 0, oldB = 0;

  i32 n = 0;
  cin >> n;
  REP(i, 0, n) {
    i32 newA, newB;
    cin >> newA >> newB;

    if (oldA == oldB) {
      total += min(newA - oldA, newB - oldB);
    } else if (oldA > oldB) {
      if (newB >= oldA) {
        total += 1 + min(newA - oldA, newB - oldA);  // 1 comes from the "catch up".
      }
    } else {
      if (newA >= oldB) {
        total += 1 + min(newB - oldB, newA - oldB);
      }
    }

    oldA = newA;
    oldB = newB;
  }

  cout << total << endl;
}
