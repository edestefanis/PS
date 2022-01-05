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

long long MOD = 1000000007LL;

long long F[1001];
long long f(int n) {
  if (n < 0) return 0;
  if (n <= 1) return 1;
  if (F[n] >= 0) return F[n];
  F[n] = (f(n-1) + f(n-2) + f(n-3) + f(n-4)) % MOD;
  return F[n];
}


long long E[1001][1001];

long long elev(long long v, long long exp) {
  //cout << "holanda" << endl;
  if (exp == 0) return 1;
  if (exp == 1) return v;
  //cout << v << "  " << exp << endl;
  long long res = elev(v, exp/2);
  res = (res * res) % MOD;
  if (exp&1) res = (res * v) % MOD;
  return res;
}

long long DP[1001][1001];

long long go(int n, int m) {
  long long& res = DP[n][m];
  if (res >= 0) return res;
  if (m == 0) {
    res = 0;
    return res;
  }
  if (m == 1) {
    res = 1;
    return res;
  }

  //cout << n << " " << m  << endl;

  res = 1;
  res = (res * elev(f(m), n)) % MOD;
  //cout << "holanda" << endl;
  //cout << n << " " << m  << endl;
  for (int j = 1; j < m; ++j) res = (res-(go(n, j) * elev(f(m-j), n))) % MOD;
  res = (res+MOD)%MOD;
  return res;
}
int main() {
  memset(F, -1, sizeof(F));
  memset(DP, -1, sizeof(DP));
  memset(E, -1, sizeof(E));
  int casos ; cin >> casos;
  for (int i = 0; i < casos; ++i) {
    int n, m; cin >> n >> m;
  //  cout << " Caso " << n << " " << m << endl;
    /*
    long long G[1001];
    G[0] = 0;
    G[1] = 1;
    cout << " Caso " << n << " " << m << endl;
    for (int len = 2; len <= m; ++len) {
      cout << len << endl;
      G[len] = 1;
      for (int j = 0; j < n; ++j) G[len] = (G[len] * f(len)) % MOD;
      //cout << len << "     " << G[len] << endl;
      for (int j = 1; j < len; ++j) G[len] = (G[len]-(G[j] * elev(f(len-j), n))) % MOD;
      G[len] = (G[len]+MOD)%MOD;
      //cout << len << "  " << G[len] << endl;
    }
    cout << G[m] << endl ;
    */
    cout << go(n, m);
  }
  cout << endl;
  return 0;
}
