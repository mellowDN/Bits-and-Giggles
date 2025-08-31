// the following code is probably the worst sorting and searching algorithm ever created
// it is called hail mary sort and hail mary search

#include <bits/stdc++.h>
using namespace std;
void funShuffle(vector<int>& arr) {
    random_device rd;
    mt19937 g(rd());

    for (int i = arr.size() - 1; i > 0; i--) {
        uniform_int_distribution<> dist(0, i);
        int j = dist(g);
        swap(arr[i], arr[j]);
    }
}

bool isSorted(vector<int>& nums){
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i]>nums[i+1]) return 0;
    }
    return 1;
}

void hailMarySort(vector<int>& nums){
    while(!isSorted(nums)){
        funShuffle(nums);
    }
}

int hailMarySearch(vector<int>& nums, int target) {
    int size = nums.size();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, size-1);

    unordered_set<int> visited; 
    int attempts = 0;
    int random;

    while (visited.size() < size) {
        random = dist(gen);
        attempts++;

        if (nums[random] == target) {
            cout << "Found in " << attempts << " attempts!" << endl;
            return random;
        }

        visited.insert(random); 
    }

    return -1; 
}

int main() {
    vector<int> nums;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    hailMarySort(nums);
    int index = hailMarySearch(nums, 2);
    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found!" << endl;
        

    return 0;
}
