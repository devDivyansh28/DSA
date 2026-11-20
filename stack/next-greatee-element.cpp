class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
        stack<int> st;
        int n = arr.size();
        vector<int>nge(n);
        for(int i = n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i] = -1;
        }else{
            nge[i]=st.top();
        }
        st.push(arr[i]);
       }
       return nge;
    }
};
