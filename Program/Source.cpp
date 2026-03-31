#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	
	sort(v.begin(), v.end(), compare);

	vector<pair<int, int>> result;

	if (n > 0){
		result.push_back(v[0]);
		int last_end = v[0].second;

		for (int i = 1; i < n; i++){
			if (v[i].first >= last_end){
				result.push_back(v[i]);
				last_end = v[i].second;
			}
		}
	}
	
	for (int i = 0; i < result.size(); i++){
		cout << result[i].first << " " << result[i].second << endl;
	}

	
	return 0;
}