#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check[101] = { false, };
int first_num, deep ,counting;
bool fin = false;
vector<int> v;
int N;
void dfs(vector<pair<int, int>> &vec, int start) {
	counting++;
	if (counting > N)
		return;
	if (start > N || start < 1)
		return;
	if (vec[start].second == start && check[vec[start].second] == false) {
		deep++;
		check[start] = true;
		v.push_back(start);
		return;
	}
	else if (vec[start].second != first_num && check[vec[start].second]==false) {
		dfs(vec, vec[start].second);
		if (fin == true) {
			check[start] = true;
			deep++;
			v.push_back(start);
		}
	}
	else if (vec[start].second == first_num && check[vec[start].second]==false) {
		deep++;
		fin = true;
		check[start] = true;
		v.push_back(start);
		return;
	}
}

int main(void) {
	int n, result = 0;
	cin >> N;
	vector<pair<int, int>> vec(N + 1, { 0, 0 });
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec[i + 1]={ i + 1, n };
	}
	for (int i = 1; i < vec.size(); i++) {
		if (check[i] == false) {
			counting = 0;
			deep = 0;	fin = false;
			first_num = i;
			dfs(vec, i);
			result += deep;
		}
	}
	sort(v.begin(), v.end());
	cout << result << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	system("pause");
	return 0;
}