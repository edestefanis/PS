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

vector<int> edges[201010];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int a, b; cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int parent[201010], children[201010];
  memset(children, 0, sizeof(children));
  parent[1] = 0;
  children[0] = 1;
  bool mark[201010]; memset(mark, false, sizeof(mark));
  queue<int> Q; Q.push(1); mark[1] = true;
  set<int> sons[201010];
  while (!Q.empty()) {
    int node = Q.front(); Q.pop();
    for (int i = 0 ; i < edges[node].size(); ++i) {
      int son = edges[node][i];
      if (mark[son]) continue;
      mark[son] = true;
      parent[son] = node;
      children[node] ++;
      sons[node].insert(son);
      Q.push(son);
      //cout << node << "  " << son << endl;
    }
  }

   

  if (yes) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
