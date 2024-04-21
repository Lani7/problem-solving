#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 1; i < n; i++)
  {
    int j;
    int val = a[i];
    for (j = i - 1; j >= 0 && a[j] > val; j--)
    {
      if (a[j] > val)
        a[j + 1] = a[j];
    }
    a[j + 1] = val;
  }

  vector<int> s(n + 1, 0);
  int sum = 0;

  for (int i = 1; i <= n; i++)
  {
    s[i] = s[i - 1] + a[i - 1];
    sum += s[i];
  }
  cout << sum;
}