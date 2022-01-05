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
		sort(vec.begin(), vec.end());
		set<pair<long long, long long> > values; 
		for (int i = 0; i < vec.size(); ++i) for (int j = i+1; j < vec.size(); ++j) {
			if (vec[i].first == vec[j].first) continue;
			if (vec[i].second <= vec[j].second) continue;
			long long num = vec[j].first - vec[i].first;	
			long long den = vec[i].second - vec[j].second;
			long long g = gcd(num, den);
			values.insert(make_pair(num / g, den / g));	
		}
		cout << "Case #" << h+1 << ": " << values.size() + 1 << endl;
	}
	return 0;
}
