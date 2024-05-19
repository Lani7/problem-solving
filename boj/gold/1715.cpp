#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬
  int sum = 0;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    pq.push(num);
  }

  while (pq.size() > 1)
  {
    int t1 = pq.top();
    pq.pop();
    int t2 = pq.top();
    pq.pop();
    sum += t1 + t2;
    pq.push(t1 + t2);
  }
  cout << sum;
}