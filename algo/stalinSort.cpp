#include <iostream>
#include <vector>
using namespace std;
vector<int> stalinSort(const vector<int>& arr) {
    vector<int> result;
    if (!arr.empty()) {
        int maxSoFar = arr[0];
        result.push_back(maxSoFar);

        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] >= maxSoFar) {
                maxSoFar = arr[i];
                result.push_back(arr[i]);
            }
        }
    }
    return result;
}

int main() {
    vector<int> input = {10,20,15,25,5};
    vector<int> sorted = stalinSort(input);

    cout << "Сталински отсортировано: ";
    for (int i =0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
    return 0;
}
