#include <iostream>
#include <stack>
#include <vector>
#include <assert.h>

using namespace std;

/*
 * 题目：给定一个数组，要找到这个数组里面每个元素左边比我小的元素的位置
 * - 注意：是左边第一个比我小的，如果有多个的话
 * - 如果没有，那么用-1表示。
 *
 * 返回：一个数组，表示左边比我小的数的下标位置
 *
 * 输入：[5, 6]
 * 输出：[-1, 0]
 * 解释：A[0] = 5，左边比我小的元素没有, 所以记录为 = -1
 *       A[1] = 6, 左边比我小的元素为A[0] = 5，所以记录为   = 0
 *       所以返回值是[-1, 0]
 */
//代码地址：https://github.com/lagoueduCol/Algorithm-Dryad/blob/main/01.Stack/%E5%B7%A6%E8%BE%B9%E7%AC%AC%E4%B8%80%E4%B8%AA%E6%AF%94%E6%88%91%E5%B0%8F.cpp

vector<int> findLeftSmall(vector<int> &A)
{
	if (A.empty())
		return {};
	// 注意，栈中的元素记录的是下标
	const int N = A.size();
	vector<int> ans(N);
	// 注意，栈中的元素记录的是下标	
	stack<int> t;

	// 注意这里的遍历方向发生了变化，因为我们是要找到左边比我小的元素的位置
	for (int i = N - 1; i >= 0; i--)
	{
		const int x = A[i];
		// 每个元素都遍历栈中的元素完成消除动作
		// 这里是递减栈
		// 如果发现进来的元素x与栈中元素相比
		// 如果大于栈中的元素，那么要把栈中的元素弹出去
		while (!t.empty() && A[t.top()] > x)
		{
			ans[t.top()] = i;
			t.pop();
		}
		t.push(i);
	}

	while (!t.empty())
	{
		ans[t.top()] = -1;
		t.pop();
	}
	return ans;
}

// 测试代码
void ASSERT_EQ(vector<int> A, vector<int> B)
{
	auto C = findLeftSmall(B);
	assert(A == C);
}

int main(void)
{
	ASSERT_EQ({-1, 0}, {5, 6});
	ASSERT_EQ({-1,0,-1,2,-1,4},{5,6,4,5,2,3});
	return 0;
}
