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


int arr[5][5];
int row[5], col[5];
int N;
void PRINT(int r, int c) {
  printf("MAT: \n");
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int go3(int r, int c) {
//  if ( r == 4)
 // PRINT(r, c);
  if (r == 4) {
    if (c) {
      if (col[c-1] != 0) return 0;
    }
  }
  if (r == c or r+c == 4) return go3(r, c+1);
  if (c == 5) {
    if (row[r] != 0) return 0;
    if (r == 4) {
      return 1;
    }
    return go3(r+1, 0);
  }
  int res = 0;
  for (int i = 0; i <= min(3, min(row[r], col[c])); ++i) {
    row[r] -= i;
    col[c] -= i;
    arr[r][c] = i;
    res += go3(r, c+1);
    row[r] += i;
    col[c] += i;
  }
  return res;
}

int go2(int r, int cant) {
  if (cant < 0) return 0;
  if (r == 5 && cant) return 0;
  if (r == 5) return go3(0, 0);
  int res = 0;
  if (r == 2) {
    return go2(r+1, cant-arr[2][2]);
  }
  for (int i = 0; i <= min(cant, 3); ++i) {
    arr[r][4-r]  = i;
    row[r] -= i;
    col[4-r] -= i;
    res += go2(r+1, cant-i);
    row[r] += i;
    col[4-r] += i;
  }
  return res;
}

int go1(int r, int cant) {
  if (r == 5 && cant) return 0;
  if (r == 5) return go2(0, N);
  int res = 0;
  for (int i = 0; i <= min(cant, 3); ++i) {
    arr[r][r] = i;
    row[r] -= i;
    col[r] -= i;
    res += go1(r+1, cant-i);
    row[r] += i;
    col[r] += i;
  }
  return res;
}

int main() {
  int res = 0;
  for (int i = 0; i <= 15; ++i) {
    for (int j = 0; j < 5; ++j) row[j] = col[j] = i;
    N = i;
    res += go1(0, N);
  }
  cout << res << endl;
  return 0;
}
