class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // Map each number to its frequency (how many times it appears)
        unordered_map<int, int> mp;

        // Count how many times each number appears
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        // Set stores frequencies that we have already seen
        unordered_set<int> st;

        // Check every frequency in the map
        for (auto c : mp) {

            // c.second is the frequency of the current number
            // If this frequency is already in the set,
            // we have seen the same frequency before → duplicate
            if (st.find(c.second) != st.end()) {
                return false;
            }

            // Frequency is new, so store it in the set
            st.insert(c.second);
        }

        // No duplicate frequencies were found
        return true;
    }
};
