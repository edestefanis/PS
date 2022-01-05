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
  int n, s;
  vector<int> a;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    int b; cin >> b; a.push_back(b);
  }
  sort(a.begin(), a.end());
  LL res = 0;
  if (a[n/2] > s) {
    int pivot = a[n/2];
    for (int i = n/2; i >= 0; --i) {
      if (pivot >= a[i] && a[i] > s) {
        res += a[i]-s;
      }
    }
  } else {
    int pivot = a[n/2];
    for (int i = n/2; i < n; ++i) {
      if (pivot <= a[i] && a[i] < s) {
        res += s - a[i];
      }
    }
  }
  cout << res << endl;
  return 0;
}
