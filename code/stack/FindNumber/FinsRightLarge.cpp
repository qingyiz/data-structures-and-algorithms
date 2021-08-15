#include <iostream>
#include <stack>
#include <vector>
#include <assert.h>

using namespace std;

/*
*【题目】一个整数数组 A，找到每个元素：右边第一个比我大的下标位置，没有则用 -1 表示。
* 输入：[2, 5]
* 输出：[1, -1]
* 解释：因为元素 5 的右边离我最近且比我大的位置应该是 A[1]，最后一个元素 5 右边没有比 5 大的元素，所以应该输出 -1。
*/
//代码地址：https://github.com/lagoueduCol/Algorithm-Dryad/blob/main/01.Stack/%E5%8F%B3%E8%BE%B9%E7%AC%AC%E4%B8%80%E4%B8%AA%E6%AF%94%E6%88%91%E5%A4%A7.cpp

vector<int> findRightLarge(vector<int> &A)
{
	if (A.empty())
		return {};

	int len = A.size();
	vector<int> ans(len);
	// 注意，栈中的元素记录的是下标
	stack<int> t;
	for (size_t i = 0; i < len; i++)
	{
		const int x = A[i];
		// 每个元素都向左遍历栈中的元素完成消除动作
		while (!t.empty() && A[t.top()] < x)
		{
			// 消除的时候，记录一下被谁消除了
			ans[t.top()] = i;
			// 消除时候，值更大的需要从栈中消失
			t.pop();
		}
		// 剩下的入栈
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
void ASSERT_EQ(vector<int> A, vector<int> B) {
  auto C = findRightLarge(B);
  assert(A == C);
}

int main(void) {
  ASSERT_EQ({1, -1}, {2, 5});
  ASSERT_EQ({1,4,3,4,5,-1},{3,4,1,2,5,6});
  ASSERT_EQ({1,4,3,4,-1},{2,4,1,4,6});

  return 0;
}