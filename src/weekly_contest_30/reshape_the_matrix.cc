#include <vector>
#include <gtest/gtest.h>

using std::vector;


namespace weekly_contest_30_reshape
{
  class Solution
  {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
    {
      int r_pre = static_cast<int>(nums.size());
      int c_pre = static_cast<int>(nums[0].size());

      if (r * c != r_pre * c_pre)
        return nums;

      vector<vector<int>> reshape = vector<vector<int>>(r);
      for (int i = 0; i < r; ++i)
        reshape[i] = vector<int>(c);

      int count = r * c;
      int index = 0;
      while (index < count)
      {
        int cur_row_pre = index / c_pre;
        int cur_col_pre = index - cur_row_pre * c_pre;
        int cur_row = index / c;
        int cur_col = index - cur_row * c;

        int length_pre = c_pre - cur_col_pre;
        int length_lat = c - cur_col;
        int length = length_pre > length_lat ? length_lat : length_pre;
        memcpy(&reshape[cur_row][cur_col], &nums[cur_row_pre][cur_col_pre], sizeof(int) * length);

        index += length;
      }
      
      return reshape;
    }

    static bool equal(vector<vector<int>>& a, vector<vector<int>>& b)
    {
      bool equal = true;

      equal = (a.size() == b.size());
      if (!equal) return false;

      equal = (a[0].size() == b[0].size());
      if (!equal) return false;

      for (int i = static_cast<int>(a.size() - 1); i >= 0; --i)
        for (int j = static_cast<int>(a[0].size() - 1); j >= 0; --j)
        {
          if (a[i][j] == b[i][j])
            continue;
          return false;
        }

      return true;
    }
  };
}

TEST(weekly_contest_30_reshape, correct)
{
  using weekly_contest_30_reshape::Solution;

  Solution sol = Solution();

  vector<vector<int>> nums;
  nums.push_back(vector<int>({ 1, 2 }));
  nums.push_back(vector<int>({ 3, 4 }));

  vector<vector<int>> result;
  result.push_back(vector<int>({ 1, 2, 3, 4 }));

  EXPECT_TRUE(sol.equal(nums, sol.matrixReshape(nums, 2, 4)));
  EXPECT_TRUE(sol.equal(nums, sol.matrixReshape(nums, 2, 2)));
  EXPECT_TRUE(sol.equal(result, sol.matrixReshape(nums, 1, 4)));
}
