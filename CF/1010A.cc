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
  int n; long double m;
  cin >> n >> m;
  vector<long double> a, b;
  for (int i = 0; i < n; ++i) {
    double p; cin >> p; a.push_back(p);
  }
  for (int i = 0; i < n; ++i) {
    double p; cin >> p; b.push_back(p);
  }

  long double beg = 0., end = 1e9+1;
  for (int t = 0; t < 500 && (end-beg) > 1e-13; ++t) {
      long double fuel = (beg+end)/2.;
      long double weight = fuel + m;
      // Calculate the trip...
      for (int i = 0; i < n; ++i) {
        weight -= (weight / a[i]);
        weight -= (weight / b[i]);
      }
      if (weight + 1e-9 >= m ) end = (beg+end)/2.;
      else beg = (beg+end)/2.;
  }
  if (beg > 1e9) printf("-1\n");
  else
  printf("%.9Lf\n", end);
  return 0;
}
