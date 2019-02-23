#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string gan, sa;
		vector<int> g(6, 0), s(7, 0);
		int j = 0;
		getline(cin, gan);
		getline(cin, sa);

		for (int k = 0; k < gan.length(); k++) {
			if (gan[k] >= '0' && gan[k] <= '9') {
				g[j] *= 10;
				g[j] += gan[k] - '0';
			}
			else if (gan[k] == ' ')
				j++;
		}
		j = 0;
		for (int k = 0; k < sa.length(); k++) {
			if (sa[k] >= '0' && sa[k] <= '9') {
				s[j] *= 10;
				s[j] += sa[k] - '0';
			}
			else if (sa[k] == ' ')
				j++;
		}
		g[1] *= 2;	g[2] *= 3;	g[3] *= 3;	g[4] *= 4;	g[5] *= 10;
		s[1] *= 2;	s[2] *= 2;	s[3] *= 2;	s[4] *= 3;	s[5] *= 5;	s[6] *= 10;
		
		int tot_g = 0, tot_s = 0;
		for (int j = 0; j < 6; j++)
			tot_g += g[j];
		for (int j = 0; j < 7; j++)
			tot_s += s[j];
		if (tot_g > tot_s)
			cout << "Battle " << i + 1 << ": Good triumphs over Evil\n";
		else if (tot_g == tot_s)
			cout << "Battle " << i + 1 << ": No victor on this battle field\n";
		else
			cout << "Battle " << i + 1 << ": Evil eradicates all trace of Good\n";
	}
	system("pause");
	return 0;
}