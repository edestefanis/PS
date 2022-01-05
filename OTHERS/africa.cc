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

  string s; cin >> s;
  map<char, vector<int> > amap;
  amap['a'] = {2};
  amap['b'] = {2, 2};
  amap['c'] = {2, 2, 2};
  amap['d'] = {3};
  amap['e'] = {3, 3};
  amap['f'] = {3, 3, 3};
  amap['g'] = {4};
  amap['h'] = {4, 4};
  amap['i'] = {4, 4, 4};
  amap['j'] = {5};
  amap['k'] = {5, 5};
  amap['l'] = {5, 5, 5};
  amap['m'] = {6};
  amap['n'] = {6, 6};
  amap['o'] = {6, 6, 6};
  amap['p'] = {7};
  amap['q'] = {7, 7};
  amap['r'] = {7, 7, 7};
  amap['s'] = {7, 7, 7, 7};
  amap['t'] = {8};
  amap['u'] = {8, 8};
  amap['v'] = {8, 8, 8};
  amap['w'] = {8, 8, 8, 8};
  amap['x'] = {9};
  amap['y'] = {9, 9};
  amap['z'] = {9, 9, 9};
  for (char c : s) {
    for (int i = 0; i < amap[c].size(); ++i) cout << amap[c][i];
  }
  cout << endl;
  return 0;
}
