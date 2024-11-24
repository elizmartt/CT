#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int vertexes;
    vector<vector<int>> adjList;

public:
    Graph(int v) : vertexes(v) {
        adjList.resize(vertexes);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph() {
        for (int i = 0; i < vertexes; i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void checkDegrees(const vector<int>& degrees) {
        for (int i = 0; i < vertexes; i++) {
            if (adjList[i].size() != degrees[i]) {
                cout << "Degrees arent correct" << i << endl;
                return;
            }
        }
        cout << "Graph successfully created.\n";
    }
};

bool constructGraph(vector<int>& degrees, Graph& graph) {
    int n = degrees.size();

    vector<pair<int, int>> vertexDegree;
    for (int i = 0; i < n; i++) {
        vertexDegree.push_back({ degrees[i], i });
    }

    sort(vertexDegree.rbegin(), vertexDegree.rend());

    for (int i = 0; i < n; i++) {
        int degree = vertexDegree[i].first;
        int u = vertexDegree[i].second;

        if (degree == 0) continue;

        for (int j = i + 1; j < n && degree > 0; j++) {
            int v = vertexDegree[j].second;

            if (vertexDegree[j].first > 0) {
                graph.addEdge(u, v);

                vertexDegree[j].first--;
                degree--;
            }
        }

        if (degree != 0) {
            return false; 
        }
    }

    return true;
}

int main() {
    int totalStudents = 30;

    vector<int> degrees;

    for (int i = 0; i < 9; i++) { degrees.push_back(1); }

    for (int i = 0; i < 11; i++) { degrees.push_back(1); }

    for (int i = 0; i < 10; i++) { degrees.push_back(1); }

    Graph myGraph(totalStudents);

    if (constructGraph(degrees, myGraph)) {
        cout << "Graph created:\n";
        myGraph.checkDegrees(degrees);
        myGraph.printGraph();
      
    }
    else {
        cout << "It is not possible to create the graph.\n";
    }

    return 0;
}
