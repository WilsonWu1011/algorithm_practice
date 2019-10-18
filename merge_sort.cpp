#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void merge(int* array,int begin,int middle,int end)
{
	int* aux = new int[end-begin+1];
	int i = begin,j = middle + 1;
	int k = 0;
	while(i <= middle && j <= end){
		if(array[i] <= array[j]){
			aux[k++] = array[i++];
		}
		else
			aux[k++] = array[j++];
	}
	while(i <= middle)
		aux[k++] = array[i++];
	while(j <= end)
		aux[k++] = array[j++];
	for(i = begin,k = 0;i <= end;i++,k++)
		array[i] = aux[k];
	delete aux;
}

void division(int* array,int begin,int end)
{
	if(begin < end){
		int middle = (begin+end)/2;
		division(array,begin,middle);
		division(array,middle+1,end);
		merge(array,begin,middle,end);
	}
}


int main()
{
	int array[9] = {4,9,15,24,30,2,6,18,20};
	division(array,0,8);
	copy(array,array+9,ostream_iterator<int>(cout," "));
	return 0;
}
