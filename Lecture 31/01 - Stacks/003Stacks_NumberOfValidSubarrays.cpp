#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int validSubarrays(vector<int>& nums) {

   vector<int> out; // to track the indices of nearest smaller element to the right
   stack<pair<int, int>> s; // <value,index>
   int n = nums.size();

   for (int i = n - 1; i >= 0; i--) {

      // find the index of the nearest smaller element to the right of nums[i]

      while (!s.empty() and s.top().first >= nums[i]) {
         s.pop();
      }

      if (s.empty()) {
         // nums[i] doesn't have a smaller element to its right
         out.push_back(n);
      } else {
         out.push_back(s.top().second);
      }

      s.push({nums[i], i});

   }

   int count = 0;

   for (int i = 0; i < n; i++) {

      count += out[i] - i;

   }

   return count;

}

int main() {

   vector<int> nums = {1, 4, 2, 5, 3, 9};

   cout << validSubarrays(nums) << endl;

}