/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two if there exists an integer x such that n == 2x.

You must solve it without using loops or recursion.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0){
        if((n&n-1)==0) return true;;
        }
       return false;
    }
};