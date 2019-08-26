#include <iostream>
#include "sort/mergeSort.h"

int main() {
    std::vector<int> data = {5,5,6,3,1,9,10,48};
    merge_sort(data, 0, data.size() - 1);
    for (auto ele : data) {
        std::cout << ele << ",";
    }
    std::cout << std::endl;
    return 0;
}
