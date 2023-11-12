#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
class Graph {
public:
    //global adjacency list
    vector<vector<pair<int, int> > > adjList;
    Graph(int n, vector<vector< int > >& edges) {
        adjList.resize(n);
        for(auto& edge: edges)
            adjList[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    
    void addEdge(vector<int> edge) {
        //update the matrix
        adjList[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    
    int shortestPath(int node1, int node2) {
        //dijkstra and traverse node a to node b

        /**  there are three steps in single source shortest path
        1. initialize-single-source(G, s)
        2. Set up the priority queue
        3. edge relaxation for min weight node's neighbours
        **/

        int n = adjList.size(); 

        /**cpp PQ decl
            template<
            class T,
            class Container = std::vector<T>,
            class Compare = std::less<typename Container::value_type>
            > class priority_queue;
        **/
        
        // greater yields total order
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;

        //step 1
        vector<int> costForNode(n, INT_MAX);
        costForNode[node1] = 0;
        pq.push(vector<int>(0, node1));

        while(!pq.empty())
        {
            int currCost = pq.top()[0];
            int currNode = pq.top()[1];
            pq.pop();

            if(currCost > costForNode[currNode]) {
                continue;
            }

            if(currNode == node2) {
                return currCost;
            }

            for(auto& neighbor: adjList[currNode]) {
                int node = neighbor.first;
                int cost = neighbor.second;
                int newCost = currCost + cost;

                if(newCost < costForNode[node])
                {
                    costForNode[node] = newCost;
                    pq.push(vector<int>(newCost, node));
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */