#include <vector>
#include <map>
#include <string>
#include <set>

#include <gtest/gtest.h>

using std::vector;
using std::map;
using std::string;
using std::set;

namespace
{
  class Solution
  {
  public:
    int distributeCandies(vector<int>& candies)
    {
      set<int> candy_values;
      
      size_t counts = candies.size();
      for (size_t i = 0; i < counts; ++i)
        candy_values.insert(candies[i]);

      size_t half_counts = counts >> 1;
      return static_cast<int>(std::min(half_counts, candy_values.size()));
    }
  };
}

TEST(weekly_contest_31_distribute, correct)
{
  Solution sol = Solution();

  vector<int> data1 = vector<int>({ 1,1,2,2,3,3 });
  EXPECT_EQ(sol.distributeCandies(data1), 3);

  vector<int> data2 = vector<int>({ 1,1,2,3 });
  EXPECT_EQ(sol.distributeCandies(data2), 2);

  vector<int> data3 = vector<int>({ 1,1,1,3,3,3 });
  EXPECT_EQ(sol.distributeCandies(data3), 2);
}

