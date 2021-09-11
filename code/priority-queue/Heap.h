
#include <vector>
#include <iostream>

using namespace std;
class Heap {

public:
    void push(int v);
    int pop();
    int size();
private:
    // 下沉
     void sink(int i);
    // 上浮
    void swim(int i);
private: 
    int n = 0;
    vector<int> a;
};