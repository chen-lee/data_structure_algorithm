#include "sort/heapSort.h"

void heap_adjust(vector<int>& data, int i) {
    int root = data[i];
    // search the max or min value in child node
    for (int j = 2 * i; j < data.size(); j *= 2) {
        if (data[j] < data[j + 1]) {
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
    // get the max or min heap
    for (int i = data.size() / 2; i >= 0; i--) {
        heap_adjust(data, i);
    }
}

