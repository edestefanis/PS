#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() { 
	int i, j, k;
	int n; cin >> n;
	string a, b;
	cin  >> a >> b;
	long long zu = 0, uu = 0, uz = 0, zz = 0;
	for (i = 0; i < n; ++i) { 
		if (a[i] == '0' && b[i] == '0')  zz++;
		if (a[i] == '1' && b[i] == '0')  uz++;
		if (a[i] == '1' && b[i] == '1')  uu++;
		if (a[i] == '0' && b[i] == '1')  zu++;
	}
	long long res = 0;
	res += zu * uz;
	res += uz * zz;
	res += zz * uu;
	cout << res << endl;
	return 0;
}
