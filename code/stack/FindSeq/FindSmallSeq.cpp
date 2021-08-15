#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
/*
*【题目】给定一个正整数数组和 k，要求依次取出 k 个数，输出其中数组的一个子序列，需要满足：1. 长度为 k；2.字典序最小。
*输入：nums = [3,5,2,6], k = 2
*输出：[2,6]
*解释：在所有可能的解：{[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]} 中，[2,6] 字典序最小。
*所谓字典序就是，给定两个数组：x = [x1,x2,x3,x4]，y = [y1,y2,y3,y4]，如果 0 ≤ p < i，xp == yp 且 xi < yi，那么我们认为 x 的字典序小于 y。

*/

//代码地址:https://github.com/lagoueduCol/Algorithm-Dryad/blob/main/01.Stack/Example04.cpp
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findSmallSeq(vector<int> &nums, int k) {
    if (nums.empty()) {
        return {};
    }
    vector<int> ans(k);
    stack<int> s;

    // 这里生成单调栈
    for (size_t i = 0; i < nums.size(); i++) {
        const int x = nums[i];
        const int left = nums.size() - i;
        // 注意我们想要提取出k个数，所以注意控制扔掉的数的个数
        while (!s.empty() && ((int)s.size() + left > k) && s.top() > x) {
            s.pop();
        }
        s.push(x);
    }

    // 如果递增栈里面的数太多，那么我们只需要取出前k个就可以了。
    // 多余的栈中的元素需要扔掉。
    while ((int)s.size() > k) {
        s.pop();
    }

    // 把k个元素取出来，注意这里取的顺序!
    for (int i = k - 1; i >= 0; i--) {
        ans[i] = s.top();
        s.pop();
    }

    return ans;
}

// 测试代码
void ASSERT_EQ(vector<int> A, vector<int> B, int k) {
    auto C = findSmallSeq(B, k);
    assert(A == C);
}

int main(void) {
    ASSERT_EQ({1, 2, 3}, {9, 2, 4, 5, 1, 2, 6, 3, 100, 4}, 3);
    ASSERT_EQ({1, 2}, {9, 2, 4, 5, 1, 2, 6, 3, 100, 4}, 2);
    ASSERT_EQ({1}, {9, 2, 4, 5, 1, 2, 6, 3, 100, 4}, 1);
    ASSERT_EQ({1}, {1, 1, 1, 1}, 1);
    ASSERT_EQ({1, 1}, {1, 1, 1, 1}, 2);
    ASSERT_EQ({1, 1, 1}, {1, 1, 1}, 3);
    return 0;
}
