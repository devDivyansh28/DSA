/*
Divide two numbers without multiplication and division

Core
Given the two integers, dividend and divisor. Divide without using the mod, division, or multiplication operators and return the quotient.

The fractional portion of the integer division should be lost as it truncates toward zero.

As an illustration, 8.345 and -2.7335 would be reduced to 8 and -2 respectively.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
*/





// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//        int ans = 0;
//        bool isSigned = true;
//        if(dividend>0 && divisor <0) isSigned=false;       
//        if(dividend<0 && divisor >0) isSigned=false;
       

//        long n = dividend;
//        long x = divisor;
//        n = abs(n);
//        x = abs(x);
//        while(n>=x){
//         int cnt = 0; 
//         while(n>=(x<<(cnt+1))){
//             cnt++;
//         }

//          ans+=(1<<cnt);
//          n-=(x<<cnt);
//        }   

//        if((ans == (1<<31)) && isSigned){
//         return INT_MAX;
//         }

//        if((ans == (1<<31)) && !isSigned){
//         return INT_MIN;
//        }  

//        return isSigned ?  ans : -1*ans;
//     }

// };