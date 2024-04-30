#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void merge_sort(int a[], int tmp[], int left, int right);
void merge(int a[], int tmp[], int left, int mid, int right);
long long result;

int main()
{
  fastio;

  int n;
  cin >> n;
  int a[n];
  int tmp[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];

  merge_sort(a, tmp, 0, n - 1);

  cout << result;
}

void merge_sort(int a[], int tmp[], int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    merge_sort(a, tmp, left, mid);
    merge_sort(a, tmp, mid + 1, right);
    merge(a, tmp, left, mid, right);
  }
}

void merge(int a[], int tmp[], int left, int mid, int right)
{
  int k = left;
  int index1 = left;
  int index2 = mid + 1;

  for (int i = left; i <= right; i++)
    tmp[i] = a[i];

  while (index1 <= mid && index2 <= right)
  {
    if (tmp[index1] > tmp[index2])
    {
      // 뒤쪽 값이 작은 경우 현재 남아있는 앞쪽 데이터 개수만큼 더함(swap 횟수)
      result = result + index2 - k;
      a[k++] = tmp[index2++];
    }
    else
      a[k++] = tmp[index1++];
  }

  while (index1 <= mid)
    a[k++] = tmp[index1++];
  while (index2 <= right)
    a[k++] = tmp[index2++];
}