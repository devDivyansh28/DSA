class Solution {
    private:
    void func(int index , vector<int>& nums , int sum , vector<int>&ans){
        if(index==nums.size()){
           
             ans.push_back(sum);
              return;
        }
        sum+=nums[index];
        func(index+1,nums,sum,ans);
        sum-=nums[index];
        func(index+1,nums,sum,ans);
        return;
    }
  public:
    vector<int> subsetSums(vector<int>& nums) {
       vector<int>ans;
       int sum = 0;
       func(0,nums,sum,ans);
       return ans;
    }
};