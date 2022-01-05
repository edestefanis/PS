#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() { 
  int i, j, k;
  int n; cin >> n;
  vector<vector<int> > vec;
  for (i = 0; i < n; ++i) {
	int a, b, c, d;
	vector<int> line;
	cin >> a >> b >> c >> d;
	line.push_back(400-(a+b+c+d));
 	line.push_back(i);
	line.push_back(a);	
	line.push_back(b);	
	line.push_back(c);	
	line.push_back(d);	
	vec.push_back(line);
  }
  sort(vec.begin(), vec.end());
  for (i = 0; i < vec.size(); ++i) {
	if (vec[i][1] == 0) cout << i+1 << endl;
  }
  return 0;
}
