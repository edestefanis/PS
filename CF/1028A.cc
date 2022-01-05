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

  int rows, cols; cin >> rows >> cols;
  vector<string> board;
  for (int i = 0; i < rows; ++i) {
    string s; cin >> s; board.push_back(s);
  }

  int mat[200][200];
  memset(mat, 0, sizeof(mat));
  int mx = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (i && j) {
        mat[i][j] = min(mat[i-1][j], mat[i][j-1]);
      }
      if (board[i][j] == 'B') mat[i][j]++;
      else mat[i][j] = 0;
      mx = max(mat[i][j], mx);
    }
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (mat[i][j] == (mx+1)/2) {
        cout << i+1 <<  " " << j+1 << endl;
        i = rows, j = cols;
      }
    }
  }
  return 0;
}
