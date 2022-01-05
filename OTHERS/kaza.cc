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


int Val(int c) {
  return c;
}

int main() {
  string s;
  cin >> s;
  cout << s.size() << endl;

  // buscamos el menor lexicografico...
  s = s + s;
  int n = 1000000;
  vector<int> vec;
  for (int i = 0; i < n; ++i) vec.push_back(i);

  for (int j = 0; j < n; ++j) {
    if (vec.size() == 1) break;
    set<int> S;
    for (int i = 0; i < vec.size(); ++i) S.insert(s[vec[i]+j]);
    vector<int> aux = vec;
    vec.clear();
    for (int i = 0; i < aux.size(); ++i) if (s[aux[i]+j] == *S.begin()) vec.push_back(aux[i]);
  }
  cout << vec[0] << " " << vec[0] + 500000 << endl;
  string p = s.substr(vec[0]+500000, 2976) ;
  cout << p.size() << endl;
  cout << p << endl;
  return 0;
}
