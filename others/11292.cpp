#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
class Person {
private:
	string name;
	double height;
public:
	Person() {};
	Person(string name, double height) {
		this->name = name;
		this->height = height;
	}
	void set_info(string name, double height) {
		this->name = name;
		this->height = height;
	}
	double get_height() { return height; }
	string get_name() { return name; }
};

bool compare(Person p1, Person p2) {
	if (p1.get_height() > p2.get_height())
		return true;
	else
		return false;
}

int main(void) {
	int N=0;

	while(1){
		bool same = false;
		Person person[51];
		string name;
		double height;
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; i++) {
			cin >> name >> height;
			person[i].set_info(name, height);
		}
		sort(person, person+N, compare);
		if (N == 1)	//하나만 있을때 하나 출력
			cout << person[0].get_name() << "\n";
		else {
			if (person[0].get_height() != person[1].get_height()) {	//가장 큰 사람이 한 명일때
				cout << person[0].get_name() << "\n";
				continue;
			}
			for (int i = 0; i < N - 1; i++) {	//가장 큰 사람이 여러명일 때
				if (person[i].get_height() == person[i + 1].get_height()) {
					cout << person[i].get_name() << "\n";
					same = true;
				}
				else {
					if (same == true)
						cout << person[i].get_name() << "\n";
					break;
				}
			}
			if (person[N - 2].get_height() == person[N - 1].get_height())
				cout << person[N - 1].get_name() << "\n";
		}
	}
	system("pause");
	return 0;
}