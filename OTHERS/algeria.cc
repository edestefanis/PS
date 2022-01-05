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


long double dp2[50000][1001];
bool done2[50000][1001];
long double go2(int turnos, int heads) {
  long double& res = dp2[turnos][heads];
  if (done2[turnos][heads]) return res;
  done2[turnos][heads] = true;
  //cout << turnos << " " << heads << endl;
  if (heads == 0) {
    if (turnos == 0) return res = 1.;
    return res = 0.;
  }
  if (turnos == 0) {
   return res = 0.;
  }
  res = 0.;
  for (int k = 2; k < 2049; k *= 2) {
    long double p = 1. / (long double) k;
    res = max( res, go2(turnos-1, heads) * (1.-p) + go2(turnos-1,  max(0, heads-k/2)) * p);
  }
  return res;
}

long double dp[50000][1001];
bool done[50000][1001];
long double go(int turnos, int heads) {
  long double& res = dp[turnos][heads];
  if (done[turnos][heads]) return res;
  done[turnos][heads] = true;
  //cout << turnos << " " << heads << endl;
  if (heads == 0) {
    return res = pow(0.5, turnos);
  }
  if (turnos == 0) {
   return res = 1.;
  }
  res = go(turnos-1, heads) * 0.5  + go(turnos-1,  heads-1) * 0.5;

//  cout << res << "  " << turnos << " " << heads << endl;
  return res;

}


int main() {
  memset(dp, -1, sizeof(dp));
  memset(done, false, sizeof(done));
  memset(dp2, -1, sizeof(dp2));
  memset(done2, false, sizeof(done2));

  long double res = 0.;

  for (int turnos = 1; turnos < 1000; ++turnos) {
    long double mip = go2(turnos, 1000);
    long double anap = go(turnos, 999);
    mip *= anap;
    res += mip;
    printf("%.20Lf  %d\n", res, turnos);
  }
  printf("  %.8Lf\n",res);
  return 0;
}
