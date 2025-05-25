class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
         int count[26][26] = {0};
        int result = 0;
        bool usedMiddle = false;


        for (const string& word : words) {
            int a = word[0] - 'a';
            int b = word[1] - 'a';
            count[a][b]++;
        }

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (count[i][j] == 0) continue;

                if (i == j) {
                    int pairs = count[i][j] / 2;
                    result += pairs * 4;
                    count[i][j] -= pairs * 2;

                    if (count[i][j] > 0 && !usedMiddle) {
                        result += 2;
                        usedMiddle = true;
                    }
                } else if (j > i && count[j][i] > 0) {
                    int pairs = min(count[i][j], count[j][i]);
                    result += pairs * 4;
                    count[i][j] -= pairs;
                    count[j][i] -= pairs;
                }
            }
        }

        return result;
    }
};