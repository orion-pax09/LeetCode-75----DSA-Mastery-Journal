class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0 ;
        int j = 0;
        while (i < s.length()&j<t.length()){
            if (s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i == s.length();
    }
};
/*

Input
s =
"axc"
t =
"ahbgdc"
output:False 


Input
s =
"abc"
t =
"ahbgdc"
Output
true
Expected
true

*/
