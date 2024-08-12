/*
图的结构体
使用点和边的结构体来表示图
*/

#include<iostream>
#include<vector>
#include <queue>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

//边的结构体
struct Edge
{
	int start;//边的起点
	Node* from;
	Node* to;

	Edge(int s, Node* f, Node* t) {
		start = s;
		from = f;
		to = t;
	}
};



//点的结构体
class Node
{
public:
	int val;//点的值
	int inDegree;//入度
	int outDegree;//出度
	//创建一个存储Node*的数组，表示该点的邻接点
	vector<Node*> neighbors;
	//创建一个存储Edge*的数组，表示该点的边
	vector<Edge*> edges;
	Node(int x) {
		val = x;
		inDegree = 0;
		outDegree = 0;
		neighbors = vector<Node*>();
		edges = vector<Edge*>();
	}
};


//图的结构体
class Graph
{
	public:
	vector<Node*> nodes;//存储图中所有的点
	vector<Edge*> edges;//存储图中所有的边
	Graph() {
		nodes = vector<Node*>();
		edges = vector<Edge*>();
	}
};


//图的宽度优先遍历
void BFS(Node* node) {
	if (node == NULL) {
		return;
	}
	queue<Node*> que;
	unordered_set<Node*> visited;
	que.push(node);
	visited.insert(node);
	while (!que.empty()) {
		Node* cur = que.front();
		que.pop();
		cout << cur->val << " ";
		for (int i = 0; i < cur->neighbors.size(); i++) {
			Node* next = cur->neighbors[i];
			if (visited.find(next) == visited.end()) {
				que.push(next);
				visited.insert(next);
			}
		}
	}
}

//图的深度优先遍历
void DFS(Node* node) {
	if (node == NULL) {
		return;
	}
	//创建一个栈
	stack<Node*> st;
	unordered_set<Node*> visited;
	st.push(node);
	visited.insert(node);
	cout << node->val << " ";
	while (!st.empty()) {
		Node* cur = st.top();
		st.pop();
		for (int i = 0; i < cur->neighbors.size(); i++) {
			Node* next = cur->neighbors[i];
			if (visited.find(next) == visited.end()) {
				st.push(cur);
				st.push(next);
				visited.insert(next);
				cout << next->val << " ";
				break;
			}
		}
	}
}


//图的拓扑排序
//依次找到入度为0的点，然后将该点的邻接点的入度减1，直到所有点都被遍历
vector<Node*> topSort(Graph* graph) {
	vector<Node*> res;
	if (graph == NULL) {
		return res;
	}
	//创建一个哈希表，存储所有点的入度
	unordered_map<Node*, int> inDegree;  //存储每个点剩余的入度
	//创建一个队列，存储入度为0的点
	queue<Node*> que;
	for (int i = 0; i < graph->nodes.size(); i++) {
		Node* node = graph->nodes[i];
		inDegree[node] = node->inDegree;
		if (node->inDegree == 0) {
			que.push(node);
		}
	}
	while (!que.empty()) {
		Node* cur = que.front();
		que.pop();
		res.push_back(cur);
		for (int i = 0; i < cur->neighbors.size(); i++) {
			Node* next = cur->neighbors[i];
			inDegree[next]--;
			if (inDegree[next] == 0) {
				que.push(next);
			}
		}
	}
	return res;
}





//图的kruskal算法
//将所有边按照权重从小到大排序
//依次选择权重最小的边，如果该边的两个点不在同一个集合中，则将这两个点合并
//直到所有点都在一个集合中

