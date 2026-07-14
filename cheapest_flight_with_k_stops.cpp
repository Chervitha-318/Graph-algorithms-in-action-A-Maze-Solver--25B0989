class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<pair<int, int>> adj[101];

        for (auto flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            adj[from].push_back({to, price});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});

        while (!q.empty()) {

            int stops = q.front().first;
            int city = q.front().second.first;
            int cost = q.front().second.second;

            q.pop();

            if (stops > k)
                continue;

            for (auto it : adj[city]) {

                int nextCity = it.first;
                int price = it.second;

                if (cost + price < dist[nextCity]) {

                    dist[nextCity] = cost + price;
                    q.push({stops + 1,
                           {nextCity, cost + price}});
                }
            }
        }
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};
