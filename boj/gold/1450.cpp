#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, c;
int a[30];
vector<long long> a1;
vector<long long> a2;

void makeCombi(int start, int end, long long sum, vector<long long> &part);

int main()
{
  fastio;
  cin >> n >> c;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // 배열을 반으로 나눠서 가능한 조합 구하기
  makeCombi(0, n / 2, 0, a1);
  makeCombi(n / 2, n, 0, a2);

  sort(a1.begin(), a1.end());
  sort(a2.begin(), a2.end());

  int left = 0;
  int right = a2.size() - 1;
  int result = 0;

  while (left < a1.size() && right >= 0)
  {
    if (a1[left] + a2[right] > c)
      right--;
    else
    {
      result += right + 1;
      left++;
    }
  }
  cout << result;
}

void makeCombi(int start, int end, long long sum, vector<long long> &part)
{
  if (sum > c)
    return;
  if (start >= end)
  {
    part.push_back(sum);
    return;
  }
  makeCombi(start + 1, end, sum, part);
  makeCombi(start + 1, end, sum + a[start], part);
}