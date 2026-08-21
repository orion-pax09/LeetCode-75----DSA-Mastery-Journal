class StockSpanner {
public:

    // Store all stock prices seen so far.
    // We use indexes because the stack stores indexes.
    vector<int> prices;

    // Monotonic stack: stores indexes of useful
    // previous greater-price candidates.
    stack<int> st;

    // Constructor: initially prices and stack are empty.
    StockSpanner() {}

    int next(int price) {

        // Add today's price to our history.
        prices.push_back(price);

        // i = index of today's/current price.
        int i = prices.size() - 1;

        // Remove prices that are <= today's price.
        // They can NEVER be the previous greater element.
        //
        // st.top() gives an index.
        // prices[st.top()] gives the actual price.
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        // If stack is empty:
        // No previous greater price exists.
        // Therefore, today's span goes all the way to day 0.
        if (st.empty()) {
            ans = i + 1;
        }

        // Otherwise:
        // st.top() is the index of the previous greater price.
        // Distance between current index and that index = span.
        else {
            ans = i - st.top();
        }

        // Save today's index for future prices.
        st.push(i);

        // Return the span for today's price.
        return ans;
    }
};
