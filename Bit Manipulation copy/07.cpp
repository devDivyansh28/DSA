/*
XOR of numbers in a given range


Given two integers L and R. Find the XOR of the elements in the range [L , R].

Example 1:
Input : L = 3 , R = 5

Output : 2

Explanation : answer = (3 ^ 4 ^ 5) = 2.

Example 2:
Input : L = 1, R = 3

Output : 0

Explanation : answer = (1 ^ 2 ^ 3) = 0.
*/
class Solution{	

    int findXOR(int n){
        if(n%4==0) return n;
        if(n%4==1) return 1;
        if(n%4==2) return (n+1);
        if(n%4==3) return 0;
    }
	public:
		int findRangeXOR(int l,int r){
			return findXOR(l-1)^findXOR(r);
		}
};
