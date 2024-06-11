#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

// 6가지 이동 케이스
int sender[] = {0, 0, 1, 1, 2, 2};
int receiver[] = {1, 2, 0, 2, 0, 1};

bool visited[201][201];
bool answer[201];
int now[3];

void bfs();

int main()
{
  fastio;

  cin >> now[0] >> now[1] >> now[2];

  bfs();

  for (int i = 0; i < 201; i++)
    if (answer[i])
      cout << i << " ";
}

void bfs()
{
  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = true;
  answer[now[2]] = true;

  while (!q.empty())
  {
    int a = q.front().first;
    int b = q.front().second;
    int c = now[2] - a - b;
    q.pop();

    // 노드에서 갈 수 있는 6개의 경우
    for (int k = 0; k < 6; k++)
    {
      int next[] = {a, b, c};
      next[receiver[k]] += next[sender[k]];
      next[sender[k]] = 0;
      // 용량을 초과할 경우
      if (next[receiver[k]] > now[receiver[k]])
      {
        // 보내는 물통은 용량에서 초과하는 만큼만 저장
        next[sender[k]] = next[receiver[k]] - now[receiver[k]];
        // 받는 물통은 최대 용량까지 채우기
        next[receiver[k]] = now[receiver[k]];
      }
      if (visited[next[0]][next[1]])
        continue;
      visited[next[0]][next[1]] = true;
      q.push({next[0], next[1]});
      if (next[0] == 0)
        answer[next[2]] = true;
    }
  }
}