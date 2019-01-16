4714
#include<iostream>
using namespace std;
int main(void) {
	double e_weight;
	double m_weight;
	while (1) {
		cin >> e_weight;
		if (e_weight == -1.0)
			break;
		m_weight = e_weight * 0.167;
		printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", e_weight, m_weight);
	}
	system("pause");
	return 0;
}