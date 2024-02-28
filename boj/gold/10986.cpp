#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  long sum = 0, result = 0;
  vector<long> s;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    sum += num;
    // 합배열에 저장하기
    s.push_back(sum);
  }

  for (int i = 0; i < s.size(); i++)
  {
    // 합 배열을 m으로 나눈 나머지 값으로 업데이트
    s[i] %= m;
    // 나머지가 0인 경우 증가시킨다.
    if (s[i] == 0)
      result++;
  }

  for (int i = 0; i < m; i++)
  {
    // 합배열에서 m으로 나눈 나머지 값이 같은 원소를 찾는다.
    // 그 중에서 2개(i,j구간)를 뽑는 모든 경우의 수를 구한다.
    long cnt = 0;
    for (int j = 0; j < s.size(); j++)
    {
      if (i == s[j])
        cnt++;
    }
    // cnt 중에서 2개 선택하기 (조합)
    result += cnt * (cnt - 1) / 2;
  }

  cout << result << "\n";
}