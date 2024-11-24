#include <iostream>
#include <list>
#include <vector>

class Graph {
private:
    int vertexes;
    std::vector<std::list<int>> adjList;
public:
    Graph(int v) : vertexes(v) {
        adjList.resize(vertexes);
    }

    void addEdge(int n, int m) {
        adjList[n - 1].push_back(m - 1);
    }

    void printGraph() {
        for (int i = 0; i < vertexes; i++) {
            std::cout << "Vertex " << i + 1 << ":"; 
            for (int k : adjList[i]) {
                std::cout << " -> " << k + 1;
            }
            std::cout << std::endl;
        }
    }

    void findTheJudge() {
        std::vector<bool> hasIncoming(vertexes, false);
        std::vector<bool> hasOutgoing(vertexes, false);

        for (int i = 0; i < vertexes; i++) {
            if (!adjList[i].empty()) {
                hasOutgoing[i] = true;
            }
            for (int k : adjList[i]) {
                hasIncoming[k] = true;
            }
        }

        for (int i = 0; i < vertexes; i++) {
            if (!hasOutgoing[i] && hasIncoming[i]) {
                std::cout << "The Judge is: " << i + 1 << std::endl; 
                return;
            }
        }
        std::cout << "No Judge found." << std::endl;
    }
};

int main() {
    int num;
    int edgeCount;
    int n, m;

    std::cout << "Input the number of vertexes: \n";
    std::cin >> num;

    Graph mygraph(num);

    std::cout << "Input the number of edges: \n";
    std::cin >> edgeCount;

    std::cout << "Input the vertexes of edges (1-based index): \n";
    for (int i = 0; i < edgeCount; i++) {
        std::cin >> n >> m;
        mygraph.addEdge(n, m);
    }

    mygraph.printGraph();
    mygraph.findTheJudge();

    return 0;
}
