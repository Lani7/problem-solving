#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, startCity, endCity, m;
  cin >> n >> startCity >> endCity >> m;

  typedef tuple<int, int, int> edge;
  vector<edge> edges;
  vector<int> money(n);
  vector<long> dist(n, LONG_MIN);

  for (int i = 0; i < m; i++)
  {
    int start, end, price;
    cin >> start >> end >> price;
    edges.push_back({start, end, price});
  }
  for (int i = 0; i < n; i++)
    cin >> money[i];

  dist[startCity] = money[startCity];

  for (int i = 0; i < n + 50; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int start = get<0>(edges[j]);
      int end = get<1>(edges[j]);
      int price = get<2>(edges[j]);
      // 시작 노드를 방문하지 않은 경우 건너뛰기
      if (dist[start] == LONG_MIN)
        continue;
      // 시작노드가 양수 사이클에 연결된 노드일 경우 종료 노드도 양수 사이클 연결 노드로 업데이트
      if (dist[start] == LONG_MAX)
        dist[end] = LONG_MAX;
      // 기존 값보다 최대 이윤을 낼 수 있는 경우 업데이트
      else if (dist[end] < dist[start] + money[end] - price)
      {
        dist[end] = dist[start] + money[end] - price;
        // n - 1번 반복 이후 갱신될 경우 양수 사이클 연결 노드로 업데이트
        if (i > n - 1)
          dist[end] = LONG_MAX;
      }
    }
  }

  // 도착 불가능한 경우
  if (dist[endCity] == LONG_MIN)
    cout << "gg";
  // 돈을 무한히 많이 가지고 있을 수 있는 경우(양수 사이클)
  else if (dist[endCity] == LONG_MAX)
    cout << "Gee";
  else
    cout << dist[endCity];
}