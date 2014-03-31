/*Clone Graph

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


 
class SolutionCG {
public:
    typedef UndirectedGraphNode GraphNode;
    typedef unordered_map<GraphNode *, GraphNode *> GraphMap;
    typedef queue<GraphNode*> GraphQueue;

    GraphNode *cloneGraph(GraphNode *node) {
        return cloneGraphBFS(node);
    }
private:
    GraphNode * cloneGraphDFS(GraphNode *node){
        GraphMap map;
        return cloneGraphDFSRe(node, map);
    }
    GraphNode * cloneGraphDFSRe(GraphNode *node, GraphMap &map){
        if(node == nullptr)
            return node;
        if(map.find(node) != map.end())
            return map[node];
        GraphNode * newNode = new GraphNode(node->label);
        map[node] = newNode;
        for (size_t i = 0; i < node->neighbors.size(); ++i)
        {       
            newNode->neighbors.push_back(cloneGraphDFSRe(node->neighbors[i], map)); 
        }
        return newNode;
    }

    GraphNode * cloneGraphBFS(GraphNode *node){
        if(node == nullptr)
            return nullptr;
        GraphQueue q;
        q.push(node);
        GraphMap map;
        map[node] = new GraphNode(node->label);
        while (!q.empty())
        {
            GraphNode * oldNode = q.front();
            q.pop();
            GraphNode * newNode = map[oldNode];
            for(size_t i = 0; i < oldNode->neighbors.size(); ++i){
                GraphNode * oldNeighbor = oldNode->neighbors[i];
                if(map.find(oldNeighbor) != map.end())
                {
                    newNode->neighbors.push_back(map[oldNeighbor]);
                    continue;
                }
                GraphNode * newNeighbor = new GraphNode(oldNeighbor->label);
                newNode->neighbors.push_back(newNeighbor);
                map[oldNeighbor] = newNeighbor;
                q.push(oldNeighbor);
            }
        }
        return map[node];
    }
};