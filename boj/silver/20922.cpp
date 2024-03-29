#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, k;
  cin >> n >> k;

  int a[n];
  int num[100001] = {0};
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int start = 0, end = 0;
  int count = 0, result = 0;

  while (end < n && start <= end)
  {
    // 중복 체크
    if (num[a[end]] < k)
    {
      num[a[end]]++;
      end++;
    }
    else if (num[a[end]] >= k)
    {
      count = end - start;
      num[a[start]]--;
      start++;
      result = max(count, result);
    }
  }
  count = end - start;
  result = max(count, result);
  cout << result << "\n";
}