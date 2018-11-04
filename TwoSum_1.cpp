#include <iostream>
#include <string>
#include <vector>
using namespace std;
void twoSum(vector<int> arr,int K) {
  for (int i = 0; i < arr.size(); i++) { 
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[i] + arr[j] == K) {
        cout<<"Found :"<<arr[i]<<" + "<<arr[j]<<": "+K;
      }
    }
  }
}

int main()
{
    twoSum({3,2,4,1},10);
}
