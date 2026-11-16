/*
Given an array of nums of n integers. Every integer in the array appears twice except one integer. Find the number that appeared once in the array.

*/

// class Solution{    
// public:    
//     int singleNumber(vector<int>& nums){
//          int num = nums[0];
//          for(int i = 1 ; i< nums.size() ; i++){
//             num = num ^ nums[i];
//          }
//          return num;
//     }
// };