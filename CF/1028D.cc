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

#define MOD 1000000007LL

int main() {
  int N; cin >> N;
  set<int> buy, sell, unknown;
  long long res = 1;
  for (int i = 0; i < N; ++i) {
    string s; int k;
    cin >> s >> k;
    if (s == "ADD") {
      if (buy.size()) {
        if (k < *(buy.rbegin())) {
          buy.insert(k);
          continue;
        }
      }
      if (sell.size()) {
        if (k > *(sell.begin())) {
          sell.insert(k);
          continue;
        }
      }
      unknown.insert(k);
    } else {
      if (buy.size()) {
        if (k < *(buy.rbegin())) {
          res = 0; break;
        } else if (k == *(buy.rbegin())) {
          buy.erase(k);
          continue;
        }
      }
      if (sell.size()) {
        if (k > *(sell.begin())) {
          res = 0; break;
        } else if (k == *(sell.begin())) {
          sell.erase(k);
          continue;
        }
      }
      for (int v : unknown) {
        if (v < k) buy.insert(v);
        if (v > k) sell.insert(v);
      }
      res = (res * 2) % MOD;
      unknown.clear();
    }
  }
  long long si = unknown.size();
  res = (res * (si+1)) % MOD;

  cout << res << endl;
  return 0;
}
