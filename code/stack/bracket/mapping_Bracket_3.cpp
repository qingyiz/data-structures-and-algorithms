/*
*FileName:mapping_Bracket_3.cpp
*FilePath:/home/qyz/Desktop/数据结构与算法/stack
*Time:2021.04.06
*Author:QYZ
*/
/*
*2. 广度扩展
*接下来再来看看如何进行广度扩展。观察题目可以发现，栈中只存放了一个维度的信息：左括号'('和右括号')'。如果栈中的内容变得更加丰富一点，就可以得到下面这道扩展题
*【题目扩展】给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。有效字符串需满足：
*左括号必须用相同类型的右括号闭合
*左括号必须以正确的顺序闭合
*注意空字符串可被认为是有效字符串
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution
{
public:
	bool isValid(string s)
	{
		if (s.length() & 0x01)
		{
			return true;
		}
		stack<char> t;
		for (auto c : s)
		{
			if (c == '(' || c == '[' || c == '{')
			{
				t.push(c);
			}
			else if (c == ')')
			{
				if (t.empty() || t.top() != '(')
				{
					return false;
				}
				t.pop();
			}
			else if (c == ']')
			{
				if (t.empty() || t.top() != '[')
				{
					return false;
				}
				t.pop();
			}
			else if (c == '}')
			{
				if (t.empty() || t.top() != '{')
				{
					return false;
				}
				t.pop();
			}
			else
			{
				return false;
			}
		}
		return t.empty();
	}
};
