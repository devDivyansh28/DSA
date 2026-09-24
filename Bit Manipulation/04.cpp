/*
Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.

For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

Example 1:
*/

// class Solution{	
// 	public:		
// 		vector<int> singleNumber(vector<int>& nums){
//             vector<int> ans;
// 			long XOR = 0;
//             for(int i = 0 ; i< nums.size() ; i++){
//                 XOR = XOR ^ nums[i];
//             }
//             int bucket1  = 0;
//             int bucket2 = 0;
//             int diff = (XOR & (XOR-1)) ^ XOR;

//             for(int i = 0 ;i<nums.size();i++){
//                 if(nums[i]&diff){
//                     bucket1 = bucket1 ^ nums[i];
//                 }else{
//                     bucket2 = bucket2^nums[i];
//                 }
//             }
//             ans.push_back(bucket1);
//             ans.push_back(bucket2);
//             sort(ans.begin() , ans.end());
//             return ans;
// 		}
// };