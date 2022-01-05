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


int main() {
  int n, m; cin >> m >> n;
  // Lets get the veracity of the elements in p.
  bool p[50]; memset(p, false, sizeof(p));
  for (int i = 0; i < n; ++i) {
      cout << m << endl << flush;
      int res; cin >> res;
      if (res == 0) return 0;
      if (res == -1) p[i] = true;
  }
  // Now lets perform a binary search.
  int beg = 0, end = m;
  int step = 0;
  while (beg + 1 < end) {
    int med = (beg+end)/2;
    cout << med << endl << flush;
    int res; cin >> res;
    if (res == -2) return 0;
    if (res == 0) return 0;
    if (res == 1 && !p[step%n]) end = med;
    else if (res == -1 && p[step%n]) end = med;
    else beg = med;
    step++;
  }
  return 0;
}
