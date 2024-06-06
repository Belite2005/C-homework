#include <iostream>
#include <list>
#include <set>
#include <unordered_map>

using namespace std;

class Vertice {
public:
    set<Vertice*> neighbors;
    int nodeID;

    Vertice(int nodeID) : nodeID(nodeID) {}

    void printList() {
        cout << "Node " << nodeID << " has neighbors ";
        for (set<Vertice*>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
            cout << (*it)->nodeID << ", ";
        }
        cout << endl;
    }
};

template <typename T>
class Edge {
public:
    T p;
    T q;

    Edge(T source_V, T destinate_V) : p(source_V), q(destinate_V) {
        p->neighbors.insert(q);
        q->neighbors.insert(p);
    }
};

template<typename T, typename U>
class Graph {
public:
    set<T> vSet;
    set<U> eSet;

    bool dfs(T vertex, unordered_map<T, bool>& visited, unordered_map<T, bool>& recStack) {
        if (!visited[vertex]) {
            visited[vertex] = true;
            recStack[vertex] = true;

            for (auto neighbor : vertex->neighbors) {
                if (!visited[neighbor] && dfs(neighbor, visited, recStack)) {
                    return true;
                } else if (recStack[neighbor]) {
                    return true;
                }
            }
        }
        recStack[vertex] = false;
        return false;
    }

    bool hasCycle() {
        unordered_map<T, bool> visited;
        unordered_map<T, bool> recStack;

        for (auto vertex : vSet) {
            if (dfs(vertex, visited, recStack)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Vertice v0(0), v1(1), v2(2), v3(3), v4(4), v5(5);
    Edge<Vertice*> 
    e1(&v0, &v1), e7(&v1, &v0),
    e2(&v0, &v2), e8(&v2, &v0),
    e3(&v1, &v3), e9(&v3, &v1),
    e4(&v1, &v4), e10(&v4, &v1),
    e5(&v2, &v4), e11(&v4, &v2),
    e6(&v3, &v5), e12(&v5, &v3);

    Graph<Vertice*, Edge<Vertice*>*> g;
    g.vSet.insert(&v0);
    g.vSet.insert(&v1);
    g.vSet.insert(&v2);
    g.vSet.insert(&v3);
    g.vSet.insert(&v4);
    g.vSet.insert(&v5);

    g.eSet.insert(&e1);
    g.eSet.insert(&e2);
    g.eSet.insert(&e3);
    g.eSet.insert(&e4);
    g.eSet.insert(&e5);
    g.eSet.insert(&e6);

    bool hasCycle = g.hasCycle();

    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
