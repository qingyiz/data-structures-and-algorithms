#include <iostream>
#include "Heap.h"
#include <vector>
using namespace std;


/*
给定一个数组 a[]，返回这个数组中最小的 k 个数。
输入：A = [3,2,1], k = 2
输出：[2, 1]
*/

vector<int> getLeastNumbers(vector<int> & arr, int k)
{
    Heap *heap = new Heap();
    if(k <= 0 || arr.empty() ){
        return {};
    }
    if(arr.size() == k){
        return arr;
    }

    for(int x = 0; x < arr.size();x++){
    //for(auto x: arr){
        heap->push(arr[x]);
        //heap->push(x);
        while(heap->size() > k){            
            heap->pop();
        }
    }
    heap->printf_heap();
    vector<int> ans;

    while (heap->size()) {
        ans.push_back(heap->pop());
    }
    
    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(10);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(9);
    v.push_back(5);
    v.push_back(12);
    vector<int> ans = getLeastNumbers(v,10);
    cout << "["<<" ";
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout <<"]"<< endl;


    return 0;

}