//	三数之和==0
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end(), [](int a, int b) {
		return a < b;
		});
	vector<vector<int>> result;
	if (nums.size() < 3)
		return result;
	if (nums[0] > 0)
		return result;
	int p1 = 0, p2 = 0, p3 = 0;
	while (p1 < nums.size())
	{
		p2 = p1 + 1;
		p3 = nums.size() - 1;
		while (p2 < p3)
		{
			long long sum = nums[p1] + nums[p2] + nums[p3];
			if (sum < 0l)
				p2++;
			else if (sum > 0l)
				p3--;
			else
			{
				result.push_back({ nums[p1],nums[p2],nums[p3] });
				int oldnum = nums[p2];
				while (p2 < p3 && nums[p2] == oldnum)
					p2++;
				oldnum = nums[p3];
				while (p2 < p3 && nums[p3] == oldnum)
					p3--;
			}
		}
		int oldnum = nums[p1];
		while (p1 < nums.size() && nums[p1] == oldnum)
			p1++;
	}
	return result;
}


int main()
{
	vector<int> nums{ -1,0,1,2,-1,-4 };
	threeSum(nums);
	return 1;
}