#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n;
  cin >> n;

  priority_queue<int> pq;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    if (x != 0)
      pq.push(x);
    else if (!pq.empty())
    {
      cout << pq.top() << '\n';
      pq.pop();
    }
    else
      cout << "0\n";
  }
}