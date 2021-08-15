/*
*FileName:mapping_Bracket_3.cpp
*FilePath:/home/qyz/Desktop/数据结构与算法/stack
*Time:2021.04.06
*Author:QYZ
*/

/*
 *代码地址：https://github.com/lagoueduCol/Algorithm-Dryad/blob/main/01.Stack/Example01.cpp
 *栈的应用：括号匹配
 *字符串中只有字符'('和')'。合法字符串需要括号可以配对。比如：
 *输入："()"
 *输出：true
 *解释：()，()()，(())是合法的。)(，()(，(()是非法的。
 *请你实现一个函数，来判断给定的字符串是否合法。
 *复杂度分析：每个字符只入栈一次，出栈一次，所以时间复杂度为 O(N)，而空间复杂度为 O(N)，因为最差情况下可能会把整个字符串都入栈。
 *由于存放的栈中的元素是一样的，其实我们记录的只是一个左括号的个数，所以可以用一个变量来代替栈。
 
*/


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
		stack<char> t;
		for (size_t i = 0; i < s.length(); i++)
		{
			char c = s[i];
			//左括号入栈
			if (c == '(')
			{
				t.push(c);
			}
			//当栈不为空时，右括号消除
			if (c == ')')
			{
				if (t.empty())
				{
					return false;
				}
				t.pop();
			}
		}
		return t.empty();
	}
};

// 下面开始测试

#define ASSERT_EQ(a, b) assert((a) == (b))
#define ASSERT_TRUE(a) assert(true == (a))

static Solution solution;

static void testEmptyString() { ASSERT_TRUE(solution.isValid("")); }
static void testSingleChar()
{
	ASSERT_TRUE(!solution.isValid("("));
	ASSERT_TRUE(!solution.isValid(")"));
}

static void testTwoChars()
{
	ASSERT_TRUE(solution.isValid("()"));
	ASSERT_TRUE(!solution.isValid("(("));
	ASSERT_TRUE(!solution.isValid("))"));
	ASSERT_TRUE(!solution.isValid(")("));
}

static void test3Chars()
{
	ASSERT_TRUE(!solution.isValid("())"));
	ASSERT_TRUE(!solution.isValid("((("));
	ASSERT_TRUE(!solution.isValid(")))"));
	ASSERT_TRUE(!solution.isValid(")()"));
}

static void test4Chars()
{
	ASSERT_TRUE(solution.isValid("()()"));
	ASSERT_TRUE(solution.isValid("(())"));
	ASSERT_TRUE(!solution.isValid("))(("));
}

static void testOther()
{
	ASSERT_TRUE(solution.isValid("()()()"));
	ASSERT_TRUE(solution.isValid("((()))"));
	ASSERT_TRUE(solution.isValid("()(())"));
	ASSERT_TRUE(!solution.isValid("()(()("));
}

static void run()
{
	testEmptyString();
	testSingleChar();
	testTwoChars();
	test3Chars();
	test4Chars();
	testOther();
	printf("Test Over!\n");
}

int main(void)
{
	run();
	return 0;
}