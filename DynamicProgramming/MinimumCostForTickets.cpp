#include <limits>
#include <vector>
class Solution {
public:
  int mincostTickets(std::vector<int> &days, std::vector<int> &costs) {
    int n = days.size();
    std::vector<int> dp(n + 1);
    for (int i = 0; i < n; i++)
      dp[i]=std::numeric_limits<int>::max();
    std::vector<int> duration{1, 7, 30};
    for (int i = n - 1; i >= 0; i--) {
      for (int k = 0; k < 3; k++) {
        int j = i;
        while (j < n && days[i] + duration[k] > days[j])
          j++;
        dp[i]=std::min(dp[i],dp[j]+costs[k]);
      }
    }
    return dp[0];
  }
};