#include <iostream>
#include <vector>
using namespace std;

void sumOfSubset(vector<int>& nums, int target, vector<int>& curr, int index) {
  if(target == 0) {
    // Target sum found, print current subset
    for(int num : curr) {
      cout << num << '\t';
    }
    cout << endl;
  }else if(index == nums.size() || target < 0) {
    // End of array of target not achievable
    return;
  }else {
    // Explore two branches : included or excluded curr element
    curr.push_back(nums[index]);
    sumOfSubset(nums, target - nums[index], curr, index + 1);
    curr.pop_back();
    sumOfSubset(nums, target, curr, index + 1);
  }
}

int main() {
  vector<int> nums = {1,3,5,7,9};
  int target = 12;
  vector<int> curr;
  sumOfSubset(nums, target, curr, 0);
  return 0;
}
