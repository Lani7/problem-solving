#include <iostream>
#include <vector>
#include <tuple>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<tuple<int, int, int>> list[10];
long lcm;
bool visited[10];
long d[10];

long gcd(long a, long b);
void dfs(int node);

int main()
{
  fastio;

  int n;
  cin >> n;
  lcm = 1;

  for (int i = 0; i < n - 1; i++)
  {
    int a, b, p, q;
    cin >> a >> b >> p >> q;
    list[a].push_back(make_tuple(b, p, q));
    list[b].push_back(make_tuple(a, q, p));
    lcm *= (p * q / gcd(p, q));
  }

  d[0] = lcm;
  dfs(0);
  long dgcd = d[0];
  for (int i = 1; i < n; i++)
    dgcd = gcd(dgcd, d[i]);

  for (int i = 0; i < n; i++)
    cout << d[i] / dgcd << ' ';
}

long gcd(long a, long b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void dfs(int node)
{
  visited[node] = true;
  for (auto i : list[node])
  {
    int next = get<0>(i);
    if (!visited[next])
    {
      d[next] = d[node] * get<2>(i) / get<1>(i);
      dfs(next);
    }
  }
}