//并查集的结构体
class UnionFindSet
{
public:
	unordered_map<Node*, Node*> fatherMap;
	unordered_map<Node*, int> sizeMap;
	UnionFindSet(vector<Node*> nodes) {
		for (int i = 0; i < nodes.size(); i++) {
			Node* node = nodes[i];
			fatherMap[node] = node;
			sizeMap[node] = 1;
		}
	}
	//
	Node* findHead(Node* node) {
		Node* father = fatherMap[node];
		if (father != node) {
			father = findHead(father);
		}
		fatherMap[node] = father;
		return father;
	}
	bool isSameSet(Node* a, Node* b) {
		return findHead(a) == findHead(b);
	}
	void unionSet(Node* a, Node* b) {
		if (a == NULL || b == NULL) {
			return;
		}
		Node* aHead = findHead(a);
		Node* bHead = findHead(b);
		if (aHead != bHead) {
			int aSetSize = sizeMap[aHead];
			int bSetSize = sizeMap[bHead];
			if (aSetSize <= bSetSize) {
				fatherMap[aHead] = bHead;
				sizeMap[bHead] = aSetSize + bSetSize;
			}
			else {
				fatherMap[bHead] = aHead;
				sizeMap[aHead] = aSetSize + bSetSize;
			}
		}
	}
};


//图的kruskal算法
vector<Edge*> kruskalMST(Graph* graph) {
	vector<Edge*> res;
	if (graph == NULL) {
		return res;
	}
	//将所有边按照权重从小到大排序
	//优先队列，按照边的权重从小到大排序
	priority_queue<Edge*, vector<Edge*>, greater<Edge*>> minHeap;

	for (int i = 0; i < graph->edges.size(); i++) {
		minHeap.push(graph->edges[i]);
	}
	//创建一个并查集
	UnionFindSet* unionFind = new UnionFindSet(graph->nodes);
	while (!minHeap.empty()) {
		Edge* edge = minHeap.top();
		minHeap.pop();
		if (!unionFind->isSameSet(edge->from, edge->to)) {
			res.push_back(edge);
			unionFind->unionSet(edge->from, edge->to);
		}
	}
	return res;
}


//图的prim算法
//从一个点开始，每次选择一个距离当前集合最近的点加入集合
//直到所有点都被加入集合

//prim算法
vector<Edge*> primMST(Graph* graph) {
	vector<Edge*> res;
	if (graph == NULL) {
		return res;
	}
	//创建一个哈希表，存储所有点的距离
	unordered_map<Node*, int> distance;
	//创建一个哈希表，存储所有点的边
	unordered_map<Node*, Edge*> edgeMap;
	//创建一个哈希表，存储所有点是否被加入集合
	unordered_set<Node*> nodeSet;
	//创建一个优先队列，存储距离当前集合最近的点
	priority_queue<Node*, vector<Node*>, greater<Node*>> minHeap;
	for (int i = 0; i < graph->nodes.size(); i++) {
		Node* node = graph->nodes[i];
		if (nodeSet.find(node) == nodeSet.end()) {
			nodeSet.insert(node);
			for (int j = 0; j < node->edges.size(); j++) {
				Edge* edge = node->edges[j];
				Node* toNode = edge->to;
				if (nodeSet.find(toNode) == nodeSet.end()) {
					int weight = edge->start;
					if (distance.find(toNode) == distance.end()) {
						distance[toNode] = weight;
						edgeMap[toNode] = edge;
					}
					else {
						if (weight < distance[toNode]) {
							distance[toNode] = weight;
							edgeMap[toNode] = edge;
						}
					}
				}
			}
			for (auto it = distance.begin(); it != distance.end(); it++) {
				minHeap.push(it->first);
			}
			while (!minHeap.empty()) {
				Node* cur = minHeap.top();
				minHeap.pop();
				Edge* edge = edgeMap[cur];
				if (nodeSet.find(cur) == nodeSet.end()) {
					nodeSet.insert(cur);
					res.push_back(edge);
					for (int i = 0; i < cur->edges.size(); i++) {
						Edge* nextEdge = cur->edges[i];
						Node* nextNode = nextEdge->to;
						if (nodeSet.find(nextNode) == nodeSet.end()) {
							int weight = nextEdge->start;
							if (
								distance.find(nextNode) == distance.end() ||
								weight < distance[nextNode]
								) {
								distance[nextNode] = weight;
								edgeMap[nextNode] = nextEdge;
							}
						}
					}
				}
			}
		}
	}
}







int main() {
	return 0;
}
