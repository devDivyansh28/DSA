class Solution {
    int lowerBound(vector<int> arr , int k){
        int low = 0;
        int high = arr.size()-1;
        int ans = arr.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
          // Applying binary search concept
          int ans = -1;
          int maxCount = 0;
          int n = mat.size();
          for(int i = 0; i< n;i++){
            int cnt = mat[i].size() - lowerBound(mat[i],1);
            if(cnt>maxCount){
                maxCount = cnt;
                ans = i;
            }
          }
          return ans;
  }
};