#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);
int main()
{
  fastio;

  int n;
  cin >> n;
  vector<pair<int, int>> info(n);

  for (int i = 0; i < n; i++)
    cin >> info[i].first >> info[i].second; // 시작 시간, 종료 시간

  sort(info.begin(), info.end(), compare);

  int end = -1;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    // 이전 회의의 종료 시간과 현재 회의의 시작 시간이 겹치지 않는 경우
    if (end <= info[i].first)
    {
      end = info[i].second;
      count++;
    }
  }
  cout << count;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}