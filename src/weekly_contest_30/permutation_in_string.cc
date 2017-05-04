#include <string>
#include <gtest/gtest.h>

using std::string;


namespace weekly_contest_30_permutation
{
  class Solution
  {
  public:
    bool checkInclusion(string s1, string s2)
    {
      int count_char[26] = { 0 };
      
      size_t length_s1 = s1.length();
      size_t length_s2 = s2.length();
      if (length_s1 > length_s2)
        return false;

      for (size_t i = 0; i < length_s1; ++i)
      {
        count_char[s1[i] - 'a']++;
        count_char[s2[i] - 'a']--;
      }

      int count_not_zero = 0;
      for (int i = 0; i < 26; ++i)
      {
        if (count_char[i])
          count_not_zero++;
      }

      int inclusion = count_not_zero ? 0 : 1;

      size_t start = 0;
      size_t end = length_s1;
      while (end < length_s2)
      {
        int count_start = ++count_char[s2[start] - 'a'];
        if (count_start == 0)
          count_not_zero--;
        if (count_start == 1)
          count_not_zero++;

        int count_end = --count_char[s2[end] - 'a'];
        if (count_end == 0)
          count_not_zero--;
        if (count_end == -1)
          count_not_zero++;

        if (!count_not_zero)
          inclusion++;

        start++;
        end++;
      }

      return inclusion > 0;
    }
  };
}

TEST(weekly_contest_30_permutation, correct)
{
  using weekly_contest_30_permutation::Solution;

  Solution sol = Solution();

  EXPECT_EQ(sol.checkInclusion("ab", "eidbaooo"), true);
  EXPECT_EQ(sol.checkInclusion("ab", "eidboaoo"), false);
  EXPECT_EQ(sol.checkInclusion("ab", "baceicoa"), true);
  EXPECT_EQ(sol.checkInclusion("ab", "a"), false);
}
