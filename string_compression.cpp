class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        for (int i = 0 ; i < n ; i++){
            int count = 0;
            char ch = chars[i];
            while (i < n && chars[i]==ch){
                count ++;
                i++;
            }
            if (count==1){
                chars[index++] = ch;
            }
            else{
                chars[index++] = ch;
                string s = to_string(count);
                for(auto digi:s){
                    chars[index++] = digi;
                }
            }
            i--;
        }
        return index;
    }
};
