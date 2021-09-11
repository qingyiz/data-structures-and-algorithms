#include <iostream>
#include "Heap.h"
#include <vector>
using namespace std;

vector<int> getLeastNumbers(vector<int> & arr, int k)
{
    Heap *heap = new Heap();
    if(k <= 0 || arr.empty() ){
        return {};
    }
    if(arr.size() == k){
        return arr;
    }
    heap->a.resize(k+1);
    heap->n = 0;
    for(int x = 0; x < arr.size();x++){
    //for(auto x: arr){
        heap->push(arr[x]);
        while(heap->size() > k){
            heap->pop();
        }
    }
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
    vector<int> ans = getLeastNumbers(v,9);
    cout << "["<<" ";
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout <<"]"<< endl;
    return 0;

}