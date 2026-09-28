/*
Assign Cookies
Consider a scenario where a teacher wants to distribute cookies to students, with each student receiving at most one cookie.

Given two arrays, student and cookie, the ith value in the Student array describes the minimum size of cookie that the ith student can be assigned. The jth value in the Cookie array represents the size of the jth cookie. If Cookie[j] >= Student[i], the jth cookie can be assigned to the ith student.

Maximize the number of students assigned with cookies and output the maximum number.
*/


// class Solution{    
//     public:
//     int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
//          int n = Student.size();
//         int m = Cookie.size();
//         // Pointers
//         int l = 0, r = 0;
//         // Sorting of vectors
//         sort(Student.begin(), Student.end());
//         sort(Cookie.begin(), Cookie.end());
 
//         // Traverse through both arrays
//         while (l < n && r < m) {
//             /*If the current cookie can satisfy 
//             the current student, move to the 
//             next student*/
//             if (Cookie[r] >= Student[l]) {
//                 l++;
//             }
//             // Move to next cookie
//             r++;
//         }
//         // Return the number of students who got cookies
//         return l; 
//     }
// };