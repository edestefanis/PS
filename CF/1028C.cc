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


class Rectangle {
public:
    Rectangle() {}
    Rectangle(int x1_, int y1_, int x2_, int y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_) {}
    void ReadRectangle() {
      cin >> x1 >> y1 >> x2 >> y2;
    }
    Rectangle Union(const Rectangle& rect) {
      return Rectangle(max(x1, rect.x1), max(y1, rect.y1),
                       min(x2, rect.x2), min(y2, rect.y2));
    }
    bool Valid() {
      return x1 <= x2 && y1 <= y2;
    }
    int x1, y1, x2, y2;
};
Rectangle rects[200000], L[200000], R[200000];
int main() {
  int N; cin >> N;
  for (int i = 0; i < N; ++i) {
    rects[i].ReadRectangle();
  }
  L[0] = rects[0]; R[N-1] = rects[N-1];
  for (int i = 1; i < N; ++i) {
    L[i] = rects[i].Union(L[i-1]);
  }
  for (int i = N-2; i >= 0; --i) {
    R[i] = rects[i].Union(R[i+1]);
  }
  if (R[1].Valid()) {
    Rectangle aux = R[1];
    cout << aux.x1 << " " << aux.y1 << endl;
    return 0;
  }
  if (L[N-2].Valid()) {
    Rectangle aux = L[N-2];
    cout << aux.x1 << " " << aux.y1 << endl;
    return 0;
  }
  for (int i = 1 ; i + 1 < N; ++i) {
    Rectangle aux = L[i-1].Union(R[i+1]);
    if (aux.Valid()) {
      cout << aux.x1 << " " << aux.y1 << endl;
      return 0;
    }
  }
  return 0;
}
