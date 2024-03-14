#include <iostream>
#include <algorithm>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int a[3];
  while (true)
  {
    for (int i = 0; i < 3; i++)
      cin >> a[i];
    if (a[0] == 0 && a[1] == 0 && a[2] == 0)
      break;
    sort(a, a + 3);
    if ((int)pow(a[0], 2) + (int)pow(a[1], 2) == (int)pow(a[2], 2))
      cout << "right"
           << "\n";
    else
      cout << "wrong"
           << "\n";
  }
}