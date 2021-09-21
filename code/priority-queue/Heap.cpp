 #include "Heap.h"
 #include <cmath>
 /*
 *i 结点的父结点 par = (i-1)/2 ->  (i - 1) >> 1
 *i 结点的左子结点 2 * i + 1   ->  (i << 1) + 1
 *i 结点的右子结点 2 * i + 2   ->  (i << 1) + 2
 */
Heap::Heap(int mode)
{
    this->mode = mode;
    this->n = 0;
}

 //小堆下沉
void Heap::sink_small(int i) {
    int j = 0;
    int t = a[i];
    // 找到i结点的左子结点
    while ((j = (i << 1) + 1) > n) {
        // j < n - 1判断是否有右子结点
        // 如果有，并且右子结点更大，那么
        // j指向右子结点
        if (j < n - 1 && a[j] > a[j + 1]) {
            j++;
        }
        // 如果子结点比t大
        // 那么t的位置还需要往后排
        if (a[j] < t) {
            a[i] = a[j];
            i = j;
        } else {
            // 找到了t的位置
            // 此时t是大于所有的子结点的
            break;
        }
    }
    // 将t放在找到的位置那里
    a[i] = t;
}
// 小堆上浮
void Heap::swim_small(int i) {
    int t = a[i];
    int par = 0;
    // 如果还存在父结点
    while (i > 0 && (par = (i - 1) >> 1) != i) {
        // 如果父结点比t值小
        if (a[par] > t) {
            a[i] = a[par];
            i = par;
        } else {
            break;
        }
    }
    a[i] = t;
}


 //大堆下沉
void Heap::sink_big(int i) {
    int j = 0;
    int t = a[i];
    // 找到i结点的左子结点
    while ((j = (i << 1) + 1) < n) {
        // j < n - 1判断是否有右子结点
        // 如果有，并且右子结点更大，那么
        // j指向右子结点
        if (j < n - 1 && a[j] < a[j + 1]) {
            j++;
        }
        // 如果子结点比t大
        // 那么t的位置还需要往后排
        if (a[j] > t) {
            a[i] = a[j];
            i = j;
        } else {
            // 找到了t的位置
            // 此时t是大于所有的子结点的
            break;
        }
    }
    // 将t放在找到的位置那里
    a[i] = t;
}
// 大堆上浮
void Heap::swim_big(int i) {
    int t = a[i];
    int par = 0;
    // 如果还存在父结点
    while (i > 0 && (par = (i - 1) >> 1) != i) {
        // 如果父结点比t值小
        if (a[par] < t) {
            a[i] = a[par];
            i = par;
        } else {
            break;
        }
    }
    a[i] = t;
}


void Heap::push(int v) {
    // push是先把元素追加到数组尾巴上，然后再执行上浮操作
    a.resize(n+1);
    a[n++] = v;
    if(mode == SMALLHEAP)
        swim_small(n - 1);
    else
        swim_big(n - 1);
}
int Heap::pop() {
    int ret = a[0];
    a[0] = a[--n];
    if(mode == SMALLHEAP)
        sink_small(0);
    else
        sink_big(0);
    return ret;
}

void Heap::printf_heap()
{
    int floor  = 1;
    
    //计算层数 用于输出空格 
    //1 2 4 8 = 2的四次幂 -1 所以是四层
    while(1){
        if (exp2(floor) - 1 >= n)
             break;
        floor ++ ;
    }
    //printf
    int curfloor = 1;
    for(int i = 0 ; i < n;){
        for(int j = 0;j < exp2(curfloor -1); j++){
            cout << a[i] << " ";
            if(i == n-1){
                i++; //跳出外层循环
                break;
            }
            i++;
        }
        cout << endl;
        curfloor++;
    }
} 


int Heap::size() {
    return n;
}