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

class Square {
public:
  Square() {}
  void Read() {
    int x, y;
    for (int i = 0; i < 4; ++i) {
      cin >> x >> y;
      points.push_back(make_pair(x, y));
    }
  }

  // This is actually twice the area, but since the division is distributive for our case, we are ok.
  int TArea(PII p1, PII p2, PII p3) {
    return abs((p3.first - p1.first) * (p2.second-p1.second) - (p3.second - p1.second) * (p2.first-p1.first));
  }

  bool TContains(PII p1, PII p2, PII p3, PII o) {
    //if (o != make_pair(6,6)) return false;
    //cout << p1.first << " " << p1.second << "  " << p2.first << " " << p2.second << " " << p3.first << " " << p3.second << " " << o.first << " " << o.second << endl;
    //cout << TArea(p1, p2, p3) << "  " << TArea(p1, p2, o) << "  " <<   TArea(p1, p3, o) << "  " << TArea(p2, p3, o) << endl;
    if (TArea(p1, p2, p3) == TArea(p1, p2, o) + TArea(p1, p3, o) + TArea(p2, p3, o)) return true;
    return false;
  }

  bool Contains(const vector<pair<int,int> >& p) {
      for (pair<int, int> point : p) {
        int i = 0;
        for (int j = 1; j < 4; ++j) {
          for (int k = j+1; k < 4; ++k) {
            if (TContains(points[i], points[k], points[j], point)) return true;
          }
        }
      }
      return false;
  }

  vector<pair<int, int> > Points() {
    auto p = points;
    int x, y; x = y = 0;
    for (auto p : points) {
        x += p.first, y += p.second;
    }
    x/=4, y/=4;
    p.push_back(make_pair(x, y));
    return p;
  }

  vector<pair<int,int> > points;
};

int main() {
  Square A, B;
  A.Read(), B.Read();
  if (A.Contains(B.Points()) || B.Contains(A.Points())) {
    cout << "YES" << endl;
  } else cout << "NO" << endl;
  return 0;
}
