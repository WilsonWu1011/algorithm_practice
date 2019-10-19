#include <iostream>

using namespace std;

const int default_size = 11;
class disjoint_set{
private:
	int* parent;
	int size;
public:	
	disjoint_set(int sz = default_size):size(sz),parent(nullptr){
		parent = new int[size];
		for(int idx = 0;idx < size;idx++)
			parent[idx] = -1;
	}
	~disjoint_set(){
		delete parent;
	}	
	int find(int child){
		while(parent[child] >= 0)
			child = parent[child];
		return child;
	}
	void Union(int child1,int child2){
		int p1 = find(child1);
		int p2 = find(child2);
		if(p1 != p2){
			parent[p1] += parent[p2];
			parent[p2] = p1;
		}
		else
			cout << "The two subsets are in the same parent set!" << endl;
	}
	void weightedUnion(int child1,int child2){
		int p1 = find(child1);
		int p2 = find(child2);
		int temp;
		
		if(p1 != p2){
			temp = parent[p1] + parent[p2];
			if(parent[p1] < parent[p2]){
				parent[p1] = temp;
				parent[p2] = p1;
			}
			else{
				parent[p2] = temp;
				parent[p1] = p2;
			}
		}
		else
			cout << "The two subsets are in the same parent set!" << endl;
				
	}
	int collapsing(int child){
		int p;
		for(p = child;parent[p] >= 0;p = parent[p]);//find parent
		while(p != child){
			int temp = parent[child];
			parent[child] = p;
			child = temp;
		}
		return p;
	}
	void display(){
		for(int i = 0;i < size;i++)
			cout << i << "  ";
		cout << endl;
		for(int i = 0;i < size;i++){
		 	cout << parent[i] << "  ";
		}
		cout << endl;
	}
	int count(){
		int ct = 0;
		for(int j = 0;j < size;j++){
			ct += (parent[j] < 0) ? 1 : 0;
		}
		return ct;
	}
};

int main()
{
	disjoint_set set;
	set.Union(0,1);
	set.Union(2,3);
	set.Union(4,1);
	set.Union(3,5);
	set.Union(1,5);
	set.Union(6,10);
	set.Union(8,6);
	set.Union(8,10);
	set.Union(0,5);
	set.Union(7,6);

	set.collapsing(10);
	set.display();
	cout << "The disjoint set has " << set.count() << " different subsets!" << endl;
	return 0;
}
