class Solution {
public:
    class Graph {
    public:
        int V;
        list<int>* l;

        Graph(int V) {
            this->V = V;
            this->l = new list<int>[V];
        }

        void addEdge(int u, int v) { l[u].push_back(v); }

        bool dfsMainCall(int u, vector<bool>& visited, vector<bool>& path) {
            visited[u] = true;
            path[u] = true;
            for (int v : l[u]) {
                if (!visited[v]) {
                    if (dfsMainCall(v, visited, path))
                        return true;
                } else {
                    if (path[v])
                        return true;
                }
            }
            path[u] = false;
            return false;
        }

        bool isCycleExist() {
            vector<bool> visited(V, false);
            vector<bool> recursion_path(V, false);
            for (int i = 0; i < V; i++) {
                {
                    if (!visited[i]) {
                        if (dfsMainCall(i, visited, recursion_path))
                            return true;
                    }
                }
            }
            return false;
        }
    };

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            graph.addEdge(prerequisites[i][1], prerequisites[i][0]);

        return !graph.isCycleExist();
    }
};