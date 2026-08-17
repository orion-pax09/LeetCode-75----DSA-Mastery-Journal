class Solution { 
public: 

    // Function returns the number of equal row-column pairs
    int equalPairs(vector<vector<int>>& grid) { 

        // Map each row(vector) to how many times that row appears
        map<vector<int>, int> rows; 

        // Go through every row
        for (int i = 0; i < grid.size(); i++) { 

            // grid[i] is the entire row
            // ++ increases the count for that row
            rows[grid[i]]++; 
        } 

        // Map each column(vector) to how many times that column appears
        map<vector<int>, int> column; 

        // Go through every column
        for (int i = 0; i < grid.size(); i++) { 

            // Temporary vector to store one complete column
            vector<int> cols; 

            // Go through every row to collect elements of this column
            for (int j = 0; j < grid.size(); j++) { 

                // grid[j][i]:
                // j = row
                // i = column
                // Add the current column element to cols
                cols.push_back(grid[j][i]); 
            } 

            // Store the complete column as a key
            // ++ increases its frequency
            column[cols]++; 
        } 

        // This will store the final number of equal row-column pairs
        int count = 0; 

        // Go through every row stored in the rows map
        for (auto r : rows) { 

            // r.first = the row(vector)
            // Check if the same vector exists as a column
            if (column.find(r.first) != column.end()) { 

                // r.second = frequency of this row
                // column[r.first] = frequency of this column
                // Multiply the two frequencies
                count += r.second * column[r.first]; 
            } 
        } 

        // Return the total number of equal row-column pairs
        return count; 
    } 
};
