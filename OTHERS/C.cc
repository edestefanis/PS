
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() { 
	int i, j, k;
	int n; cin >> n;
	int p = 1;
	while (p * p < n) p++;

 	int previous = 0;
	i = 0;
	while (i < n) {
		i += p;
		if (i > n) i = n;
		for (j = i; j > previous; --j) {
			if (j != p) cout << " ";
			cout << j;
		}
		previous = i;
	}
	cout << endl;
	return 0;
}

