#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define tr(a, x) for (auto &a : x)

#define int long long
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int32_t main()
{
  SpeedForce;
  int n;
  cin >> n;
  int arr[n], w[n];
  tr(a, arr)
  {
    cin >> a;
  }
  tr(a, w)
  {
    cin >> a;
  }

  int sum = INT_MIN, start_ind = -1, last_ind = -1;
  rep(i, n - 1)
  {
    int temp_sum = w[i];
    int temp_start = i;
    int temp_end = i;

    if (arr[i] < arr[i + 1])
    {
      sum = max(temp_sum, sum);
      if (sum == temp_sum)
      {
        start_ind = temp_start;
        last_ind = temp_end;
      }
      continue;
    }

    while (i < n - 1 && arr[i] >= arr[i + 1])
    {
      temp_sum += w[i + 1];
      i++;
      temp_end++;
    }

    sum = max(temp_sum, sum);
    if (sum == temp_sum)
    {
      start_ind = temp_start;
      last_ind = temp_end;
    }
  }

  cout << start_ind + 1 << " " << last_ind + 1;
}
