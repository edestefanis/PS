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

set<pair<int,int> > divs[100100];

int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  if (!b) return a;
  return gcd(b, a%b);
}

long long calcular(LL A) {
  LL res = 1;
  for (pair<int, int> p : divs[A]) {
    res *= (p.second+1);
  }
  return res;
}

LL calc_resta(LL G) {
  if (G==1) return 0;
  LL res = calcular(G)-1;
  LL cant = calcular(G);
  return res * cant  * 2 + ((cant * (cant-1) * (cant-2)) / 6) * 5;
}

LL calc_resta_dos(int G, int A) {
  return calcular(G) * (calcular(A)-1) + calcular(G) * ((calcular(A) * (calcular(A)-1))/2) ;
}

LL calc_resta_solo(int G, int A) {
  return ((calcular(G) * (calcular(G)-1))/2) * (calcular(A)-1)  ;
}

int main() {
  // Calcular los primos.
  bool prime[100100];
  prime[0] = prime[1] = false;
  for (int i = 2; i < 100100; ++i) prime[i] = true;
  for (int i = 2; i < 100100; ++i) {
    if (!prime[i]) continue;
    divs[i].insert(make_pair(i, 1));
    int k = i+i;
    while (k < 100100) {
      prime[k] = false;
      int aux = k, cant = 0;
      while (aux % i == 0) cant++, aux/=i;
      divs[k].insert(make_pair(i, cant));
      k += i;
    }
  }
  int casos; cin >> casos; for (int h = 0; h < casos; ++h) {
    LL A, B, C; cin >> A >> B >> C;

    /*
    LL G = gcd(gcd(A, B), C);

    LL res = ((calcular(G) * (calcular(G)-1) * (calcular(G)-2)) / 6) * 5;
    // Now lets assume A uses an own prime..
  */


    LL res = calcular(A) * calcular(B) * calcular(C);
    //cout << res << endl;
    // restamos de a pares...
    LL G = gcd(gcd(A, B), C);
    res -= calc_resta(G);
    //cout << res << endl;
    A /= G, B/=G, C/=G;
    res -= (calc_resta_dos(G, gcd(A, B)) + calc_resta_dos(G, gcd(B, C)) + calc_resta_dos(G, gcd(A,C)));
    res -= (calc_resta_solo(G, A) + calc_resta_solo(G, B) + calc_resta_solo(G, C));
    cout << res << endl;
  }
  return 0;
}
