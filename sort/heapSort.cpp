#include <iostream>
#include "sort/heapSort.h"

// 判断子节点是否大于根节点，如果是，则切换顺序; 若根节点的索引是i, 则子节点的索引是2i + 1, 2i + 2 
void heap_adjust(vector<int>& data, int i) {
    int root = data[i];
    // search the max or min value in child node
    for (int j = 2 * i; j < data.size(); j *= 2) {
        if (data[j + 1] < data[j + 2]) {
            ++j;
        }
        if (root >= data[j]) {
            break;
        }
        data[i] = data[j];
        i = j;
    }
    data[i] = root;
}

void heap_sort(vector<int>& data) {
    // 构建初始堆，将给定的无序的序列构建成一个大堆或者小堆
    // 比如将无序序列data: 90 70 80 60 10 40 50 30 20, 将无序的序列构建成一颗完全二叉树
    // 然后从第一非叶子节点开始，构建每个小块的堆，第一个非叶子节点的索引是data.size() / 2 - 1, 依次从左到右，从上到下，也就是从data.size() - 1 -> 0, 这些都是非叶子节点，代码如下：
    for (int i = data.size() / 2 - 1; i >= 0; i--) {
        std::cout << "非叶子节点: " << i << "  开始构建最大堆";
        heap_adjust(data, i);
    }
}

