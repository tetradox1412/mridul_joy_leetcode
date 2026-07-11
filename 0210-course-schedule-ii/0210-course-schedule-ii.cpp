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

        void addEdges(vector<int> pair) { l[pair[1]].push_back(pair[0]); }

        bool dfsMainCall(int u, vector<bool>& visited, vector<bool>& path) {
            visited[u] = true;
            path[u] = true;
            for (int v : l[u]) {
                if (!visited[v]) {
                    if (dfsMainCall(v, visited, path))
                        return true;
                }

                if (path[v])
                    return true;
            }

            path[u] = false;
            return false;
        }

        bool cycleDetect() {
            vector<bool> visited(V, false);
            vector<bool> path(V, false);
            for (int i = 0; i < V; i++)
                if (!visited[i])
                    if (dfsMainCall(i, visited, path))
                        return true;
            return false;
        }

        void topoSortHelp(int u, vector<bool>& visited, stack<int>& s) {
            visited[u] = true;
            for (int v : l[u]) {
                if (!visited[v])
                    topoSortHelp(v, visited, s);
            }
            s.push(u);
        }

        void topoSort(vector<int>& result) {
            vector<bool> visited(V, false);
            stack<int> s;
            for (int i = 0; i < V; i++) {
                if (!visited[i])
                    topoSortHelp(i, visited, s);
            }

            while (!s.empty()) {
                result.push_back(s.top());
                s.pop();
            }
        }
    };

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            graph.addEdges(prerequisites[i]);
        vector<int> result;
        if (!graph.cycleDetect()) {
            graph.topoSort(result);
        }
        return result;
    }
};