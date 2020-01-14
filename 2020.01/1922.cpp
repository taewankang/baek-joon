/*
	ũ�罺Į �˰����� �̿��ؼ� �ذ��ϴ� ����
	�� ���� ������� ���� �ذ� ����
*/
/*
	ù ��° ���
	�ڵ� ��ó: https://jaimemin.tistory.com/802
	BFS�� �̿��ؼ� �����ϴ� ���
	1. �Է��� ���� �� 2���� vector�� �̿��ؼ� ������ ��忡 ����� ������ �Է� �޴´�. (�� �� �Է¹��� �� �ι��� push_back�� �Ͼ��.)
	2. 1���� �����ϴ� ���� ������ ���� priority_queue�� �̿��ؼ� bfs�� �����Ѵ�. (����ġ�� ũ�⸦ �������� greater(��������)�� ���Ľ�Ų��.)
	3. �̹� �湮�� ������� Ȯ���ϱ� ���� 1���� �迭�� visit�� ������ش�.
	4. Visit�� ��湮�� �� �ϰ� ���ֹǷ� ����Ŭ�� ���� ���� ����.
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
//	cin.tie(0); //cin ����ӵ� ���
//	cin >> N >> M;
//
//	for (int i = 0; i < M; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		//�����
//		graph[a].push_back({ c, b });
//		graph[b].push_back({ c, a });
//	}
//	//1�� �������� ����
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
	�� ��° ���
	�ڵ� ��ó: https://lmcoa15.tistory.com/57
	1. parent��带 �������ָ鼭 ����
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
	find�� �����ϴ� �� ���� ���
	1. ��͸� �̿��ؼ� ����
	if(k == parent[k]){
		return k;
	}
	return find(parent[k]);


	2. while���� �̿��ؼ� ����
	while(parent[k] != k){
		k = parent[k];
	}
	return k;
*/