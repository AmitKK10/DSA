class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
      int n = moveTime.size(), m = moveTime[0].size();

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> times(n, vector<int>(m, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();

            if (t >= times[r][c])
                continue;

            times[r][c] = t;

            if (r == n - 1 && c == m - 1)
                return t;

            for (int d = 0; d < 4; ++d) {
                int nr = r + dirs[d][0], nc = c + dirs[d][1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int cost = ((r + c) % 2) + 1;
                int next = max(t, moveTime[nr][nc]) + cost;

                if (next < times[nr][nc])
                    pq.push({next, nr, nc});
            }
        }

        return -1;  
    }
};