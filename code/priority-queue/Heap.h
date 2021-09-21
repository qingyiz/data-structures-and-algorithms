#ifndef __HEAP_H__
#define __HEAP_H__
#include <vector>
#include <iostream>

using namespace std;
#define BIGHEAP 0
#define SMALLHEAP 1

class Heap {

public:
    Heap(int mode = BIGHEAP);
    void push(int v);
    int pop();
    int size();
    void printf_heap();
private:
    // 小堆下沉
     void sink_small(int i);
    // 小堆上浮
    void swim_small(int i);
    // 大堆下沉
    void sink_big(int i);
    // 大堆上浮
    void swim_big(int i);
public: 
    int mode; //堆的类型，默认大堆 ,SMALLHEAP BIGHEAP 大堆
    int n = 0;
    vector<int> a;
};

#endif 