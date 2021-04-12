//	因子只有2、3、5的数被称作丑数
#include <set>
#include <algorithm>
#include "vector"

//	查找第n个丑数(使用set)
int FindChouShu(int n);

//	查找第n个丑数(使用动态规划)
int FindChouShu2(int n);

int main()
{
	FindChouShu2(10);
	return 1;
}

int FindChouShu(int n)
{
	//	在32位系统中long会产生溢出问题
	std::set<long> setBackup;
	long lResult;
	setBackup.insert(1l);
	int iPos = 0;
	while (iPos != n)
	{
		lResult = *(setBackup.begin());
		long lAddNum = lResult * 2;
		if (!setBackup.count(lAddNum))
			setBackup.insert(lAddNum);
		lAddNum = lResult * 3;
		if (!setBackup.count(lAddNum))
			setBackup.insert(lAddNum);
		lAddNum = lResult * 5;
		if (!setBackup.count(lAddNum))
			setBackup.insert(lAddNum);
		setBackup.erase(setBackup.begin());
	}
	return (int)lResult;
}

int FindChouShu2(int n)
{
// 	if (n == 1)
// 		return 1;
// 	int iResult1 = 1, iResult2 = 1, iResult3 = 1;
// 	int iPos = 1;
// 	int iMin = 1;
// 	while (iPos != n)
// 	{
// 		int iNext1 = iResult1 * 2, iNext2 = iResult2 * 3, iNext3 = iResult3 * 5;
// 		iMin = std::min(std::min(iNext1, iNext2), iNext3);
		//	这样赋值会跳过一些丑数，造成结果错误
// 		if (iMin == iNext1)
// 			iResult1 = iNext1;
// 		if(iMin == iNext2)
// 			iResult2 = iNext2;
// 		if (iMin == iNext3)
// 			iResult3 = iNext3;
// 		iPos++;
// 	}
	std::vector<int> vecBackup;
	vecBackup.resize(n + 1);
	vecBackup.push_back(1);
	auto itr2 = vecBackup.begin(), itr3 = vecBackup.begin(), itr5 = vecBackup.begin();
	for (int i = 1; i < n; ++i)
	{
		int iNext2 = (*itr2) * 2, iNext3 = (*itr3) * 3, iNext5 = (*itr5) * 5;
		int iMin = std::min(std::min(iNext2, iNext3), iNext5);
		vecBackup.push_back(iMin);
		if (iMin == iNext2)
			++itr2;
		else if (iMin == iNext3)
			++itr3;
		else if (iMin == iNext5)
			++itr5;
	}
	return vecBackup[n-1];
}