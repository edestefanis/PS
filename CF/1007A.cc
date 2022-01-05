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
  int n; cin >> n;
  int arr[100100];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  multiset<int> free;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (free.empty()) {
      free.insert(arr[i]);
    } else {
      if (*(free.begin()) < arr[i]) {
         free.erase(free.begin()); res++;
        }
      free.insert(arr[i]);
    }
  }
  cout << res << endl;
  return 0;
}
