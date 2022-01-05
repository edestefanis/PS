#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


long long gcd(long long a, long long b) {
	if (a == 0) return b;
	if (a > b) return gcd(b, a);
	return gcd(b % a, a);
}


int main() {
	int i,j , k;
	int casos; cin >> casos;
	for (int h = 0; h < casos; ++h) {
		int N; cin >> N;
		vector<pair<long long, long long> > vec;
		for (int i = 0; i < N; ++i) {
			long long a, b;
			cin >> a >> b;
			vec.push_back(make_pair(a,b));
		}	
		bool done = false;

		for (long long a = 1; !done && a < 20; ++a) for (long long b = 1;!done && b < 20; ++b) {
			long long previous = 0;
			for (int i = 0; i < vec.size(); ++i) {
				long long num = a * vec[i].first + b * vec[i].second;
				//cout << previous << "  " << num << endl;
				if (num <= previous) {
					previous = -1;
				       	break;
				}
				previous = num;
			}
			if (previous != -1) {
				done = true;
				cout << "Case #" << h+1 << ": " << a << " " << b << endl;
			}
		}
		if (!done) cout << "Case #" << h+1 << ": IMPOSSIBLE" << endl;
	}
	return 0;
}
