#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, k;
  cin >> n >> k;

  int a[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  cout << a[k - 1];
}
