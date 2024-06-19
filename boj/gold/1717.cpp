#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int parent[1000001];

void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main()
{
  fastio;

  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n; i++)
    parent[i] = i;

  for (int i = 0; i < m; i++)
  {
    int type, a, b;
    cin >> type >> a >> b;
    if (!type)
      unionfunc(a, b);
    else
    {
      if (checkSame(a, b))
        cout << "YES \n";
      else
        cout << "NO \n";
    }
  }
}

void unionfunc(int a, int b)
{
  int val1 = find(a);
  int val2 = find(b);
  // 서로 다른 집합일 경우
  if (val1 != val2)
  {
    // 항상 작은 수가 대표노드가 되도록 설정
    if (val1 < val2)
      parent[val2] = val1;
    else if (val1 > val2)
      parent[val1] = val2;
  }
}

int find(int a)
{
  if (parent[a] == a)
    return a;
  return parent[a] = find(parent[a]);
}

bool checkSame(int a, int b)
{
  if (find(a) == find(b))
    return true;
  else
    return false;
}