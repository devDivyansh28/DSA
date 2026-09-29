/*
Lemonade Change
Each lemonade at a booth sells for $5. Consumers are lining up to place individual orders, following the billing order. Every consumer will purchase a single lemonade and may pay with a $5, $10, or $20 bill. Each customer must receive the appropriate change so that the net transaction is $5. Initially, there is no change available.

Determine if it is possible to provide the correct change to every customer. Return true if the correct change can be given to every customer, and false otherwise.

Given an integer array bills, where bills[i] is the bill the ith customer pays, return true if the correct change can be given to every customer, and false otherwise.
*/



// class Solution{    
//   public:    
//     bool lemonadeChange(vector<int>& bills){
//         int count5 = 0;
//         int count10 = 0;

//         int n = bills.size();
//         for(int i = 0; i< n ;i++){
//             if(bills[i]==5){
//                count5++;
//             }else if(bills[i]==10){
//                 if(count5){
//                     count5-=1;
//                     count10+=1;
//                 }else{
//                     return false;
//                 }
//             }else if(bills[i]==20){
//                 if((count10>=1&&count5>=1) || count5>=3){
//                     if((count10>=1 &&count5>=1)){
//                         count10-=1;
//                         count5-=1;
//                     }else{
//                         count5-=3;
//                     }
//                 }
//                 else{
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };