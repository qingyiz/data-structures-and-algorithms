#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
练习题 2：在练习题1的基础上，给定的是一个单词数组，求这个数组前 k 个高频单词。如果有两个单词出现频率是一样的。那么输出字典序较小的那个单词。
输入：A = ["AA", "BB", "AA", "BB", "CCC", "CCC", "CCC", "AA"] k = 2
输出：["AA", "CCC"]
解释：出现次数最多的 2 个单词就是["AA", "CCC"]

编译需要加上 -std=c++11
*/




vector<string> topKFrequent_1(vector<string> & A, int k)
{
    
    unordered_map<string, int> H;
    //key为元素值，唯一的，当出现重复值 ++value ,也就是说value值为出现的次数
    for (auto x : A) {
        H[x]++;
    }
    
    auto cmp = [&](const pair<string, int>& a, const pair<string, int>& b) {
        //比较规则，当second也就是次数不相等时，则返回比较次数
        if (a.second != b.second) {
            return b.second < a.second;
        }
        //当次数相同，则比较数的大小
        // 如果出现次数相同
        // 那么字典序小的要排在前面
        // 按理说应该就是 b.first < a.first;
        // 但是，由于后面还有reverse(ans.begin(), ans.end());
        // 所以这里需要用a.first < b.first;
        return a.first < b.first;
    };
    
    // 要出现次数高频的k个，那么要用小堆
    //decltype 类型说明符，cmp什么类型它就是表示什么类型
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> Q(cmp);

    for (auto& p : H) {
        Q.push({p.first, p.second});
        while (Q.size() > k) {
            Q.pop();
        }
    }

    vector<string> ans;
    while (!Q.empty()) {
        ans.push_back(Q.top().first);
        Q.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}




struct cmp
{
    bool operator()(const pair<string, int>& a, const pair<string, int>& b)
    {
        //比较规则，当second也就是次数不相等时，则返回比较次数
        if (a.second != b.second) {
            return b.second < a.second;
        }
        //当次数相同，则比较数的大小
        return a.first < b.first;
    }
};
vector<string> topKFrequent_2(vector<string> & A, int k)
{
    
    unordered_map<string, int> H;
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
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> Q;

    for (auto& p : H) {
        Q.push({p.first, p.second});
        while (Q.size() > k) {
            Q.pop();
        }
    }

    vector<string> ans;
    while (!Q.empty()) {
        ans.push_back(Q.top().first);
        Q.pop();
    }

    sort(ans.begin(), ans.end());

    return ans;
}


int main()
{
    vector<string> v;
    v.push_back("AA");
    v.push_back("BB");
    v.push_back("AA");
    v.push_back("BB");
    v.push_back("CCC");
    v.push_back("CCC");
    v.push_back("CCC");
    v.push_back("AA");
    vector<string> ans = topKFrequent_1(v,2);
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
