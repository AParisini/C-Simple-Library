#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(vector<int> &heapTree, int i){

  int size = heapTree.size();
  int largest = i;
  int leftBranch = 2 * i + 1;
  int rightBranch = 2 * i + 2;
  if (leftBranch < size && heapTree[leftBranch] > heapTree[largest])
    largest = leftBranch;
  if (rightBranch < size && heapTree[rightBranch] > heapTree[largest])
    largest = rightBranch;

  if (largest != i){
    swap(&heapTree[i], &heapTree[largest]);
    heapify(heapTree, largest);
  }
}
void insert(vector<int> &heapTree, int newNum){
    
  int size = heapTree.size();
  if (size == 0){
    heapTree.push_back(newNum);
  }
  else{
    heapTree.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--){
      heapify(heapTree, i);
    }
  }
}
void deleteNode(vector<int> &heapTree, int num){

  int size = heapTree.size();
  int i;
  for (i = 0; i < size; i++){
    if (num == heapTree[i])
      break;
  }
  swap(&heapTree[i], &heapTree[size - 1]);

  heapTree.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--){
    heapify(heapTree, i);
  }

}
void printArray(vector<int> &heapTree){
  for (int i = 0; i < heapTree.size(); ++i)
    cout << heapTree[i] << " ";
  cout << "\n";
}

int main()
{
  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);

  cout << "Max-Heap array: ";
  printArray(heapTree);

  deleteNode(heapTree, 4);
  cout << "After Deletion: ";

  printArray(heapTree);
}