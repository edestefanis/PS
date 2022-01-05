#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
#include <climits>
#include <numeric>
#include <valarray>
#include <complex>
#include <memory.h>
using namespace std;

const int dr[]={0,-1,0,1,-1,1, 1,-1};
const int dc[]={1,0,-1,0, 1,1,-1,-1};
const double eps=1e-9;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef pair<double, double> PDD;
typedef vector<PDD> VPDD;
typedef vector<vector<pair<int, long long> > > Graph;



bool tratar(int v, vector<PII> v1, vector<PII> v2) {
  set<int> s1, s2;
  for (auto p : v1) {
    s1.insert(p.first), s1.insert(p.second);
  }
  for (auto p : v2) {
    s2.insert(p.first), s2.insert(p.second);
  }
  if (s1.find(v) == s1.end()) return false;
  if (s2.find(v) == s2.end()) return false;

  // lets count the pairs on the left...
  bool pos = false;
  for (auto p : v1) {
    int other = -1;
    if (p.first == v) other = p.second;
    else if (p.second == v) other = p.first;
    if (other == -1) continue;
    for (auto p2 : v2) {
      int other2 = -1;
      if (other == p2.first) other2 = p2.second;
      else if (other == p2.second) other2 = p2.first;
      if (other2 == -1) continue;
      if (other2 != v) return false;
    }
    int cnt = 0;
    for (auto p2 : v2) {
      int other2 = -1;
      if (v == p2.first) other2 = p2.second;
      else if (v == p2.second) other2 = p2.first;
      if (other2 == -1) continue;
      if (other2 != other) cnt++;
    }
    if (cnt > 0) pos = true;
  }
  if (!pos) return false;
  pos = false;

  for (auto p : v2) {
    int other = -1;
    if (p.first == v) other = p.second;
    else if (p.second == v) other = p.first;
    if (other == -1) continue;
    for (auto p2 : v1) {
      int other2 = -1;
      if (other == p2.first) other2 = p2.second;
      else if (other == p2.second) other2 = p2.first;
      if (other2 == -1) continue;
      if (other2 != v) return false;
    }
    int cnt = 0;
    for (auto p2 : v1) {
      int other2 = -1;
      if (v == p2.first) other2 = p2.second;
      else if (v == p2.second) other2 = p2.first;
      if (other2 == -1) continue;
      if (other2 != other) cnt++;
    }
    if (cnt > 0) pos = true;
  }
  if (!pos) return false;
  return true;
}

set<int> Calc(vector<PII> v1, vector<PII> v2, set<int> possible, bool& certain) {
  set<int> left, right;
  for (auto p: v1) {
    int value = -1;
    for (auto p2: v2) {
      if (p == p2) continue;
      if (p.first == p2.first || p.first == p2.second) {
        if (possible.find(p.first) == possible.end()) continue;
        if (value == -1) {
          value = p.first;
        } else if (value == p.second) {
          value = 0; break;
        }
      } else if (p.second == p2.first || p.second == p2.second) {
        if (possible.find(p.second) == possible.end()) continue;
        if (value == -1) {
          value = p.second;
        } else if (value == p.first) {
          value = 0; break;
        }
      }
    }
    if (value != -1) {
      left.insert(value);
    }
    if (value == 0) certain = false;
  }
  for (auto p: v2) {
    int value = -1;
    for (auto p2: v1) {
      if (p == p2) continue;
      if (p.first == p2.first || p.first == p2.second) {
        if (possible.find(p.first) == possible.end()) continue;
        if (value == -1) {
          value = p.first;
        } else if (value == p.second) {
          value = 0; break;
        }
      } else if (p.second == p2.first || p.second == p2.second) {
        if (possible.find(p.second) == possible.end()) continue;
        if (value == -1) {
          value = p.second;
        } else if (value == p.first) {
          value = 0; break;
        }
      }
    }
    if (value != -1) {
      right.insert(value);
    }
    if (value == 0) certain = false;
  }

  set<int> res;
  auto it = set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter( res, res.begin() ));
  return res;
}

int main() {
  vector<PII> v1, v2;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int a, b; cin >> a >> b;
    if (b < a) swap(a,b);
   v1.push_back(make_pair(a, b));
  }
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    if (b < a) swap(a,b);
     v2.push_back(make_pair(a, b));
  }
  set<int> res;
  for (int i = 1 ; i < 10; ++i) res.insert(i);
  bool certain = true;
  for (int i = 0; i < 1; ++i) {
    res = Calc(v1, v2, res, certain);
  }

  if (res.size() == 0 || !certain) {
    cout << -1 << endl;
  } else if (res.size() == 1) {
    cout << *res.begin() << endl;
  } else cout << 0 << endl;
 return 0;
 /*
  int res = -1;
  set<int> pos;
  for (int p = 1; p <= 9; ++p) {
    if (tratar(p, v1, v2)) {
      pos.insert(p);
      //cout << p << endl;
    }
  }
  if (pos.size() > 1) {
    cout << 0 << endl;
  } else if (pos.size() == 1) {
    cout << *pos.begin() << endl;
  } else cout << -1 << endl;
  return 0;
  */
}
