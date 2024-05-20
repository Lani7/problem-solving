#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n;
  cin >> n;
  priority_queue<int> plus;                             // 내림차순 정렬
  priority_queue<int, vector<int>, greater<int>> minus; // 오름차순 정렬
  int one = 0;
  int zero = 0;
  int sum = 0;

  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    if (data > 1)
      plus.push(data);
    else if (data == 1)
      one++;
    else if (data == 0)
      zero++;
    else
      minus.push(data);
  }

  // 1보다 큰 양수의 집합
  while (plus.size() > 1)
  {
    int t1 = plus.top();
    plus.pop();
    int t2 = plus.top();
    plus.pop();
    sum += t1 * t2;
  }
  if (!plus.empty())
    sum += plus.top();

  // 음수의 집합
  while (minus.size() > 1)
  {
    int t1 = minus.top();
    minus.pop();
    int t2 = minus.top();
    minus.pop();
    sum += t1 * t2;
  }
  // 0이 있을 경우 남은 음수와 곱해 0으로 만듦
  // 0이 없을 경우 남은 음수를 더함
  if (!minus.empty() && zero == 0)
    sum += minus.top();

  // 1의 개수 더하기
  sum += one;

  cout << sum;
}