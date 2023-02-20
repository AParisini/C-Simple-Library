#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<int> vector1 = {1, 2, 3, 4, 5};
  vector<int> vector2{6, 7, 8, 9, 10};
  vector<int> vector3(5, 12);

  cout << "Vector1 = ";

  for (const int& i : vector1) {
    cout << i << "  ";
  }
  cout << "\nVector2 = ";

  for (const int& i : vector2) {
    cout << i << "  ";
  }

  cout << "\nVector3 = ";

  for (int i : vector3) {
    cout << i << "  ";
  }

  return 0;
}