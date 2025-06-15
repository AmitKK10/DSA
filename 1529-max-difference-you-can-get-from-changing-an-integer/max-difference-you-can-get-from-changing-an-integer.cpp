class Solution {
public:
    int maxDiff(int num) {
         string s = to_string(num);
        int maxVal = num;
        int minVal = num;

        // Try all digit replacements for max value
        for (char x = '0'; x <= '9'; x++) {
            for (char y = '0'; y <= '9'; y++) {
                string temp = s;
                for (char& ch : temp) {
                    if (ch == x) ch = y;
                }

                // Skip invalid numbers (leading zero or 0)
                if (temp[0] == '0') continue;

                int newVal = stoi(temp);
                maxVal = max(maxVal, newVal);
            }
        }

        // Try all digit replacements for min value
        for (char x = '0'; x <= '9'; x++) {
            for (char y = '0'; y <= '9'; y++) {
                string temp = s;
                for (char& ch : temp) {
                    if (ch == x) ch = y;
                }

                // Skip invalid numbers (leading zero or 0)
                if (temp[0] == '0') continue;

                int newVal = stoi(temp);
                minVal = min(minVal, newVal);
            }
        }

        return maxVal - minVal;
    }
};