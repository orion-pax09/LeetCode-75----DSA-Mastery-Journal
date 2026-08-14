class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // Stack stores indices of temperatures
        stack<int> st;

        // Answer array; initially assume there is no warmer day
        vector<int> vt(temperatures.size(), 0);

        // Start from the right because we are looking for a future day
        for (int i = temperatures.size() - 1; i >= 0; i--) {

            // Remove days that are not warmer than today's temperature
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack isn't empty, its top is the next warmer day
            if (!st.empty()) {
                vt[i] = st.top() - i;
            }

            // Store today's index for future days
            st.push(i);
        }

        return vt;
    }
};
