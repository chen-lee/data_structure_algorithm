#include <iostream>
#include "sort/heapSort.h"

void swap1(vector<int>& data, int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
    std::cout << "swapped: ";
    for (auto ele : data) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

int partition(vector<int>& data, int low, int high) {
    int midVal = data[low];
    vector<int> small;
    vector<int> big;
    for (int i = low; i <= high;  ++i) {
        if (data[i] < midVal) small.push_back(data[i]);
        if (data[i] > midVal) big.push_back(data[i]);
    }

    for (auto ele : small) {
        data[low++] = ele;
    }

    for (auto ele : big) {
        data[high--] = ele;
    }

    while (low < high) {
        data[high--] = midVal;
    }
    data[high] = midVal;
    /*
    while (low < high) {
        while (low < high && data[low] < midVal) {
            ++low;
        }
        std::cout << "        swap: " << low << " " << high << std::endl;
        swap1(data, low, high);
        while (low < high && data[high] >= midVal) {
            --high;
        }
        std::cout << "        swap: " << low << " " << high << std::endl;
        swap1(data, low, high);
    }
    */
    return low;
}

void qsort(vector<int>& data, int low, int high) {
    if (low < high) {
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
}

void quick_sort(vector<int>& data) {
    qsort(data, 0, data.size() - 1);
}

