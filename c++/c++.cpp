#include <iostream>
#include <vector>
#include <queue>


using namespace std;
// DFS : 깊이 우선 탐색
// BFS : 너비 우선 탐색


struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector <bool> visited;
vector <bool> discovered;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>> (6);


	// 인접 리스트
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);

	// 인접 행렬
	//adjacent = vector<vector<int>>
	//{
	//	{0,1,0,1,0,0},
	//	{1,0,1,1,0,0},
	//	{0,0,0,0,0,0},
	//	{0,0,0,0,1,0},
	//	{0,1,0,1,0,0},
	//	{0,0,0,0,1,0},
	//};

}

#pragma region MyRegion
// DFS
void Dfs(int here)
{
	// 방문
	visited[here] = true;

	cout << "Visited : " << here << endl;
	// 인접 리스트 version
	// 모든 인접 정점을 순회한다.
	//for (int i = 0; i < adjacent[here].size(); i++)
	//{
	//	int there = adjacent[here][i];
	//	
	//	if (visited[there] == false)
	//		Dfs(there);
	//}


	// 인접 행렬 version
	// 모든 인접 접점을 순회한다.
	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;

		if (visited[there] == false)
			Dfs(there);
	}


}

void DfsAll()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
			Dfs(i);
	}
}
#pragma endregion


#pragma region MyRegion
void Bfs(int here)
{
	queue<int> q;
	q.push(here);
	discovered[here] = true;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "Visited : " << here << endl;

		for (int there : adjacent[here])
		{
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;
		}
	}
}

void BfsAll()
{
	for (int i = 0; i < 6; i++)
	{
		if (discovered[i] == false)
			Bfs(i);
	}
}


#pragma endregion

int main()
{
	CreateGraph();
	//visited = vector<bool>(6, false);
	//Dfs(0);
	//DfsAll();

	discovered = vector<bool>(6, false);
	//Bfs(0);
	BfsAll();
}
