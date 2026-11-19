class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Set to store unique triplets
        set<vector<int>> tripletSet;

        int n = nums.size();

        // Check all possible triplets
        for (int i = 0; i < n; i++) {
            // Set to store elements seen so far in the loop
            set<int> hashset;

            for (int j = i + 1; j < n; j++) {
                // Calculate the 3rd element needed to reach target
                int third = - (nums[i] + nums[j]);

                /* Find if third element exists in
                hashset (complements seen so far)*/
                if (hashset.find(third) != hashset.end()) {
                    // Found a triplet that sums up to target
                    vector<int> temp = {nums[i], nums[j], third};
                    
                    /* Sort the triplet to ensure 
                    uniqueness when storing in set*/
                    sort(temp.begin(), temp.end());
                    tripletSet.insert(temp);
                }
                
                /* Insert the current element
                into hashset for future checks*/
                hashset.insert(nums[j]);
            }
        }

        // Convert set to vector (unique triplets)
        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());

        //Return the ans
        return ans;
    }
};