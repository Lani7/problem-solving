#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, d, k, c;
  cin >> n >> d >> k >> c;
  vector<int> v(d + 1, 0); // 초밥의 총 가짓수
  int a[n + 1];            // 제시된 회전 초밥

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int cnt = 0;

  // 첫 구간 (0~k 미만) 회전초밥을 인덱스로 초밥총가짓수 벡터에 저장
  for (int i = 0; i < k; i++)
    v[a[i]]++;

  // 구간에 쿠폰 번호가 없다면 1 증가
  if (v[c] == 0)
    cnt++;

  // 먹은 초밥의 가짓수 계산 (초밥총가짓수중 값이 0이상인 경우)
  for (int i = 1; i <= d; i++)
  {
    if (v[i] > 0)
      cnt++;
  }

  int result = cnt;

  // 첫 구간을 제외한 1~n미만까지 반복
  for (int start = 1, i = k; start < n; i++, start++)
  {
    cnt = 0;
    // 추가 (회전초밥이므로 인덱스를 넘어갈 경우 mod 이용)
    v[a[i % n]]++;
    // 제거
    v[a[(i - k) % n]]--;

    // 쿠폰이 없을 경우 가짓수 추가
    if (v[c] == 0)
      cnt++;
    // 먹은 초밥의 가짓수 계산
    for (int i = 1; i <= d; i++)
    {
      if (v[i] > 0)
        cnt++;
    }
    result = max(result, cnt);
  }

  cout << result << endl;
}
