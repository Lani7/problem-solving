#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int parent[201];
void unionfunc(int a, int b);
int find(int a);

int main()
{
  fastio;

  int n, m;
  cin >> n >> m;
  int city[201][201];
  int route[1001];

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      cin >> city[i][j];
  }

  for (int i = 1; i <= m; i++)
    cin >> route[i];

  // 대표 노드 초기화
  for (int i = 1; i <= n; i++)
    parent[i] = i;

  // 도시가 연결되어 있을 경우 union 실행
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (city[i][j] == 1)
        unionfunc(i, j);
    }
  }

  // 여행 경로 도시의 대표 노드가 모두 같은지 확인
  int idx = find(route[1]);
  for (int i = 2; i <= m; i++)
  {
    if (idx != find(route[i]))
    {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}

void unionfunc(int a, int b)
{
  int val1 = find(a);
  int val2 = find(b);
  if (val1 != val2)
    parent[val2] = val1;
}

int find(int a)
{
  if (a == parent[a])
    return a;
  return parent[a] = find(parent[a]);
}