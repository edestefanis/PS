#include <cstdio>
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>


using namespace std;

int arr[15];
int cnt[1<<13];

	int n, m, q;

		int kk;
	char s[15];
int dfs(int pos, int sum, int mask) {
	if (sum > kk) return 0;
	if (pos  == n) {
		return cnt[mask];
	}
	// its equal
	return dfs(pos+1, sum+arr[pos], mask | (s[pos]=='1'?(1<<pos):0)) +
	       dfs(pos+1, sum, mask | (s[pos] =='0'?(1<<pos):0));	
}

int main() { 
	int i, j, k;
	cin >> n >> m >> q;
	for (i = n-1; i >=0; --i) scanf("%d", &arr[i]);
	int total = 0;
	for (i = 0; i < n; ++i) total += arr[i];
	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < m; ++i) { 
	      scanf("%s", s);
	      int mask = 0;
	      reverse(s, s+n);
	      for (j = 0; j < n; ++j) if (s[j] == '1') mask += 1 << j;
	      cnt[mask]++;
	}
	int suma[1<<15];
	memset(suma, 0, sizeof(suma));
	for ( j = 0; j < 1<<n; ++j) { 
		for (k = 0; k < n; ++k) {
			if ((1<<k) & j) suma[j] += arr[k];
		}
	}
	int opp[1<<15];
	for ( j = 0; j < 1<<n; ++j) { 
		int val = 0;
		for (k = 0; k < n; ++k) {
			if ((1<<k) & j);
			else val += 1<<k;
		}
		opp[j] = val;
	}
	bool seen[1<<15];
	int mem[1<<13][101];
	memset(mem, 0, sizeof(mem));
	for (i = 0; i < q; ++i) {
		scanf("%s %d", s, &kk);
		reverse(s, s+n);
		int res = 0;
		int num = 0;
		for (j = 0; j < n; ++j) {
			if (s[j] == '1') num += (1<<j);	
		}
		if (seen[num]) {
			for (j = 0; j <= kk; ++j) res += mem[num][j];	
		} else {
			seen[num] = true;
			for (j = 0; j < 1<<n; ++j ) {
				if (suma[opp[j xor num]] <= kk) res += cnt[j];
				if (suma[opp[j xor num]] < 101) mem[num][suma[opp[j xor num]]] += cnt[j];
			}
		}
		printf("%d\n", res);
	}

	return 0;
}
