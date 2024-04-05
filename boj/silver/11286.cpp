#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct cmp
{
  bool operator()(int o1, int o2)
  {
    if (abs(o1) == abs(o2))
      return o1 > o2;
    return abs(o1) > abs(o2);
  }
};

int main()
{
  fastio;

  int n;
  cin >> n;

  priority_queue<int, vector<int>, cmp> pq;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    if (x != 0)
      pq.push(x);
    else
    {
      if (!pq.empty())
      {
        cout << pq.top() << '\n';
        pq.pop();
      }
      else
        cout << "0 \n";
    }
  }
}