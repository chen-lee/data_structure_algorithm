#include <iostream>
#include "sort/heapSort.h"

void swap1(vector<int>& data, int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

int partition(vector<int>& data, int low, int high) {
    int midVal = data[low];
    while (low < high) {
        while (low < high && data[low] <= midVal) {
            ++low;
        }
        swap1(data, low, high);
        std::cout << "        swap: " << low << " " << high << std::endl;
        while (low < high && data[high] >= midVal) {
            --high;
        }
        swap1(data, low, high);
        std::cout << "        swap: " << low << " " << high << std::endl;
    }
    return low;
}

void qsort(vector<int>& data, int low, int high) {

    std::cout << "low: " << low << "  high: " << high << ": ";
    for (int i = low; i <= high; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;


    int mid = partition(data, low, high);
    std::cout << "mid: " << mid << std::endl;
    qsort(data, low, mid - 1);
    qsort(data, mid + 1, high);
}

void quick_sort(vector<int>& data) {
    qsort(data, 0, data.size() - 1);
}

