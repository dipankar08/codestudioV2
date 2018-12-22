/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
template <class T>
void printVec(vector<T> v){
  for(auto a: v){
    cout<<a<<", ";
  }
  cout<<endl;
}


template<typename T>
void printStack(const std::stack<T>& s)
{
    typedef typename std::stack<T>::container_type Container;

    const auto containerPtr = reinterpret_cast<const Container*>(&s);
    cout<<"[";
    for(auto e : *containerPtr){
        cout << e << ",";
    }
    cout<<"]";
}
