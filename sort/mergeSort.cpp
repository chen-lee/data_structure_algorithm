#include "sort/mergeSort.h"


void merge(vector<int>& data, int start, int mid, int end) {
    vector<int> tmp;
    int i = start;
    int j = mid + 1;
    while(i != mid + 1 && j != end + 1) {
        if (data[i] <= data[j]) {
            tmp.push_back(data[i++]);
        } else {
            tmp.push_back(data[j++]);
        }
    }
    while (i != mid + 1) {
        tmp.push_back(data[i++]);
    }
    while (j != end + 1) {
        tmp.push_back(data[j++]);
    }
    for (int z = 0; z < tmp.size(); ++z) {
        data[z] = tmp[z];
    }
}

void merge_sort(vector<int>& data, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}

