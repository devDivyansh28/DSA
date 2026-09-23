/*
Given two integers start and goal. Flip the minimum number of bits of start integer to convert it into goal integer.

A bits flip in the number val is to choose any bit in binary representation of val and flipping it from either 0 to 1 or 1 to 0.
*/

class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
       int cnt = 0;
       while(start !=0 || goal !=0){
        if((start&1) != (goal&1)) cnt+=1;
         start = start>>1;
         goal = goal>>1;
       }
       return cnt;
    }
};


class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
        int diff = start ^ goal;
        int cnt = 0;
        while(diff>0){
            cnt+=(diff&1);
            diff=diff>>1;
        }
        if(diff==1)cnt+=1;
        return cnt;
    }
};

class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
        int diff = start ^ goal;
        return __builtin_popcount(diff);
        
    }
};