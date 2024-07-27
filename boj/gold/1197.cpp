#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int parent[100001];
void union_func(int a, int b);
int find(int a);

int main()
{
  fastio;

  int v, e;
  cin >> v >> e;

  typedef struct edge
  {
    int s, e, w;
    bool operator>(const edge &temp) const
    {
      return w > temp.w;
    }
  } edge;

  priority_queue<edge, vector<edge>, greater<edge>> pq;

  for (int i = 1; i <= v; i++)
    parent[i] = i;

  for (int i = 0; i < e; i++)
  {
    int s, e, w;
    cin >> s >> e >> w;
    pq.push({s, e, w});
  }

  int usedEdge = 0;
  int result = 0;

  while (usedEdge != v - 1)
  {
    edge cur = pq.top();
    pq.pop();
    if (find(cur.s) != find(cur.e))
    {
      union_func(cur.s, cur.e);
      result += cur.w;
      usedEdge++;
    }
  }
  cout << result;
}

void union_func(int a, int b)
{
  a = find(a);
  b = find(b);
  if (a != b)
    parent[b] = a;
}

int find(int a)
{
  if (parent[a] == a)
    return a;
  return parent[a] = find(parent[a]);
}