
/*
*FileName:TreeLevelOrder.cpp
*FilePath:/home/qyz/Desktop/数据结构与算法/FIFO/Tree
*Time:2021.08.08
*Author:QYZ
*/

// 本题测试平台链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
// 代码链接：https://github.com/lagoueduCol/Algorithm-Dryad/blob/main/02.Queue/01.TreeLevelOrder.cpp
/**
 * 【题目】:从上到下按层打印二叉树，同一层结点按从左到右的顺序打印，每一层打印到一行。

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		queue<TreeNode *> Q;
		// 如果结点不为空，那么加入FIFO队列
		// 注意，入队的时候都不能为空
		if (root)
		{
			Q.push(root);
		}

		// ans用于保存层次遍历的结果
		vector<vector<int>> ans;
		while (!Q.empty())
		{
			// 生成新的一层,
			//emplace_back,在容器尾部添加一个元素，这个元素原地构造，不需要触发拷贝构造和转移构造。而且调用形式更加简洁，直接根据参数初始化临时对象的成员。
			ans.emplace_back();
			// 拿到当前层的结点个数
			int qSize = Q.size();
			// 依次取出当前层的结点
			while (qSize--)
			{
				// 照顺序取出当前层的结点
				auto cur = Q.front();
				Q.pop();
				// 把结点值放到当前层
				//back()函数返回最后一个元素的地址，end()返回尾地址，尾地址不指向任何存储的元素，而是标志vector的结束。
				//vector中push_back函数的意思是在vector的末尾插入一个元素
				ans.back().push_back(cur->val);

				// 取出下一层，并且放到队列中。
				if (cur->left)
				{
					Q.push(cur->left);
				}
				if (cur->right)
				{
					Q.push(cur->right);
				}
			}
		}
		return ans;
	}
};