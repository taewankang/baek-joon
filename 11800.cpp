#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	vector<pair<int, string>> dice;
	vector<pair<int, string>> same;
	dice.push_back({ 0, "" });
	dice.push_back({ 1, "Yakk" });	dice.push_back({ 2, "Doh" });
	dice.push_back({ 3, "Seh" });	dice.push_back({ 4, "Ghar" });
	dice.push_back({ 5, "Bang" });	dice.push_back({ 6, "Sheesh" });
	same.push_back({ 0, "" });
	same.push_back({ 1, "Habb Yakk" });	same.push_back({ 2, "Dobara" });
	same.push_back({ 3, "Dousa" });	same.push_back({ 4, "Dorgy" });
	same.push_back({ 5, "Dabash" });	same.push_back({ 6, "Dosh" });
	for (int m = 0; m < T; m++) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "Case " << m + 1 << ": " << same[a].second<< "\n";
		}
		else if ((a == 6 && b == 5) || (a == 5 && b == 6)) {
			cout << "Case " << m + 1 << ": Sheesh Beesh\n";
		}
		else {
			cout << "Case " << m + 1 << ": " << dice[max(a, b)].second << " " << dice[min(a, b)].second << "\n";
		}
	}
	system("pause");
	return 0;
}