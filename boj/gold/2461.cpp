#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2e9;
using namespace std;

int main()
{
  fastio;

  int n, m;
  cin >> n >> m;

  pair<int, int> a[n * m];
  vector<int> class_cnt(n, 0); // 학급 개수 확인

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int ability;
      cin >> ability;
      // 능력치와 학급을 한 쌍으로 배열에 저장
      a[i * m + j] = make_pair(ability, i);
    }
  }
  sort(a, a + (n * m));

  int start = 0, end = 0;
  int cnt = 0;
  int result = INF;

  while (start <= end && end < n * m)
  {
    // 새로운 학급일 경우에만 학급수 세기
    if (class_cnt[a[end].second] == 0)
      cnt++;

    class_cnt[a[end].second]++;

    // 학급수가 n개일 경우 start 증가를 반복
    while (cnt == n)
    {
      result = min(result, a[end].first - a[start].first);

      class_cnt[a[start].second]--;
      // 제외한 학급수가 0인 경우(학급이 제외된 경우) cnt 감소
      if (class_cnt[a[start].second] == 0)
        cnt--;
      start++;
    }

    end++;
  }
  cout << result;
}