//	��ҽ���
//	ʹ�ö�̬�滮�ķ���
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
//	��ҽ���II
//	����ʹ�ö�̬�滮�ķ������ص����ڶԵ�һ��ֵ�Ĳ���
//	1��������0�����͵�size-2����		2��������0�����͵�size-3����	3��������һ�����͵�size-2����	4��������1�����͵�size-3����
//	��һ������������ֵ�в���������������λ��ҲҪ��������
//	0��size-3�м����ٸ�һ�����������Ӧ��ֵΪ0��ͬ����1�����͵�size-3�������ٸ�һ����������ֵΪ0
int Rob(vector<int>& num)
{

}