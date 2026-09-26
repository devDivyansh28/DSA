/*
Power Set Bit Manipulation

Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.

Do not include the duplicates in the answer.

Example 1:
Input : nums = [1, 2, 3]

Output : [ [ ] , [1] , [2] , [1, 2] , [3] , [1, 3] , [2, 3] , [1, 2 ,3] ]

Example 2:
Input : nums = [1, 2]

Output : [ [ ] , [1] , [2] , [1, 2] ]
*/

// class Solution {
// public:	
//     vector<vector<int> > powerSet(vector<int>& nums) {
//         int subsets = 1<<nums.size();
//         vector<vector<int>> ans;
//         for(int i=0 ; i<=subsets-1;i++){
//             vector<int> temp;
//             for(int j = 0 ; j<=nums.size()-1 ; j++){
//                 if(i & (1<<j)){
//                       temp.push_back(nums[j]);
//                 }
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };