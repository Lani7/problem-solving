#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<string> split(string input, char deli);
int mySum(string str);

int main()
{
  fastio;

  int result = 0;
  string input;
  cin >> input;

  vector<string> str = split(input, '-');

  for (int i = 0; i < str.size(); i++)
  {
    int sum = mySum(str[i]);
    // 제일 앞에 것만 더하고 나머지 뒷부분은 빼기
    if (i == 0)
      result += sum;
    else
      result -= sum;
  }
  cout << result;
}

vector<string> split(string input, char deli)
{
  vector<string> result;
  stringstream ss(input);
  string buffer;

  while (getline(ss, buffer, deli))
    result.push_back(buffer);

  return result;
}

int mySum(string str)
{
  int sum = 0;
  vector<string> result = split(str, '+');
  for (int i = 0; i < result.size(); i++)
    sum += stoi(result[i]);
  return sum;
}