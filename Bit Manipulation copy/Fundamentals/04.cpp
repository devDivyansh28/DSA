/*
Given an integer n, return the number of set bits (1s) in its binary representation.

Can you solve it in O(log n) time complexity?
*/

class Solution {
public:
    int countSetBits(int n) {
        int cnt = 0;
        while(n>1){
            cnt+=(n&1);
            n=n>>1;
        }
        if(n==1) cnt+=1;
        return cnt;
    }
};