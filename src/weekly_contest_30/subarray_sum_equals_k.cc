#include <vector>
#include <map>
#include <gtest/gtest.h>

using std::vector;
using std::map;


namespace weekly_contest_30_subarray
{
  class Solution
  {
  public:
    int subarraySum(vector<int>& nums, int k)
    {
      map<int, int> sums;
      sums[0] = 1;

      int sum = 0;
      int count = 0;

      for (vector<int>::const_iterator istart = nums.cbegin(), iend = nums.cend();
        istart != iend; ++istart)
      {
        sum += *istart;
        count += sums[sum - k];
        sums[sum] += 1;
      }

      return count;
    }
  };
}

TEST(weekly_contest_30_subarray, correct)
{
  using weekly_contest_30_subarray::Solution;

  Solution sol = Solution();

  vector<int> nums({ 1, 1, 1 });

  EXPECT_EQ(sol.subarraySum(nums, 0), 0);
  EXPECT_EQ(sol.subarraySum(nums, 1), 3);
  EXPECT_EQ(sol.subarraySum(nums, 2), 2);
  EXPECT_EQ(sol.subarraySum(nums, 3), 1);
}