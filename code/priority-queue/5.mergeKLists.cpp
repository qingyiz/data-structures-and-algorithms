#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*
 * 示例 1：
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 编译需要加上 -std=c++11
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    struct tmp{
        bool operator()(const ListNode *x, const ListNode *y) const{
            return x->val > y->val;
        }
    };
    priority_queue<ListNode *, vector<ListNode *>, struct tmp> Q;
    for(auto &l: lists){
        if (l) Q.push(l);
    }
    ListNode dummy(0), *tail = &dummy;
    while(!Q.empty()){
        auto p = Q.top();
        Q.pop();
        tail->next = p;
        tail = p;
        if (p->next)
            Q.push(p->next);
    }
    tail->next = nullptr;
    return dummy.next;
}

int main()
{
    
    vector<ListNode *> v;
    ListNode * l1 = new ListNode(1);
    ListNode * l2 = new ListNode(4);
    ListNode * l3 = new ListNode(5);
    ListNode * l4 = new ListNode(1);
    ListNode * l5 = new ListNode(3);
    ListNode * l6 = new ListNode(4);
    ListNode * l7 = new ListNode(2);
    ListNode * l8 = new ListNode(6);
    l1->next = l2;
    l2->next = l3;
    l3->next = nullptr;
    l4->next = l5;
    l5->next = l6;
    l6->next = nullptr;
    l7->next = l8;
    l8->next = nullptr;
    v.push_back(l1);
    v.push_back(l4);
    v.push_back(l7);
    ListNode * ans = mergeKLists(v);
    ListNode * tmp = ans;

    while(tmp->next){
        cout << tmp->val ;
        if(tmp->next->next){
            cout << "->";
        }
        tmp = tmp->next;

    }
    cout << endl;
    return 0;
}