#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int H, W;
	cin >> H >> W;
	string str;
	cin.ignore();
	for (int i = 0; i < H; i++) {
		int coming = 0;
		bool cloud = false;
		getline(cin, str);
		for (int j = 0; j < W; j++) {
			if (str[j] == 'c') {
				cout << "0 ";
				if (cloud == false) {
					cloud = true;
					coming++;
				}
				else if (cloud == true) {
					coming = 1;
				}
			}
			else if (str[j] == '.' && cloud==true) {
				cout << coming << " ";
				coming++;
			}
			else if (str[j] == '.' && cloud == false) {
				cout << "-1 ";
			}
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}