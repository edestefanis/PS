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

#define fr(i,a,b) for(int i(a),_b(b);i<=_b;++i)
#define frd(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define reps(i,a) fr(i,0,sz(a)-1)
#define fore(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define clr(x,a) memset(x,a,sizeof(x))
#define findx(a,x) (find(all(a),x)-a.begin())
#define two(X) (1LL<<(X))
#define contain(S,X) (((S)&two(X))!=0)

template<class T> void print(T const &x) {ostringstream os; os<<x; cout<<os.str()<<endl;}
template<class T> void print(vector<T> const &v) {ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T> void print(vector<vector<T> > const &v){ostringstream os; for(int i=0;i<v.size();++i) {for(int j=0;j<v[i].size();++j){if(j)os<<' ';os<<v[i][j];}os<<endl;}cout<<os.str()<<endl;}
template<class T> void print(valarray<T> const &v) {ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T> int sz(const T&c){return (int)c.size();}
template<class T> void srt(T&c){std::sort(c.begin(),c.end());}
template<class T> void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> void checkmax(T &a,T b){if(b>a) a=b;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}
template<class T> bool inside(T r,T c,T R, T C){return r>=0 && r<R && c>=0 && c<C;}


typedef int coord_t;         // coordinate type
typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point {
	coord_t x, y;
	Point() {}
	Point(coord_t x_, coord_t y_) : x(x_), y(y_) {}

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};


#define MAXN 201010
class ConvexHull {
public:
	ConvexHull(int _N) : N(_N) {}

	coord2_t dot(const Point &A, const Point &O, const Point &B) {
		return (A.x - O.x) * 1LL * (B.x - O.x) + (A.y - O.y) * 1LL * (B.y - O.y);
	}
	coord2_t cross(const Point &O, const Point &A, const Point &B) {
		return (A.x - O.x) * 1LL * (B.y - O.y) - (A.y - O.y) * 1LL *(B.x - O.x);
	}
	void make() {
		size_t k = 0;
		if (N <= 2) return;
		Point H[MAXN];
		sort(v, v+N);
		for (size_t i = 0; i < N; ++i) {  // lower
			while (k >= 2 && cross(H[k-2], H[k-1], v[i]) <= 0) k--;
			H[k++] = v[i];
		}
		for (size_t i = N-1, t = k+1; i > 0; --i) {  // upper
			while (k >= t && cross(H[k-2], H[k-1], v[i-1]) <= 0) k--;
			H[k++] = v[i-1];
		}
		for (size_t i = 0 ; i < k; ++i) {
			v[i] = H[i];
		}
		N = k-1;
	}

	void read() {
			for (int i = 0; i < N; ++i) {
		    int x, y;
		    scanf("%d %d", &v[i].x, &v[i].y);
			}
	}

	Point v[MAXN];
	int N;
};


unsigned long long dist(Point& v1, Point& v2) {
	return (v2.x - v1.x) * 1LL * (v2.x - v1.x) + (v2.y - v1.y) * 1LL * (v2.y - v1.y);
}


int main() {
  int N, M;
	scanf("%d %d", &N, &M);
	ConvexHull v1(N), v2(M);
	v1.read();
	v1.make();
	v2.read();
	v2.make();
	int i;

	bool res = false;
	if (v1.N == v2.N) {
		// Pretty basic comparison.
		// Generate hash for the first hull.
		unsigned long long p[101010], suf[101010], pre[101010], val[101010], pre2[101010];
		unsigned long long prime = 49157, s = 0;
		for (i = 1, p[0] = 1; i < v2.N; ++i) p[i] = p[i-1] * prime;
		int T = v1.N;
		for (i = 0, pre[0] = 0; i < T; ++i) {
			  val[i] = dot(v1.v[i], v1.v[(i+1)%T], v1.v[(i+2)%T]) + dist(v1.v[i], v1.v[(i+1)%T]) * prime;
				//cout << val[i] << "... val " << endl;
				pre[i] += val[i] * p[i];
				pre[i+1] = pre[i];
		}
		for (i = 0; i < T; ++i) {
				//cout <<  dot(v2[i], v2[(i+1)%T], v2[(i+2)%T]) << "... val " << endl;
				s += p[i] * (dot(v2.v[i], v2.v[(i+1)%T], v2.v[(i+2)%T]) + dist(v2.v[i], v2.v[(i+1)%T]) * prime);
		}

		if (pre[T-1] == s) res = true;
		for (i = T-1, suf[T]=0; i > 0 && !res; --i) {
			suf[i] = suf[i+1] * prime + val[i];
			//cout << s << "   " << pre[i] << "  " << p[T-1-i] << "  " << suf[i+1] << endl;
			if (s == pre[i-1] * p[T-1-(i-1)] + suf[i]) {
				res = true;
			}
		}
	}

	if (res) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
