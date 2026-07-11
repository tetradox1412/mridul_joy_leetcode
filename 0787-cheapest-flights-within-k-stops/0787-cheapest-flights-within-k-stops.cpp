class Solution {
public:
    class Info {
    public:
        int V;
        int K;
        int cost;

        Info(int V, int K, int cost) {
            this->V = V;
            this->K = K;
            this->cost = cost;
        }
    };

    class Graph // For flight tickets
    {
    public:
        int V;
        list<pair<int, int>>* l; //  Pair : ( Price , Destination  )

        Graph(int V) {
            this->V = V;
            this->l = new list<pair<int, int>>[V];
        }

        void addEdge(vector<int>& vec) {
            l[vec[0]].push_back(make_pair(vec[2], vec[1]));
        }

        int cheapestFlight(int src, int dest, int K) {
            vector<int> minCost(V, INT_MAX);
            queue<Info> Q;
            int ans = INT_MAX;

            minCost[src] = 0;
            Q.push(Info(src, K + 1, 0));
            while (!Q.empty()) {
                Info front = Q.front();
                Q.pop();

                if (front.V == dest && front.K >= 0) {
                    ans = min(ans, front.cost);
                    continue;
                }

                if (front.K < 0)
                    continue;

                for (pair<int, int> p : l[front.V]) {
                    if (minCost[p.second] > front.cost + p.first) {
                        minCost[p.second] = front.cost + p.first;
                        Q.push(Info(p.second, front.K - 1, minCost[p.second]));
                    }
                }
            }

            return ans == INT_MAX ? -1 : ans;
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        Graph graph(n);
        for (int i = 0; i < flights.size(); i++) {
            graph.addEdge(flights[i]);
        }

        return graph.cheapestFlight(src, dst, k);
    }
};