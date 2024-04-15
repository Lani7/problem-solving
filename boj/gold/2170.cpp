#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n;
  cin >> n;

  vector<pair<int, int>> v;

  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }

  sort(v.begin(), v.end());

  int start = v[0].first;
  int end = v[0].second;
  int result = 0;

  for (int i = 1; i < v.size(); i++)
  {
    if (v[i].first > end)
    {
      result += end - start;
      start = v[i].first;
      end = v[i].second;
    }
    else if (v[i].second > end)
      end = v[i].second;
  }
  result += end - start;
  cout << result;
}