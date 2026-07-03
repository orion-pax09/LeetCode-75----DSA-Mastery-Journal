class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = s.size()-1;
        while (start < s.size()&&s[start]==' '){
            start++;
        }
        while (end >=  0 && s[end]==' '){
            end--;
        }
        string words="";

        for (int i = end ; i >= start ; i--){
            if (s[i]!=' '){
                words +=s[i];
            }
            else{
                words+=' ';
            }
        }

        int l = 0;
        while (l < words.size()){
            int r = l;
            while (r < words.size()&&words[r]!=' '){
                r++;
            }

            int left = l;
            int right = r-1;
            while (right > left ){
                char temp = words[left];
                words[left] = words[right];
                words[right] = temp;
                left++;
                right--;
            }
            l = r + 1;
        }
        string ans ="";
        int i =0;
        while (i<words.size()){
            while (i<words.size()&&words[i]==' '){
                i++;
            }
            while(i<words.size()&&words[i]!=' '){
                ans+=words[i];
                i++;
            }
            if(i<words.size()){
                ans+=' ';
            }
        }
        return ans;
    }
};
