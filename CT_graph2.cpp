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
        adjList[n].push_back(m);
    }

    void printGraph() {
        for (int i = 0; i < vertexes; i++) {
            std::cout << "Vertex " << i << ":";
            for (int k : adjList[i]) {
                std::cout << " -> " << k;
            }
            std::cout << std::endl;
        }
    }

    void isPrisonerGuilty() {
        int accusationCount = 0;

        for (int i = 0; i < vertexes; i++) {
                for (int neighbor : adjList[i]) {
                    if (neighbor == 1) {
                        accusationCount++;
                    
                }
            }
        }

        int totalPeople = vertexes + 1; 

        if (accusationCount > totalPeople / 2) {
            std::cout << "The Prisoner (Vertex 1) is Guilty!" << std::endl;
        }
        else {
            std::cout << "The Prisoner (Vertex 1) is Not Guilty!" << std::endl;
        }
    }
};

int main() {
    int num;
    int edgeCount;
    int n, m;

    std::cout << "Input the number of vertexes: \n";
    std::cin >> num;

    if (num < 3) {
        std::cout << "There should be at least 3 vertexes (Judge, Prisoner, and People)" << std::endl;
        return 0;
    }

    Graph mygraph(num+2);

    std::cout << "Input the number of edges: \n";
    std::cin >> edgeCount;
    std::cout << "Input the judge opinion:\n";
    std::cin >> m;
    mygraph.addEdge(0, m);
    std::cout << "Input the vertexes of edges (who accuses whom): \n";
    for (int i = 0; i < edgeCount; i++) {
        std::cin >> n >> m;
        mygraph.addEdge(n, m);
    }

    mygraph.printGraph();
    mygraph.isPrisonerGuilty();

    return 0;
}
