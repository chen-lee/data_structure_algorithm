#include <iostream>
#include "sort/mergeSort.h"

void merge(vector<int>& data, int start, int mid, int end) {
    vector<int> tmp;
    int i = start;
    int j = mid + 1;
    while(i <= mid && j <= end) {
        if (data[i] <= data[j]) {
            tmp.push_back(data[i++]);
        } else {
            tmp.push_back(data[j++]);
        }
    }
    while (i <= mid) {
        tmp.push_back(data[i++]);
    }
    while (j <= end) {
        tmp.push_back(data[j++]);
    }
    for (int z = 0; z < tmp.size(); ++z) {
        data[z + start] = tmp[z];
    }
}

void merge_test() {
    vector<int> data = {5,6,8,1,3};
    merge(data, 0, 2, 4);
}

void merge_sort(vector<int>& data, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}

// non-recurent method
void merge_sortV2(vector<int>& data) {
    for (int w = 1; w < data.size(); w *=2) {
        int start = 0; int end = w;
        while (start < data.size() - 1) {
            int mid = (start + end) / 2;
            std::cout << start << ":" << mid << " + " << mid + 1 << ":" << end << std::endl;
            merge(data, start, mid, end);
            start += w;
            end += w;
            if (end > data.size() - 1) {
                end = data.size() - 1;
            }
        }
    }
}
