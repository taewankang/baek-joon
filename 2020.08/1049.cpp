//변수 이름을 잘못 지정..
#include<iostream>
#include<algorithm>
using namespace std;
int N, M, minimum = 97654321;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    int package, single;
    int package_price = 10001, single_price = 1001;
    int only_package; // 패키지만 샀을 때,
    int cnt_package, cnt_left;  // 패키지와 낱개를 같이 샀을 때

    cnt_package = N / 6;
    only_package = cnt_package;
    if(N % 6 != 0) only_package++;
    cnt_left = N % 6;
 
    for(int i = 0; i < M; i++){
        cin >> package >> single;
        if(package_price > package) package_price = package;
        if(single_price > single) single_price = single;
    }
    
    minimum = min(single_price * N, min(only_package * package_price, cnt_package * package_price + cnt_left * single_price));
    //min(낱개로만 샀을 때, min(패키지로만 샀을 때, 패키지와 낱개를 같이 샀을 때))
    cout << minimum << endl;
    return 0;
}