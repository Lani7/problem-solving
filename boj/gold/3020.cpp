#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  int n, h;
  cin >> n >> h;

  vector<int> bottom(h + 1, 0);
  vector<int> up(h + 1, 0);
  vector<int> result(h + 1, 0);

  // 각각 석순, 종유석 벡터에 길이를 인덱스로 개수를 저장
  for (int i = 0; i < n / 2; i++)
  {
    int num;
    cin >> num;
    bottom[num]++;

    cin >> num;
    up[num]++;
  }

  // 누적합 만들기 (길이가 가장 긴 것이 장애물이 적은 개수이므로 역순으로 누적합)
  for (int i = bottom.size() - 2; i > 0; i--)
  {
    bottom[i] += bottom[i + 1];
    up[i] += up[i + 1];
  }

  int min_val = numeric_limits<int>::max();
  int count = 0;

  // result 벡터에 bottom벡터 순방향 + up벡터 역순(종유석은 거꾸로 있기 때문)으로 각각 더하기
  for (int i = 1, j = up.size() - 1; i < result.size(); i++, j--)
  {
    result[i] = bottom[i] + up[j];
    if (min_val == result[i])
      count++;
    else if (min_val > result[i])
    {
      min_val = result[i];
      count = 1;
    }
  }

  cout << min_val << " " << count;
}