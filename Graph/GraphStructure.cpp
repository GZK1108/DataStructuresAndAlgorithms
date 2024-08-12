/*
ͼ�Ľṹ��
ʹ�õ�ͱߵĽṹ������ʾͼ
*/

#include<iostream>
#include<vector>
#include <queue>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

//�ߵĽṹ��
struct Edge
{
	int start;//�ߵ����
	Node* from;
	Node* to;

	Edge(int s, Node* f, Node* t) {
		start = s;
		from = f;
		to = t;
	}
};



//��Ľṹ��
class Node
{
public:
	int val;//���ֵ
	int inDegree;//���
	int outDegree;//����
	//����һ���洢Node*�����飬��ʾ�õ���ڽӵ�
	vector<Node*> neighbors;
	//����һ���洢Edge*�����飬��ʾ�õ�ı�
	vector<Edge*> edges;
	Node(int x) {
		val = x;
		inDegree = 0;
		outDegree = 0;
		neighbors = vector<Node*>();
		edges = vector<Edge*>();
	}
};


//ͼ�Ľṹ��
class Graph
{
	public:
	vector<Node*> nodes;//�洢ͼ�����еĵ�
	vector<Edge*> edges;//�洢ͼ�����еı�
	Graph() {
		nodes = vector<Node*>();
		edges = vector<Edge*>();
	}
};


//ͼ�Ŀ�����ȱ���
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

//ͼ��������ȱ���
void DFS(Node* node) {
	if (node == NULL) {
		return;
	}
	//����һ��ջ
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


//ͼ����������
//�����ҵ����Ϊ0�ĵ㣬Ȼ�󽫸õ���ڽӵ����ȼ�1��ֱ�����е㶼������
vector<Node*> topSort(Graph* graph) {
	vector<Node*> res;
	if (graph == NULL) {
		return res;
	}
	//����һ����ϣ���洢���е�����
	unordered_map<Node*, int> inDegree;  //�洢ÿ����ʣ������
	//����һ�����У��洢���Ϊ0�ĵ�
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





//ͼ��kruskal�㷨
//�����б߰���Ȩ�ش�С��������
//����ѡ��Ȩ����С�ıߣ�����ñߵ������㲻��ͬһ�������У�����������ϲ�
//ֱ�����е㶼��һ��������

//���鼯�Ľṹ��
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


//ͼ��kruskal�㷨
vector<Edge*> kruskalMST(Graph* graph) {
	vector<Edge*> res;
	if (graph == NULL) {
		return res;
	}
	//�����б߰���Ȩ�ش�С��������
	//���ȶ��У����ձߵ�Ȩ�ش�С��������
	priority_queue<Edge*, vector<Edge*>, greater<Edge*>> minHeap;

	for (int i = 0; i < graph->edges.size(); i++) {
		minHeap.push(graph->edges[i]);
	}
	//����һ�����鼯
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


//ͼ��prim�㷨
//��һ���㿪ʼ��ÿ��ѡ��һ�����뵱ǰ��������ĵ���뼯��
//ֱ�����е㶼�����뼯��

//prim�㷨
vector<Edge*> primMST(Graph* graph) {
	vector<Edge*> res;
	if (graph == NULL) {
		return res;
	}
	//����һ����ϣ���洢���е�ľ���
	unordered_map<Node*, int> distance;
	//����һ����ϣ���洢���е�ı�
	unordered_map<Node*, Edge*> edgeMap;
	//����һ����ϣ���洢���е��Ƿ񱻼��뼯��
	unordered_set<Node*> nodeSet;
	//����һ�����ȶ��У��洢���뵱ǰ��������ĵ�
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
