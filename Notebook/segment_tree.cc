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

struct node{
  int on, area ;
  node() { }
  node(int x, int y) { on=x , area=y; }
};

int N;
int xsol = -1;
struct segmentTree {
  vector<node> vec;
  int off;
  segmentTree(int x) { off=1; while (off < x) off *=2; vec.resize(off*2 , node(0 ,0)); }
  int superficie() { return vec[1].area; }
  void add (int node, int begin, int end, int a, int b) {
    if (begin > b || end < a) return;
    if (begin <= a && b <= end) {
      if (!vec[node].on){
        vec[node].area = b-a+1;
      }
      vec[node].on++;
      if (vec[node].on >= N-1) {
        xsol = a;
      }
      cout << a << " " << b << "  " << vec[node].on << endl;
    } else {
      add(node*2, begin, end, a, (a+b) / 2);
      add(node*2+1, begin, end, (a+b)/2+1,b);
      if (!vec[node].on) vec[node].area = vec[2*node].area+vec[2*node + 1].area;
    }
  }
  void take(int node, int begin, int end, int a, int b) {
    if (begin > b || end < a ) return;
    if (begin <= a && b <= end) {
      vec[node].on--;
      if (!vec[node].on) {
        if (a!=b) vec[node].area = vec[node*2].area + vec[node*2 + 1].area;
        else vec[node].area = 0;
      }
    } else {
      take(node*2, begin, end, a, (a+b) / 2);
      take(node*2+1, begin, end, (a+b)/2+1, b);
      if (!vec[node].on) vec[node].area = vec[node*2].area + vec[node*2+ 1].area;
    }
  }
};

#define PII pair<int, int>

int main() {
  int i, j, k; segmentTree sTree (300001);
  scanf("%i", &N); int x1, y1, x2, y2;
  vector<pair<int, PII> > abre, cierra; int lastx=INT_MAX;
  for (i =0; i<N; i++) {
    scanf("%i %i %i %i", &x1, &y1, &x2, &y2); y2--;
    abre.push_back(make_pair(x1, make_pair(y1, y2))); cierra.push_back(make_pair(x2, make_pair(y1, y2)));
    lastx = min(x1, min(x2, lastx));
  }
  sort(abre.begin(), abre.end()); sort(cierra.begin(), cierra.end()); abre.push_back(make_pair(INT_MAX, PII(0, 0)));

  int ind1, ind2; ind1 = ind2 = 0 ;
  int res = 0;
  for (k=0; k<2*N; k++) {
    if (abre[ind1].first < cierra[ind2].first) {
      res += sTree.superficie() * (abre[ind1].first - lastx);
      lastx = abre[ind1].first;
      sTree.add(1, abre[ind1].second.first, abre[ind1].second.second, 0, sTree.off-1);
      if (xsol >= 0) {
        cout << xsol << " "  << lastx << endl;
        break;
      }
      ind1++;
    } else {
      res += sTree.superficie() * (cierra[ind2].first-lastx);
      lastx = cierra[ind2].first;
      sTree.take(1, cierra[ind2].second.first,
      cierra[ind2].second.second, 0, sTree.off-1);
      ind2++;
    }
  }
  return 0;
}
