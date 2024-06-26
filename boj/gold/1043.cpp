#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int parent[51];
void unionfunc(int a, int b);
int find(int a);

int main()
{
  fastio;

  int n, m, t;
  cin >> n >> m >> t;

  int trueP[51];
  vector<vector<int>> party(m);

  for (int i = 0; i < t; i++)
    cin >> trueP[i];

  for (int i = 0; i < m; i++)
  {
    int party_size;
    cin >> party_size;
    for (int j = 0; j < party_size; j++)
    {
      int tmp;
      cin >> tmp;
      party[i].push_back(tmp);
    }
  }

  // 대표 노드 초기화
  for (int i = 1; i <= n; i++)
    parent[i] = i;

  // 파티 참가자를 각각의 그룹으로 union
  for (int i = 0; i < m; i++)
  {
    int first = party[i][0];
    for (int j = 1; j < party[i].size(); j++)
      unionfunc(first, party[i][j]);
  }

  int cnt = 0;
  // 각 파티의 대표 노드와 진실을 아는 사람들이 같은 그룹에 있는지 확인
  for (int i = 0; i < m; i++)
  {
    bool flag = true;
    int first = party[i][0];
    for (int j = 0; j < t; j++)
    {
      // 파티의 대표 노드와 진실을 아는 사람의 대표 노드가 같으면 과장할 수 없음
      if (find(first) == find(trueP[j]))
      {
        flag = false;
        break;
      }
    }
    if (flag)
      cnt++;
  }
  cout << cnt;
}

void unionfunc(int a, int b)
{
  int val_a = find(a);
  int val_b = find(b);
  if (val_a != val_b)
  {
    parent[val_b] = val_a;
  }
}

int find(int a)
{
  if (parent[a] == a)
    return a;
  return parent[a] = find(parent[a]);
}