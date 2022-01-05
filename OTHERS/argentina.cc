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


LL MOD = 123456789;

class Mat {
public:
  Mat() {
     mat[0][0] = 0, mat[0][1] = 1, mat[1][0] = 2, mat[1][1] = 1;
  }

  void Mult(const Mat& m) {
    LL aux[2][2];
    aux[0][0] = (mat[0][0] * m.mat[0][0] + mat[0][1] * m.mat[1][0]) % MOD;
    aux[0][1] = (mat[0][0] * m.mat[0][1] + mat[0][1] * m.mat[1][1]) %MOD;
    aux[1][0] = (mat[1][0] * m.mat[0][0] + mat[1][1] * m.mat[1][0]) % MOD;
    aux[1][1] = (mat[1][0] * m.mat[0][1] + mat[1][1] * m.mat[1][1]) % MOD;
    for (int  i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) mat[i][j] = aux[i][j];
  }

  LL mat[2][2];
};

Mat A;

Mat Elevar(LL N, Mat m) {
  if (N == 0) {
    Mat I; memset(I.mat, 0, sizeof(I.mat));
    I.mat[0][0] = I.mat[1][1] = 1;
    return I;
  }
  if (N == 1) {
    Mat m; return m;
  }
  Mat e = Elevar(N/2, m);
  e.Mult(e);
  if (N&1) {
    e.Mult(A);
  }
  return e;
}

void print (Mat m) {
  for (int i = 0; i < 2; ++i)  {
    for (int j = 0; j < 2; ++j) {
      printf("%lld ", m.mat[i][j]);
    }
    printf("\n");
  }
}
int main() {
  Mat m;
  m = Elevar(234612846789230LL, m);
  print(m);
  cout << m.mat[0][1] << endl;
  return 0;
}
