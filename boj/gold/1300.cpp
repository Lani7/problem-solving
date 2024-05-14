#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  long n, k;
  cin >> n >> k;

  long low = 1;
  long high = k;

  while (low < high)
  {
    cout << "---------------" << endl;
    cout << "low: " << low << " high: " << high << endl;
    long mid = (low + high) / 2;
    long count = 0;
    cout << "mid: " << mid << endl;

    for (int i = 1; i <= n; i++)
      count += min(mid / i, n);
    cout << "count: " << count << endl;

    if (count < k)
      low = mid + 1;
    else
      high = mid;
  }
  // cout << "low: " << low << endl;
  cout << low;
}