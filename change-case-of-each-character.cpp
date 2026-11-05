class Solution {
public:
    string toggleCase(const string& s) {
         string result = "";
        
        // Traverse each character in the string
        for (char ch : s) {
            // If lowercase, convert to uppercase
            if (ch >= 'a' && ch <= 'z')
                result += (ch - 'a' + 'A');
            // If uppercase, convert to lowercase
            else if (ch >= 'A' && ch <= 'Z')
                result += (ch - 'A' + 'a');
            // Otherwise, keep the character as is
            else
                result += ch;
        }
 
        // Return the modified string
        return result;
    }
};
