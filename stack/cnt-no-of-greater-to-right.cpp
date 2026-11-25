class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        vector<int> ans;
        
        for(auto idx : indices){
            int cnt = 0;
            for(int i = idx+1 ;i< arr.size();i++){
                if(arr[i]>arr[idx]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};