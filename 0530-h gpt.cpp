#include <iostream>
#include <list>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;

class Vertice {
public:
    bool visited = false;
    list<Vertice*> neighbors;
    int nodeID;

    Vertice(int nodeID) : nodeID(nodeID) {}

    void printList() {
        cout << "Node " << nodeID << " has neighbors ";
        for (list<Vertice*>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
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
        p->neighbors.push_back(q);
        q->neighbors.push_back(p);
    }
};

template<typename T, typename U>
class Graph {
public:
    set<T> vSet;
    set<U> eSet;

    bool bfs(T startVertex) {
        if (vSet.find(startVertex) == vSet.end()) return false;
        
        queue<T> q;
        unordered_map<T, T> parent;
        startVertex->visited = true;
        q.push(startVertex);
        parent[startVertex] = nullptr; // Start vertex has no parent

        while (!q.empty()) {
            T current = q.front();
            q.pop();
            cout << "Visited vertex " << current->nodeID << endl;

            for (list<Vertice*>::iterator neighbor = current->neighbors.begin(); 
                 neighbor != current->neighbors.end(); ++neighbor) {
                if (!(*neighbor)->visited) {
                    (*neighbor)->visited = true;
                    q.push(*neighbor);
                    parent[*neighbor] = current;
                } else if (parent[current] != *neighbor) {
                    // If the neighbor is visited and is not the parent, we found a cycle
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Vertice v0(0), v1(1), v2(2), v3(3), v4(4), v5(5);
    Edge<Vertice*> 
    e1(&v0, &v1), e2(&v0, &v2),
    e3(&v1, &v3), e4(&v1, &v4),
    e5(&v2, &v4), e6(&v3, &v5);

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

    bool hasCycle = g.bfs(&v1);

    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
