#include "Heap.h"
#include <iostream>

using namespace std;

int main()
{
    Heap * heap = new Heap(BIGHEAP);
    
    heap->push(3);
    
    heap->push(6);
    heap->push(2);
    heap->push(7);
    heap->push(8);
    heap->push(1);
    heap->printf_heap();
    

    
    return 0;
}
