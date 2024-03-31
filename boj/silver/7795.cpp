#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int t, n, m;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    cin >> n >> m;
    int a[n];
    int b[m];
    int cnt = 0;

    for (int j = 0; j < n; j++)
      cin >> a[j];
    sort(a, a + n);
    for (int j = 0; j < m; j++)
      cin >> b[j];
    sort(b, b + m);

    // 배열 a크기(n)만큼 반복
    for (int k = 0; k < n; k++)
    {
      // 배열 b에 대하여 이분탐색
      int left = 0;
      int right = m - 1;
      while (left <= right)
      {
        int mid = (left + right) / 2;
        // key보다 크거나 같은 경우 앞쪽 범위로 좁힘
        if (b[mid] >= a[k])
          right = mid - 1;
        // key보다 작은 경우
        else
        {
          // 조건 만족 (바로 다음 인덱스의 값이 키값보다 더 큰 경우)
          if (b[mid + 1] >= a[k])
            left = mid + 1;
          // 조건을 만족하는 최대값 찾기 위해 뒤쪽 범위로 좁힘
          else
            left = mid + 1;
        }
      }
      cnt += left;
    }
    cout << cnt << "\n";
  }
}