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


int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  if (!b) return a;
  return gcd(b, a%b);
}

int main() {
  int n, k;
  cin >> n >> k;
  set<int> todo;
  int g = 0;
  for (int i = 0; i < n; ++i) {
    int p; cin >> p;
    g = gcd(g, p%k);
  }
  int val = g;
  while (1) {
    if (todo.find(val) != todo.end()) {
      break;
    }
    todo.insert(val);
    val = (val + g) % k;
  }
  cout << todo.size() << endl;
  int first = true;
  for (auto it = todo.begin(); it != todo.end(); ++it) {
    if (!first) cout << " ";
    first = false;
    cout << *it;
  } cout << endl;

  return 0;
}
