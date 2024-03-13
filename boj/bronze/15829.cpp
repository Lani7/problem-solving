#include <iostream>
#include <cmath>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define M 1234567891;
using namespace std;

int main()
{
  fastio;

  int length;
  string str;
  long long hash = 0;
  long long r = 1;

  cin >> length >> str;

  for (int i = 0; i < length; i++)
  {
    long long num = str[i] - 'a' + 1;
    hash += (num * r) % M;
    r = (r * 31) % M;
  }

  cout << hash % M;
}