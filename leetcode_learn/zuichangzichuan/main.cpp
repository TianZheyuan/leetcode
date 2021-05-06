//	无重复字符的最长子串
#include "string"
#include "vector"
#include "map"

class Solution
{
public:
	int lengthOfLongestSubstring(std::string s)
	{
		std::map<char,int> vec_pos;
		int start = -1;		//	当前的start位置
		int result = 0;		
		for (int i = 0; i < s.length(); ++i)
		{
			auto itr = vec_pos.find(s[i]);
			if (itr != vec_pos.end())
			{
				if (itr->second > start)
					start = itr->second;
				else
					result = i - start > result ? i - start : result;
				itr->second = i;
			}
			else
			{
				vec_pos.insert(std::pair<char, int>(s[i], i));
				result = i - start > result ? i - start : result;
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	s.lengthOfLongestSubstring("");
}