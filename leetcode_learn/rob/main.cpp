//	打家劫舍
//	使用动态规划的方法
#include<vector>
using namespace std;

int Rob(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return nums[0] > nums[1] ? nums[0] : nums[1];
	int pMax1 = nums[1];
	int pMax2 = nums[0];
	int pMax3 = 0;
	for (int i = 2; i < nums.size(); ++i)
	{
		int temp = pMax1;
		pMax1 = (pMax2 + nums[i]) > (pMax3 + nums[i]) ? (pMax2 + nums[i]) : (pMax3 + nums[i]);
		pMax3 = pMax2;
		pMax2 = temp;
	}
	return pMax1 > pMax2 ? pMax1 : pMax2;
	
}
//	打家劫舍II
//	依旧使用动态规划的方法，重点在于对第一个值的操作
//	1、包含第0个数和第size-2个数		2、包含第0个数和第size-3个数	3、包含第一个数和第size-2个数	4、包含第1个数和第size-3个数
//	解一定在上述几个值中产生，并且上述的位置也要满足条件
//	0和size-3中间至少隔一个数，否则对应的值为0，同理，第1个数和第size-3个数至少隔一个数，否则值为0
int Rob(vector<int>& num)
{

}