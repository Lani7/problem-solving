#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;
  int n;
  cin >> n;
  vector<int> a_cnt(100001, 0); // 중복인지 확인하기 위한 벡터
  int a[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int start = 0, end = 0;
  long long cnt = 0;

  while (start <= end && end < n)
  {
    // 중복된 수일 경우
    if (a_cnt[a[end]] > 0)
    {
      a_cnt[a[start]]--;
      start++;
      continue;
    }
    // 중복된 수가 아닐 경우
    // 거리(경우의 수) 계산
    cnt += end - start + 1;
    // 숫자가 나온 횟수를 벡터에 저장
    a_cnt[a[end]]++;
    end++;
  }
  cout << cnt;
}