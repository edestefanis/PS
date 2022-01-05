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


char s[100100];
int main() {
  cin >> s;
  int n = strlen(s);
  unsigned long long K = 2147483659LL;
  vector<pair<unsigned long long, int> > vec;
  for (int i = 0; i < n; ++i)
    vec.push_back(make_pair(0, i));
  map<unsigned long long, int> G;
  long long res = 0;
  while (vec.size()) {
    vector<pair<unsigned long long, int> > aux;
    aux = vec;
    vec.clear();
    for (int i = 0; i < aux.size(); ++i) {
      ///cout << aux[i].first << " " << aux[i].second << endl;
      if (aux[i].second == n) continue;
      unsigned long long roll = aux[i].first;
      if (roll && G[roll] == 1) {
        res += (n-aux[i].second);
        continue;
      }
      //cout << "hoalnda" << endl;
      roll = (roll * K) + s[aux[i].second];
      G[roll]++;
      vec.push_back(make_pair(roll, aux[i].second+1));
    }
  }
  res += G.size();
  cout << "holanda" << endl;
  cout << res << endl;
  return 0;
}
