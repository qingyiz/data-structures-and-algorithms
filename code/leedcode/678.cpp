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
678. 有效的括号字符串
给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

任何左括号 ( 必须有相应的右括号 )。
任何右括号 ) 必须有相应的左括号 ( 。
左括号 ( 必须在对应的右括号之前 )。
 * 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。 
一个空字符串也被视为有效字符串。
	示例 1:
	输入: "()"
	输出: True
	示例 2:
	输入: "(*)"
	输出: True
	示例 3:	
	输入: "(*))"
	输出: True

*/

class Solution
{
public:
	bool checkValidString(string s)
	{
		//为空或者长度为0
		if (s.empty())
			return true;
		if (s.length() % 2 == 1)
			return false;
		stack<char> t;
		for (size_t i = 0; i < s.length(); i++)
		{
			char c = s[i];
			if (c == '(' || c == '*')
			{
				t.push(c);
			}
			if (c == ')')
			{
				if (t.empty())
					return false;
				t.pop();
			}
		}
		return (t.empty() ? true : (t.top() == '*'));
	}
};

