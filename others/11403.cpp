#include <iostream>
using namespace std;
int input[101][101];
bool visited[101][101];
int n;
void go(int start, int x, int y)
{
	input[start][y] = 1;		//
	cout << "top: " << start << " y: " << y << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", input[i][j]);
		printf("\n");
	}
	cout << endl;

	visited[start][y] = true;	//여기 방문을 했다.
	for (int i = 1; i <= n; i++)
	{
		if (!visited[start][i] && input[y][i])	//첫번째 i항을 방문하지 않았고 1이라면
			go(start, y, i);			//1에서 시작하고
	}
}

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf_s("%d", &input[i][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << "go" << endl;
			if (!visited[i][i] && input[i][j])	//방문을 하지 않았고 input이 1이라면 
				go(i, i, j);
		}
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", input[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}