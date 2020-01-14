/*
	크루스칼 알고리즘을 이용해서 해결하는 문제
	두 가지 방법으로 문제 해결 가능
*/
/*
	첫 번째 방법
	코드 출처: https://jaimemin.tistory.com/802
	BFS를 이용해서 구현하는 방법
	1. 입력을 받을 때 2차원 vector를 이용해서 각각의 노드에 연결된 간선을 입력 받는다. (한 번 입력받을 때 두번의 push_back이 일어난다.)
	2. 1번을 시작하는 노드로 정해준 다음 priority_queue를 이용해서 bfs를 진행한다. (가중치의 크기를 기준으로 greater(오름차순)로 정렬시킨다.)
	3. 이미 방문한 노드인지 확인하기 위해 1차원 배열인 visit을 만들어준다.
	4. Visit이 재방문을 안 하게 해주므로 사이클이 생길 일이 없다.
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <functional>
//using namespace std;
//
//const int MAX = 1000 + 1;
//int N, M;
//vector<vector<pair<int, int>>> graph(MAX);
////minHeap
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//bool visited[MAX];
//int main(void)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); //cin 실행속도 향상
//	cin >> N >> M;
//
//	for (int i = 0; i < M; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		//양방향
//		graph[a].push_back({ c, b });
//		graph[b].push_back({ c, a });
//	}
//	//1번 정점부터 시작
//	pq.push({ 0, 1 });
//	int result = 0;
//	while (!pq.empty())
//	{
//		int cost = pq.top().first;
//		int vertex = pq.top().second;
//		pq.pop();
//		cout << "cost: " << cost << endl;
//		if (!visited[vertex])
//		{
//			visited[vertex] = true;
//			result += cost;
//
//			for (int i = 0; i < graph[vertex].size(); i++)
//			{
//				int nextCost = graph[vertex][i].first;
//				int nextVertex = graph[vertex][i].second;
//
//				if (!visited[nextVertex])
//					pq.push({ nextCost, nextVertex });
//			}
//		}
//	}
//	cout << result << "\n";
//	return 0;
//}


/*
	두 번째 방법
	코드 출처: https://lmcoa15.tistory.com/57
	1. parent노드를 변경해주면서 구현
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct str {
//	int s, e, w;
//	str(int s, int e, int w) :s(s), e(e), w(w) {};
//};
//
//bool operator<(str s1, str s2) {
//	return s1.w < s2.w;
//}
//
//int parent[1001] = { 0 };
//int find(int k) {
//
//	while (parent[k] != k) {
//		k = parent[k];
//	}
//	return k;
//}
//int main() {
//
//	int N, M;
//	cin >> N >> M;
//
//	int s, e, w;
//	vector<str> vec;
//	for (int i = 0; i < M; i++) {
//		scanf_s("%d %d %d", &s, &e, &w);
//		vec.push_back(str(s, e, w));
//	}
//
//	int ans = 0;
//	int p1, p2 = 0;
//	sort(vec.begin(), vec.end());
//
//	for (int i = 1; i <= N; i++)
//		parent[i] = i;
//
//	for (int i = 0; i < vec.size(); i++) {
//
//		p1 = find(vec[i].s);
//		p2 = find(vec[i].e);
//
//		if (p1 == p2)
//			continue;
//
//		if (p1 < p2)   parent[p1] = p2;
//		else    parent[p2] = p1;
//		ans += vec[i].w;
//	}
//
//	cout << ans << endl;
//	return 0;
//}

/*
	find를 구현하는 두 가지 방법
	1. 재귀를 이용해서 구현
	if(k == parent[k]){
		return k;
	}
	return find(parent[k]);


	2. while문을 이용해서 구현
	while(parent[k] != k){
		k = parent[k];
	}
	return k;
*/