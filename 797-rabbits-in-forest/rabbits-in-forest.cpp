class Solution {
public:
    int numRabbits(vector<int>& answers) {
         unordered_map<int, int> count;
    for (int ans : answers) {
        count[ans]++;
    }

    int result = 0;
    for (auto& [k, c] : count) {
        int groupSize = k + 1;
        int groups = ceil((double)c / groupSize);
        result += groups * groupSize;
    }

    return result;
    }
};