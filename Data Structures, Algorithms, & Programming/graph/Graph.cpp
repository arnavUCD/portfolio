Arnav Sharma
SID- 921870432

#ifndef GRAPH_CPP
#define GRAPH_CPP
#include "Graph.hpp"
#include "GraphNode.hpp"
#include <queue>

// helps constructs a graph from a vector edge pair
template <typename T>
Graph<T>::Graph(const std::vector<std::pair<T,T>> &edges){
    for (const auto&edge : edges){
        addVertex(edge.first);
        addVertex(edge.second);
        addEdge(edge.first, edge.second);
    }
}

// this function creates a grph from given adjacency list
template <typename T>
Graph<T>::Graph(const std::map<T, std::set<T>> &adjList){
    for (const auto &entry : adjList) {
        addVertex(entry.first);
        for (const auto &neighbor : entry.second) {
            addVertex(neighbor);
            addEdge(entry.first, neighbor);
        }
    }
}

// this function throws back the number of vertices
template <typename T>
int Graph<T>::size() const{
    return _adjList.size();
}

// adds a vertex if it does not exist already
template <typename T>
void Graph<T>::addVertex(T vertex){
    if(_adjList.find(vertex) == _adjList.end()){
        _adjList[vertex] = std::set<T>();
    }
    if (_vertices.find(vertex) == _vertices.end()){
        _vertices[vertex] = GraphNode<T>(vertex);
    }
}

// adds and edge while making sure both vertices exists
template <typename T>
void Graph<T>::addEdge(T from, T to){
    addVertex(from);
    addVertex(to);
    _adjList[from].insert(to);
}

// checks for the added by the above function
template <typename T>
bool Graph<T>::hasEdge(T from, T to) const{
    auto fromcurr = _adjList.find(from);
    if (fromcurr != _adjList.end()){
        auto tocurr = fromcurr->second.find(to);
        if (tocurr != fromcurr->second.end()) {
            return true;
        }
    }
    return false;
}

// returns the neighbour of a vertex (if exist)
template <typename T>
std::optional<std::set<T>> Graph<T>::getNeighbors(T vertex) const{
    auto it = _adjList.find(vertex);

    if (it != _adjList.end()) {
        return it->second;
    }
    else{
        return std::nullopt;
    }
}

// perfroems a BFS and returns the visited vertices
template <typename T>
std::vector<T> Graph<T>::BFS(T start){
   for(auto& vertex: _vertices){
        vertex.second.color = White;
        vertex.second.distance = -1;
        vertex.second.predecessor = std::nullopt;
    }
    _vertices[start].color = Gray;
    _vertices[start].distance = 0;
    _vertices[start].predecessor = std::nullopt;
    std::queue<T> q;
    q.push(start);
    std::vector<T> result;
    while (!q.empty()){
        T u = q.front();
        q.pop();
        result.push_back(u);
        for (const T& v : _adjList[u]){
            if(_vertices[v].color == White){
                _vertices[v].color = Gray;
                _vertices[v].distance = _vertices[u].distance + 1;
                _vertices[v].predecessor = u;
                q.push(v);
            }
        }
        _vertices[u].color = Black;
    }
    return result;
}

//retuerns the shortest path from the start to end
template <typename T>
int Graph<T>::shortestPath(T start, T end){
    BFS(start);
    
    if(_vertices[end].distance == -1){
        return -1;
    }
    std::vector<T> path;
    T currVertex = end;
    while (currVertex != start){
        path.push_back(currVertex);
        currVertex = _vertices[currVertex].predecessor.value();
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return _vertices[end].distance;
}

// performs a DFS operation on graph
template <typename T>
std::list<T> Graph<T>::DFS(){
    std::list<T> result;
    int time = 0;      
     std::function<void(const T &)> DFS_visit = [&](const T &u){
        _vertices[u].color = Gray;
        _vertices[u].discovery_time = ++time;

        for (const T &v : _adjList[u]){
            if (_vertices[v].color == White){
                _vertices[v].predecessor = u;
                DFS_visit(v);
            }
        }
        _vertices[u].color = Black;
        _vertices[u].finish_time = ++time;
        result.push_front(u);
    };
    for (auto& pair : _vertices){
        pair.second.color = White;
        pair.second.predecessor = std::nullopt;
    }
    for (const auto& pair : _vertices){
        if (pair.second.color == White){
            DFS_visit(pair.first);
        }
    }
    return result;
}
#endif