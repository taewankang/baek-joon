#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> vec(51);
int counting = 0;
void dfs(int del) {
	if (vec[del].size() == 0) {
		counting++;
		return;
	}
	for (int i = 0; i < vec[del].size(); i++)
		dfs(vec[del][i]);
}

int find_parent(int N, int n) {
	for(int i=0; i<N; i++){
		for (int j = 0; j < vec[i].size(); j++)
			if (vec[i][j] == n)
				return i;
	}
	return -1;
}

int main(void) {
	int N, n, del, result = 0;;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if(n != -1)
			vec[n].push_back(i);
	}
	cin >> del;
	dfs(del);
	int parent = find_parent(N, del);
	if (parent != -1) {
		if (vec[parent].size() == 1)
			result++;
	}
	for (int i = 0; i < N; i++)
		if (vec[i].size() == 0)
			result++;
	cout << result - counting << endl;
	system("pause");
	return 0;
}