#include <iostream>
#include "sort/mergeSort.h"

template <typename T>
std::string vector2str(vector<T>& data, std::string dim = " ") {
    std::string res = "";
    for (int i = 0; i < data.size() - 1; ++i) {
        res += std::to_string(data[i]) + dim;
    }
    res += std::to_string(data[data.size() - 1]);
    return res;
}

int main() {
    std::vector<int> data = {8,5,6,3,1,9,10,48,47};
    std::cout << "raw data: " << vector2str(data) << std::endl;
    merge_sort(data, 0, data.size() - 1);
    std::cout << "sort data: " << vector2str(data) << std::endl;
    /*
    // with no recursion
    merge_sort(data);
    for (auto ele : data) {
        std::cout << ele << ",";
    }
    std::cout << std::endl;
    */

    return 0;
}
