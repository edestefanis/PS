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


long long get(string s, long long x, long long y) {
  bool isla = false;
  long long cant = 0;
  bool allone = true;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (!i && s[i] == '0') cant++;
    else if (i && s[i] == '0' && s[i-1] == '1') cant++;
  }
  long long res = 1e18;
  for (long long i = 0; i < cant; ++i) {
    res = min(res, (i * x) + (cant-i) * y);
  }
  if (cant == 0) res = 0;
  return res;
}

int main() {
  int n, x, y; cin >> n >> x >> y;
  string s;
  cin >> s;
  long long res = get(s, x, y);
  cout << res << endl;
  return 0;
}
