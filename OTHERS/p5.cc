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


set<int> edges[201010];

int n, m, k;
set<pair<int, int> > S;
int val[201010];

set<pair<int, int> > deleted;
void DeleteEdge(int node, int neigh) {
  pair<int,int> n(node, neigh);
  if (deleted.find(n) != deleted.end()) return;
  deleted.insert(n);

  pair<int,int> p = make_pair(val[node], node);
  if (S.find(p) != S.end()) {
    S.erase(p);
    val[node]--;
    S.insert(make_pair(val[node], node));
  }
  edges[node].erase(neigh);
}

void Reduce() {
  if (S.empty()) return;
  while (!S.empty() && S.begin()->first < k) {
    pair<int,int> p = *(S.begin()); S.erase(S.begin());

    set<int> neighs = edges[p.second];
    for (int neigh : neighs) {
      DeleteEdge(p.second, neigh);
      DeleteEdge(neigh, p.second);
    }
  }
}

int main() {
  cin >> n >> m >> k;
  vector<pair<int,int> > E;
  for (int i = 0; i < m ; ++i) {
    int a, b; cin >> a >> b;
    edges[a].insert(b);
    edges[b].insert(a);
    E.push_back(make_pair(a,b));
  }

  vector<int> res(m);
  for (int i = 0; i < n ; ++ i) {
    S.insert(make_pair(edges[i+1].size(), i+1));
    val[i+1] = edges[i+1].size();
  }
  Reduce();
  for (int i = m-1; i >= 0; --i) {
    res[i] = S.size();
    // Delete an edge...
    DeleteEdge(E[i].first, E[i].second);
    DeleteEdge(E[i].second, E[i].first);
    Reduce();
  }

  for (int r : res) cout << r << endl;

  return 0;
}
