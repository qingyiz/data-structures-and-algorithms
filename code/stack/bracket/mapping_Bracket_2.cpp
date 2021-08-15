#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
*FileName:mapping_Bracket_3.cpp
*FilePath:/home/qyz/Desktop/数据结构与算法/stack
*Time:2021.04.06
*Author:QYZ
*/
/*
*1. 深度扩展
*如果仔细观察，你会发现，栈中存放的元素是一样的。全部都是左括号'('，除此之外，再也没有别的元素，优化方法如下。
*栈中元素都相同时，实际上没有必要使用栈，只需要记录栈中元素个数。
*/

/*
 *代码地址：https://github.com/lagoueduCol/Algorithm-Dryad/blob/main/01.Stack/Example01_D.cpp
 *栈的应用：括号匹配
 *字符串中只有字符'('和')'。合法字符串需要括号可以配对。比如：
 *输入："()"
 *输出：true
 *解释：()，()()，(())是合法的。)(，()(，(()是非法的。
 *请你实现一个函数，来判断给定的字符串是否合法。
 *复杂度分析：时间复杂度为 O(N)，而空间复杂度为 O(1)，因为最差情况下可能会把整个字符串都遍历一遍。
*/
class Solution
{
public:
	bool isValid(string s)
	{
		//为空或者长度为0
		if (s.empty())
			return true;
		//为奇数时
		if (s.length() % 2 == 1)
			return false;
		int leftBraceNumber = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			char c = s[i];
			//左括号入栈
			if (c == '(')
			{
				leftBraceNumber++;
			}
			//当栈不为空时，右括号消除
			if (c == ')')
			{
				if (leftBraceNumber == 0)
				{
					return false;
				}
				leftBraceNumber--;
			}
		}
		return leftBraceNumber == 0;
	}
};

static Solution solution;

static void testEmptyString() { assert(solution.isValid("")); }

static void testSingleChar()
{
	assert(!solution.isValid("("));
	assert(!solution.isValid(")"));
}

static void testTwoChars()
{
	assert(solution.isValid("()"));
	assert(!solution.isValid("(("));
	assert(!solution.isValid("))"));
	assert(!solution.isValid(")("));
}

static void test3Chars()
{
	assert(!solution.isValid("())"));
	assert(!solution.isValid("((("));
	assert(!solution.isValid(")))"));
	assert(!solution.isValid(")()"));
}

static void test4Chars()
{
	assert(solution.isValid("()()"));
	assert(solution.isValid("(())"));
	assert(!solution.isValid("))(("));
}

static void testOther()
{
	assert(solution.isValid("()()()"));
	assert(solution.isValid("((()))"));
	assert(solution.isValid("()(())"));
	assert(!solution.isValid("()(()("));
}

static void run()
{
	testEmptyString();
	testSingleChar();
	testTwoChars();
	test3Chars();
	test4Chars();
	testOther();
	printf("test over\n");
}

int main(void)
{
	run();
	return 0;
}