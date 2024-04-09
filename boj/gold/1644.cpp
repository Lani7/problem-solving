#include <iostream>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<int> get_prime(int n);

int main()
{
  fastio;

  int n;
  cin >> n;

  if (n == 1)
  {
    cout << "0";
    return 0;
  }

  vector<int> v = get_prime(n);

  int start = 0, end = 0;
  int cnt = 0;
  int sum = v[start];

  while (start <= end && end < v.size())
  {
    if (sum > n)
    {
      sum -= v[start];
      start++;
    }
    else if (sum < n)
    {
      end++;
      sum += v[end];
    }
    else
    {
      cnt++;
      sum -= v[start];
      start++;
      end++;
      sum += v[end];
    }
  }
  cout << cnt;
}

vector<int> get_prime(int n)
{
  vector<bool> is_prime(n + 1, true);
  vector<int> v;

  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= sqrt(n); i++)
  {
    if (!is_prime[i])
      continue;
    for (int j = 2; i * j <= n; j++)
      is_prime[i * j] = false;
  }

  for (int i = 2; i <= n; i++)
    if (is_prime[i])
      v.push_back(i);

  return v;
}