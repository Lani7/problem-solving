#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, m;
  cin >> n >> m;

  int a[n];
  int start = 0;
  int end = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    start = max(start, a[i]);
    end += a[i];
  }

  while (start < end)
  {
    int mid = (start + end) / 2;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      if (sum + a[i] > mid)
      {
        // 블루레이 개수 추가
        count++;
        sum = 0;
      }
      sum += a[i];
    }
    count++; // 마지막 블루레이

    if (count <= m)
      end = mid;
    else
      start = mid + 1;
  }
  cout << start;
}