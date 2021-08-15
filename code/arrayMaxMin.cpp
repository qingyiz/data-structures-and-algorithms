#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;


/*
* 编写一个函数，实现从数组中取出最大值与最小值
* 
*/


class Solution
{
public:
	void findMaxMinNnmber(vector<int> A, int left, int right, int &max, int &min)
	{
		if (right == left)
		{
			max = min = A[left];
		}
		else if (right - left == 1)
		{
			A[left] > A[right] ? (max = A[left], min = A[right]) : (max = A[right], min = A[left]);
		}
		else
		{
			int mid = (right + left) / 2;
			int lmax, lmin, rmax, rmin;
			this->findMaxMinNnmber(A, left, mid, lmax, lmin);
			this->findMaxMinNnmber(A, mid + 1, right, rmax, rmin);
			max = lmax > rmax ? lmax : rmax;
			min = lmin < rmin ? lmin : rmin;
		}
	}
};

static Solution solution;

// 测试代码
void ASSERT_EQ(vector<int> A, vector<int> B)
{
	int max, min, right;
	right = A.capacity() - 1;
	solution.findMaxMinNnmber(A, 0, right, max, min);
	vector<int> ans{min, max};
	assert(B == ans);
}
static void run()
{
	ASSERT_EQ({1}, {1, 1});
	ASSERT_EQ({1, 5, 4, 3, 0, 9, 7}, {0, 9});
	ASSERT_EQ({2, 5, 6, -1, 8, 4, 9, 3, 6, 2, 1, 7, 12, 8}, {-1, 12});
}
int main(void)
{
	run();
	return 0;
}
