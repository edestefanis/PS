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


long long get(long long n) {
  long long res = 0;
  set<int> R;
  set<int> mods;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 49; ++j) {
      for (int k = 0; k <= (n-i-j); ++k) {
        int val = (k + i * 5 + j * 10 + (n-i-j-k)* 50);
        mods.insert(val%49);
        R.insert(val);
      }
        long long cant = n - i - j;
        if (cant < 0) continue;
        res += cant + 1;
    }
  }
  return R.size();
}

int main() {
  long long n; cin >> n;
  if (n < 100) {
    cout << get(n) << endl;
  } else {
    cout << get(100) + (n-100) * 49LL << endl;
  }
  return 0;
}
