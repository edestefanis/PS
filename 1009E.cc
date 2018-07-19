#include <cstdio>
#include <vector>
#include <iostream>


using namespace std;

typedef long long ll;
int main() {

				int n;
				cin >> n;
				vector<ll> a;
				ll MOD = 998244353;
				for (int i = 0; i < n; ++i) {
								int b;
								scanf("%d", &b);
								a.push_back(b);
								if (i) {
												a[i] = (a[i-1] + a[i]) % MOD;
								}
				}
				ll p[1000010];
				p[0] = 1;
				for (int i = 1; i <= n; ++i) {
								p[i] = (p[i-1]+p[i-1]);
								if (p[i] > MOD) p[i] %= MOD;
				}

				ll res = 0;
				for (int i = 1; i < n; ++i) {
								if (n-i-2 >= 0) {
												res = (res + ((a[i-1] * (n-i-1))%MOD) * p[n-i-2]) % MOD;
								}
								res = (res + a[i-1] * p[n-i]);
								if (res >= MOD) res %= MOD;
				}
				res = (res + a[n-1]) % MOD;
				cout << res << endl;

				return 0;
}
