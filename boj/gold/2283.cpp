#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2e9
using namespace std;

int main()
{
  fastio;
  int n, k;
  cin >> n >> k;

  pair<int, int> arr[n];

  int max_len = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].first >> arr[i].second;
    max_len = max(max_len, arr[i].second);
  }
  sort(arr, arr + n);

  vector<int> v(max_len + 1, 0);
  for (int i = 0; i < n; i++)
    for (int j = arr[i].first; j < arr[i].second; j++)
      v[j]++;

  int a = 0;
  int b = 0;
  int sum = 0;

  while (a <= b && b <= max_len)
  {
    if (sum == k)
    {
      cout << a << " " << b;
      return 0;
    }
    else if (sum < k)
      sum += v[b++];
    else
      sum -= v[a++];
  }
  cout << "0 0";
}