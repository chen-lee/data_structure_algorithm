#include <iostream>
#include "sort/heapSort.h"

// 判断子节点是否大于父节点，如果是，则切换顺序; 若父节点的索引是i, 则子节点的索引是2i + 1, 2i + 2 
void heap_adjust(vector<int>& data, int i, int len) {
    int node = data[i];  // current node
    // search the max or min value in child node
    // child node index 2i + 1, 2i + 2
    for (int j = 2 * i + 1; j < len; j = 2 * j + 1) {  // 从当前节点的左子节点开始
        if (j + 1 < len && data[j] < data[j + 1]) { // 若左子节点的值小于右子节点，则让j指向右子节点
            ++j;
        }
        if (node >= data[j]) {  // 比较最大的子节点值和当前节点的值，如果当前节点的值大于或等于最大子节点的值说明不用进行堆调整，直接退出即可
            break;
        }
        data[i] = data[j];  // 否则需要将最大子节点的值更新当前节点
        i = j;
    }
    data[i] = node;
    for (auto ele : data) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

void swap(vector<int>& data, int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
    std::cout << "swap: ";
    for (auto ele : data) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

void heap_sort(vector<int>& data) {
    // 构建初始堆，将给定的无序的序列构建成一个大堆或者小堆
    // 比如将无序序列data: 90 70 80 60 10 40 50 30 20, 将无序的序列构建成一颗完全二叉树
    // 然后从第一非叶子节点开始，构建每个小块的堆，第一个非叶子节点的索引是data.size() / 2 - 1, 依次从左到右，从上到下，也就是从data.size() - 1 -> 0, 这些都是非叶子节点，代码如下：
    for (int i = data.size() / 2 - 1; i >= 0; i--) {
        std::cout << "非叶子节点: " << i << "  开始构建最大堆" << std::endl;
        heap_adjust(data, i, data.size());
    }

    std::cout << "heap end, start sort ... ..." << std::endl;
    // 调整堆结构，交换堆顶与末尾元素
    for (int i = data.size() - 1; i >= 0; i--) {
        swap(data, 0, i);
        std::cout << "swap: " << 0 << "   " << i << std::endl;
        heap_adjust(data, 0, i);
    }
}

