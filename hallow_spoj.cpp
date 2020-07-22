#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int n, c;
     cin >> c >> n;
     vector<int> arr;
     unordered_map<int, int> m1;
     while (n != 0 && c != 0)
     {
          arr.clear();
          m1.clear();
          arr.assign(n, 0);
          for (auto &x : arr)
          {
               cin >> x;
          }
          m1[0] = 0;
          int sum = 0;
          for (int i = 0; i < n; i++)
          {
               sum += arr[i];
               sum %= c;
               auto it = m1.find(sum);
               if (it != m1.end())
               {
                    int start = (it->second) + 1;
                    for (int j = start; j <= i + 1; j++)
                    {
                         cout << j << " ";
                    }
                    cout << endl;
                    break;
               }
               else
               {
                    m1[sum] = i + 1;
               }
          }
          cin >> c >> n;
     }
}