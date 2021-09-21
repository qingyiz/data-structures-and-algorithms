#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
/*
练习题 1：给定一个非空的整数数组，求这个数组的前 k 个高频元素。如果有两个数出现次数一样，那么优先取较小的那个数。
输入：A = [1,2,1,1,3,3,2,3] k = 2
输出：[1, 3]
解释：每个数字的出现频率从高到低排序<1, 3次>, <3,3次> <2, 2次>，取前 2 个高频数字。所以是 [1, 3]。

编译需要加上 -std=c++11
*/




vector<int> topKFrequent_1(vector<int> & A, int k)
{
    
    unordered_map<int, int> H;
    //key为元素值，唯一的，当出现重复值 ++value ,也就是说value值为出现的次数
    for (auto x : A) {
        H[x]++;
    }
    
    auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
        //比较规则，当second也就是次数不相等时，则返回比较次数
        if (a.second != b.second) {
            return b.second < a.second;
        }
        //当次数相同，则比较数的大小
        return b.first < a.first;
    };
    
    // 要出现次数高频的k个，那么要用小堆
    //decltype 类型说明符，cmp什么类型它就是表示什么类型
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> Q(cmp);

    for (auto& p : H) {
        Q.push({p.first, p.second});
        while (Q.size() > k) {
            Q.pop();
        }
    }

    vector<int> ans;
    while (!Q.empty()) {
        ans.push_back(Q.top().first);
        Q.pop();
    }

    sort(ans.begin(), ans.end());

    return ans;
}




struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        //比较规则，当second也就是次数不相等时，则返回比较次数
        if (a.second != b.second) {
            return b.second < a.second;
        }
        //当次数相同，则比较数的大小
        return b.first < a.first;
    }
};
vector<int> topKFrequent_2(vector<int> & A, int k)
{
    
    unordered_map<int, int> H;
    //key为元素值，唯一的，当出现重复值 ++value ,也就是说value值为出现的次数
    for (auto x : A) {
        H[x]++;
    }
    /*
    auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
        //比较规则，当second也就是次数不相等时，则返回比较次数
        if (a.second != b.second) {
            return b.second < a.second;
        }
        //当次数相同，则比较数的大小
        return b.first < a.first;
    };
    */
    // 要出现次数高频的k个，那么要用小堆
    //decltype 类型说明符，cmp什么类型它就是表示什么类型
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q;

    for (auto& p : H) {
        Q.push({p.first, p.second});
        while (Q.size() > k) {
            Q.pop();
        }
    }

    vector<int> ans;
    while (!Q.empty()) {
        ans.push_back(Q.top().first);
        Q.pop();
    }

    sort(ans.begin(), ans.end());

    return ans;
}


int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int> ans = topKFrequent_1(v,2);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    ans = topKFrequent_2(v,2);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
