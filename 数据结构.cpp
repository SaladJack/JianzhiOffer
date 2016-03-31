#include <queue>
#include <iostream>
using namespace std;
class Graph{
private:
	int numVertex, numEdge;
	int **matrix;
	int *mark;
	
public:
	Graph(int numVertex){
		Init(numVertex);
	}
	~Graph(){
		delete[] mark;
		for (int i = 0; i < numVertex; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	void Init(int n){
		int i;
		numVertex = n;
		numEdge = 0;
		mark = new int[n];
		for (int i = 0; i < n; i++){
			mark[i] = 0;
		}
		matrix = (int**)new int*[numVertex];//！！！！
		for (int i = 0; i < n; i++){
			matrix[i] = new int[numVertex];
		}
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n;j++){
			matrix[i][j] = 0;
		}
	}

	int getNumVertex(){ return numVertex; }

	int getMark(int v){ return mark[v]; }

	int first(int v){ 
		for (int i = 0; i < numVertex; i++){
			if (matrix[v][i]!=0)
			return i;
		}
		return numVertex;
		}

	int next(int v, int w){
		for (int i = w+1; i < numVertex; i++){
			if (matrix[v][i] != 0)
				return i;
		}
		return numVertex;
	}

	void setMark(int v, int IsVisited)
	{
		mark[v] = IsVisited;
	}
	
	



	void DFS(Graph* G, int v){
		setMark(v, 1);
		for (int i = G->first(v); i<G->getNumVertex; i=G->next(v,i)){
			if (!G->getMark(i))
			   DFS(G, 1);
		}
	}

	void BFS(Graph* G, int v){
		int u, w;
		queue<int>* Q;
		G->setMark(v, 1);
		Q->push(v);
		while (!Q->empty()){
			u = Q->back();
			Q->pop();
			for (int i = G->first(u); i < G->getNumVertex; i = G->next(u, i)){
				if (!G->getMark(i))
				{
					Q->push(i);
					setMark(i, 1);
				}
			}
		}
	}
};







//Quicksort
void Quicksort(int* a, int lo, int hi){
	if (lo >= hi) return;
	int v =partition(a, lo, hi);//构造切分并将切分元素插入到适当位置

	Quicksort(a, lo, v - 1);
	Quicksort(a, v + 1, hi);



}
int partition(int *a, int lo, int hi){
	int v = a[lo];
	int i = lo;
	int j = hi + 1;
	//将所有小于v的元素放到左边，大于v的元素放到右边
	while (1){
		while (a[++i] <= v) if(i==hi)break;
		while (a[--j] >= v) if (j == lo) break;
		if (i >= j) break;
		swap (a,i,j);
	}
	swap (a, lo, j);//a[lo]跟较小的a[j]交换
	return j;//返回a[lo]的位置 即刚换的a[j]的位置
}
void swap(int*a, int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;

}
int main(){
	int a[] = { 5, 4, 3, 2, 1 };
	Quicksort(a, 0, 4);
	for (int i = 0; i < 5; ++i){
		cout << a[i] << " ";
	}
	system("pause");

}