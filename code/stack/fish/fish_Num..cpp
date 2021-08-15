/*
*FileName:mapping_Bracket_3.cpp
*FilePath:/home/qyz/Desktop/数据结构与算法/stack
*Time:2021.04.06
*Author:QYZ
*/

// 测试链接：https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/start/
// 代码链接: https://github.com/lagoueduCol/Algorithm-Dryad/blob/main/01.Stack/Fish.cpp

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
//constexpr表示这玩意儿在编译期就可以算出来（前提是为了算出它所依赖的东西也是在编译期可以算出来的）。
//而const只保证了运行时不直接被修改（但这个东西仍然可能是个动态变量）

//复杂度分析：每只鱼只入栈一次，出栈一次，所以时间复杂度 为 O(N)，而空间复杂度为 O(N)，因为最差情况下可能把所有的鱼都入栈。

int solution(vector<int> &Size, vector<int> &Dir)
{
	// 首先拿到鱼的数量
	// 如果鱼的数量小于等于1，那么直接返回鱼的数量
	const int fishNumber = A.size();
	if (fishNumber <= 1)
		return fishNumber;
	// 0表示鱼向左游
	constexpr int left = 0;
	// 1表示鱼向右游
	constexpr int right = 1;

	//该解决方案使用栈是用来存放索引，而不是数据
	stack<int> t;
	for (int i = 0; i < fishNumber; i++)
	{
		// 当前鱼的情况：1，游动的方向；2，大小
		const int S = Size[i];
		const int D = Dir[i];
		// 当前的鱼是否被栈中的鱼吃掉了
		bool has_eat = false;
		// 如果栈中还有鱼，并且栈中鱼向右，当前的鱼向左游，那么就会有相遇的可能性
		while (!t.empty() && Dir[t.top()] == right && D == left){
			// 如果栈顶的鱼比较大，那么把新来的吃掉
			if(Size[t.top()] > S){
				has_eat = true;
				break;
			}
			// 如果栈中的鱼较小，那么会把栈中的鱼吃掉，栈中的鱼被消除，所以需要弹栈。
			t.pop();
		}
		 // 如果新来的鱼，没有被吃掉，那么压入栈中。
		if(has_eat)
			continue;
		t.push(i);
	}
	return t.size();
}