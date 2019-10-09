#include <iostream>
#include <map>
#include<string.h>
#include<string>
using namespace std;
int main(void){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	for(int i=0; i<N; i++){	
		int n;
		map<string, int> m;
		map<string, int>::iterator iter = m.begin();
		string key, value;
		cin >> n;
		for(int j=0; j<n; j++){
			cin >> value >> key;			
			iter = m.begin();
			iter = m.find(key);
			if(iter == m.end())
				m.insert({key, 2});
			else
				m[key]++;			
		}		
		int result = 1;
		for(iter = m.begin() ; iter != m.end(); iter++){
			result *= (*iter).second;
		}
		cout << result - 1 << endl;
	}
    return 0;
}