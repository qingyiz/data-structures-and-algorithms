#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*
 *  给定一个点集数组 A[]，求离原点最近的 k 个点。
 *  输入：A = [[0,1], [1,0], [100,1], [1,100]], k = 2
 *  输出：[[0,1], [1,0]]
 *  解释：离原点最近的两个点就是 [[0,1], [1,0]]
 * 
 *  输入：points = [[3,3],[5,-1],[-2,4]], K = 2
 *  输出：[[3,3],[-2,4]]
 * （答案 [[-2,4],[3,3]] 也会被接受。）
*/
vector<vector<int>> kClosest(vector<vector<int>>& A, int K) 
{

    auto dist1 = [&](int64_t x, int64_t y) { return x * x + y * y; };
    //获取距离的平方
    auto dist = [&](const vector<int>& x) { return dist1(x[0], x[1]); };
    const int N = A.size();

    auto cmp = [&](const int a, const int b) {
        return dist(A[a]) < dist(A[b]);   
    };
    priority_queue<int,vector<int>,decltype(cmp)> Q(cmp);
    for(int i = 0; i < N;i++){
        Q.push(i);
        if(Q.size() > K){
            Q.pop();
        }
        
    }

    vector<vector<int>> ans;
        while (!Q.empty()) {
            ans.push_back(A[Q.top()]);
            Q.pop();
        }

    return ans;

}

int main()
{
    vector<vector<int>> v;
    v.push_back({0,311      });
    v.push_back({12,0});
    v.push_back({100,1});
    v.push_back({1,100});
    vector<vector<int>> ans = kClosest(v,2);
    for (int i = 0; i < ans.size();i++){
        cout << "[";
        cout << ans[i][0] << " ";
         cout << ans[i][1] << "]" << " ";
    }
    cout << endl;
    return 0;
}