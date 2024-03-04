#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> s(n + 1);

  // 합 배열 만들기
  for (int i = 1; i <= n; i++)
  {
    int num;
    cin >> num;
    s[i] = s[i - 1] + num;
  }

  int start = 1;
  int end = 1;
  int sum = 0;
  int count = 0;

  while (end < n + 1)
  {
    // start, end 구간의 합 구하기
    sum = s[end] - s[start - 1];
    if (sum > m)
      start++;
    else if (sum < m)
      end++;
    else
    {
      count++;
      start++;
      end++;
    }
  }
  cout << count << endl;
}