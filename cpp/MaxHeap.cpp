#include <iostream>
using namespace std;

class Heap
{
	int n = 0;
	int HeapArray[30] = { 0 };
	public:
		void insert(int data)
		{
			HeapArray[n] = data;
			{
				int child = n;
				int parent = (child - 1) / 2;
				if(parent > -1)
				{
					while (HeapArray[child] > HeapArray[parent])
					{
						int temp = HeapArray[parent];
						HeapArray[parent] = HeapArray[child];
						HeapArray[child] = temp;
						child = parent;
						parent = (child - 1) / 2;
					}
				}
				n++;
			}
		}
		void DownHeap(int i)
		{
			for(; i < n; i++)
			{
				int l = (2 * (i)) + 1;
				int r = (2 * (i)) + 2;
				if(HeapArray[i] < HeapArray[l])
				{
					int temp = HeapArray[i];
					HeapArray[i] = HeapArray[l];
					HeapArray[l] = temp;
				}
				if(HeapArray[i] < HeapArray[r])
				{
					int temp = HeapArray[i];
					HeapArray[i] = HeapArray[r];
					HeapArray[r] = temp;
				}
			}
		}
		void Delete(int del)
		{
			int flag = 0;
			int i = 0;
			for(; i < n; i++)              
			{
				if(HeapArray[i] == del)
				{
					flag = 1;
					break;
				}
				else
				{
					flag = 0;
				}
			}
			if(flag)
			{
				HeapArray[i] = HeapArray[n - 1];
				HeapArray[--n] = 0;
				if(i == (n - 1))
				{
					return;
				}
				DownHeap(i);
			}
			else       
			{
				cout << "Element Not Found" << endl;
			}
		}
		
		void DescendingSort()
		{
			int sorted[n];
			Heap temp;
			for(int i = 0; i < n; i++)
			{
				temp.insert(HeapArray[i]);
			}
			for(int i = 0; i < n; i++)
			{
				sorted[i] = temp.First();
				temp.Delete(temp.First());
			}
			
			for(int i = 0; i < n; i++)
			{
				cout << sorted[i] << "\t";
			}
			cout << endl;
		}
		
		void AscendingSort()
		{
			Heap temp;
			for(int i = 0; i < n; i++)
			{
				temp.insert(HeapArray[i]);
			}
			int sorted[n];
			for(int i = n - 1; i >= 0; i--)
			{
				sorted[i] = temp.First();
				temp.Delete(temp.First());
			}
			for(int i = 0; i < n; i++)
			{
				cout << sorted[i] << "\t";
			}
			cout << endl;
		}
		
		int First()
		{
			return HeapArray[0];
		}
		void Display()
		{
			for (int i = 0; i < n; i++)
			{
				cout << HeapArray[i] << endl;
			}
			for(int i = 0; i < n; i++)
			{
				int l = (2*(i)) + 1;
				int r = (2*(i)) + 2;
				if(HeapArray[l] == 0 && HeapArray[r] == 0)
				{
					continue;
				}
				cout << HeapArray[i] << "\t Left: " << HeapArray[l] << "\t Right: " << HeapArray[r] << endl;
			}
		}
};

int main()
{
	Heap heap;
	heap.insert(5);
	heap.insert(3);
	heap.insert(1);
	heap.insert(2);
	heap.insert(4);
	heap.Display();
	heap.Delete(1);
	cout << endl << endl << "-----------" << endl;
	heap.Display();
	cout << endl << endl << "-----------" << endl;
	heap.AscendingSort();
	heap.DescendingSort();
	heap.Display();
	return 0;
}
