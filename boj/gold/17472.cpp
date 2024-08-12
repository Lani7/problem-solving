#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void union_func(int a, int b);
int find(int a);
void bfs(int i, int j);

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int map[101][101];
bool visited[101][101];
int parent[101];
int n, m, sNum;
vector<vector<pair<int, int>>> sumlist;
vector<pair<int, int>> list;

typedef struct edge
{
  int s, e, v;
  bool operator>(const edge &temp) const
  {
    return v > temp.v;
  }
} edge;

priority_queue<edge, vector<edge>, greater<edge>> pq;

int main()
{
  fastio;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> map[i][j];

  sNum = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (map[i][j] == 0 || visited[i][j] == true)
        continue;
      // 모든 위치에서 bfs탐색으로 섬을 분리
      bfs(i, j);
      sNum++;
      // 각 섬의 정보를 sumlist 변수에 저장
      sumlist.push_back(list);
    }
  }

  // 섬의 모든 위치에서 만들 수 있는 다리 정보(에지) 저장
  for (int i = 0; i < sumlist.size(); i++)
  {
    vector<pair<int, int>> now = sumlist[i];
    for (int j = 0; j < now.size(); j++)
    {
      int r = now[j].first;
      int c = now[j].second;
      int now_S = map[r][c];

      for (int dir = 0; dir < 4; dir++)
      {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        int blength = 0;

        while (nr >= 0 && nr < n && nc >= 0 && nc < m)
        {
          // 같은 섬인 경우
          if (map[nr][nc] == now_S)
            break;
          // 다른 섬인 경우
          else if (map[nr][nc] != 0)
          {
            // 우선순위 큐에 에지 정보 저장
            if (blength > 1)
              pq.push({now_S, map[nr][nc], blength});
            break;
          }
          // 바다인 경우
          else
          {
            blength++;
            nr += dr[dir];
            nc += dc[dir];
          }
        }
      }
    }
  }

  // parent 배열 초기화
  for (int i = 0; i < sNum; i++)
    parent[i] = i;

  // 최소 신장 트리 알고리즘
  int useEdge = 0;
  int result = 0;

  while (!pq.empty())
  {
    edge now = pq.top();
    pq.pop();
    if (find(now.s) != find(now.e))
    {
      union_func(now.s, now.e);
      result += now.v;
      useEdge++;
    }
  }

  // sNum을 1부터 시작했기 때문에 에지 개수를 sNum-2와 비교
  if (useEdge == sNum - 2)
    cout << result;
  else
    cout << "-1";
}

void union_func(int a, int b)
{
  a = find(a);
  b = find(b);

  if (a != b)
    parent[b] = a;
};

int find(int a)
{
  if (parent[a] == a)
    return a;
  return parent[a] = find(parent[a]);
};

void bfs(int i, int j)
{
  // 연결된 섬 찾기
  // i, j 위치에서 4방향을 탐색해서 하나의 섬의 영역 저장
  queue<pair<int, int>> q;
  list.clear();
  q.push({i, j});
  list.push_back({i, j});
  visited[i][j] = true;
  map[i][j] = sNum;

  while (!q.empty())
  {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nr = r + dr[dir];
      int nc = c + dc[dir];

      while (nr >= 0 && nr < n && nc >= 0 && nc < m)
      {
        if (map[nr][nc] == 0 || visited[nr][nc] == true)
          break;
        // 같은 섬
        map[nr][nc] = sNum;
        visited[nr][nc] = true;
        list.push_back({nr, nc});
        q.push({nr, nc});

        nr += dr[dir];
        nc += dc[dir];
      }
    }
  }
};