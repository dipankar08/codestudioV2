/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student {
  string name;
  int mark;

public:
  Student(string name, int mark) : name(name), mark(mark) {}
  friend ostream &operator<<(ostream &output, const Student &s) {
    output << "Student( " << s.name << " , " << s.mark << " )";
    return output;
  }
  string getName() { return name; }
  int getMark() { return mark; }
};

#if 0
int main() {
  vector<Student> v;
  // insert
  v.push_back(Student("A", 50));
  v.push_back(Student("B", 20));
  v.push_back(Student("C", 30));
  // iterate
  cout << "Print all:" << endl;
  for (auto s : v) {
    cout << s << endl;
  }
  // properties
  cout << "Size : " << v.size() << endl;
  cout << "Capacity : " << v.capacity() << endl;
  cout << "front : " << v.front() << endl;
  cout << "back : " << v.back() << endl;
  cout << "2nd : " << v[1] << endl;
  cout << "IsEmpty : " << v.empty() << endl;
  // sort
  std::sort(v.begin(), v.end(), [](Student &lhs, Student &rhs) {
    return lhs.getMark() < rhs.getMark();
  });
  cout << "After Sort:" << endl;
  for (auto s : v) {
    cout << s << endl;
  }
  // delete
  v.pop_back();
  cout << "After Delete:" << v.size() << endl;
  // clear
  v.clear();
  cout << "After Clear:" << v.size() << endl;
}
#endif

#if 0
#include <deque>
int main() {
  deque<int> dq;
  //push.
  dq.push_back(2);
  dq.push_back(3);
  dq.push_front(1);
  cout<<"DeQueue is:";
  for (auto i : dq) {
    cout << i << " ";
  }
  cout<<endl<<"Front:"<<dq.front()<<"  Back:"<<dq.back()<<" Size:"<<dq.size()<<endl;
  dq.pop_front();
  dq.pop_back();
  cout<<"DeQue is:";
  for (auto i : dq) {
    cout << i << " ";
  }
  cout<<endl;
}
#endif
#if 0
#include <list>
int main() {
  list<int> myList = {1, 2, 3};
  cout << "Print all After insert:" << endl;
  list<int>::iterator it = myList.begin();
  myList.insert(it, 0); // {0,1,2,3}
  myList.erase(it);     // {0, 2, 3}
  for (auto l : myList) {
    cout << l << endl;
  }
}
#endif

#if 0
#include <set>
#include <unordered_set>
int main() {
  set<int> mySet;
  // unordered_set<int> mySet;
  mySet.insert(2);                    // {2}
  mySet.insert(2);                    // {2}
  mySet.insert(3);                    // {2, 3}
  mySet.insert(1);                    // {1, 2, 3}
  mySet.insert(4);                    // {1, 2, 3, 4}
  mySet.erase(4);                     // {1, 2, 3}
  if (mySet.find(3) != mySet.end()) { // way to find.
    cout << "Found" << endl;
  } else {
    cout << "Not Found" << endl;
  }
  // print will print in a sorted in case of set and might be random in case of
  // unorder_set
  for (auto l : mySet) {
    cout << l << endl;
  }
}
#endif

#if 0
#include <map>
int main() {
   map<int, string> m;
  // insert
  m.insert(pair<int, string>(2, "dip"));
  m.insert(make_pair(1, "sup"));
  m.insert(make_pair(3, "guo"));
  // iterate
  cout << "\n\nIterate after all insert:" << endl;
  for (pair<int, string> m1 : m) {
    cout << m1.first << " => " << m1.second << endl;
  }
  // something like has_key, get returns a iterator of pair
  if (m.find(1) != m.end()) {
    map<int, string>::iterator ret = m.find(1);
    cout << "Found :" << (*ret).first << " => " << (*ret).second << endl;
  }
  // update: find and update
  if (m.find(3) != m.end()) {
    m[3] = "GODO";
  }
  cout << "\n\nIterate after all update:" << endl;
  for (pair<int, string> m1 : m) {
    cout << m1.first << " => " << m1.second << endl;
  }
  // delete an entry
  m.erase(3);
  cout << "\n\nIterate after dlete 3:" << endl;
  for (pair<int, string> m1 : m) {
    cout << m1.first << " => " << m1.second << endl;
  }
  // delete all
  m.clear();
  cout << "\n\nSize after clear : " << m.size() << "\n\n";
}
#endif

#if 0
#include <unordered_map>
int main() {
    unordered_map < int,  string > om;
    om.insert(make_pair(10,  "Dipankar"));
    om.insert(make_pair(9,  "Dipankar"));
    om.insert(make_pair(11,  "Dipankar"));
    //iterate but in unorder fashion,.
    cout << "\n\nIterate after all insert:" << endl;
    for(pair < int,  string > om1 : om) {
        cout << om1.first << " : " << om1.second << endl;
    }
    //update 
    om[11]="TEST_VALUE";
    // check
    if(om.find(11)!= om.end()){
      cout<<"12 found - value:"<<om.find(11)->second<<endl;
    } else{
      cout<<"12 not found"<<endl;
    }
    cout << "\n\nPrinting some properties:" << endl;
    cout << "Load Factor = " << om.load_factor() << endl;
    cout << "Total Bucket size = " << om.bucket_count() << endl;
    cout << "which bucket = " << om.bucket(10) << endl;
}
#endif

#include <algorithm> // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector> // std::vector
int main() {
  std::vector<int> v = {10, 20, 30, 5, 15};
  // make heap
  std::make_heap(v.begin(), v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';

  // take the top
  std::pop_heap(v.begin(), v.end());
  v.pop_back();
  std::cout << "max heap after pop : " << v.front() << '\n';

  // inset and do the re-heap.
  v.push_back(99);
  std::push_heap(v.begin(), v.end());
  std::cout << "max heap after push: " << v.front() << '\n';

  // sort heap.
  std::sort_heap(v.begin(), v.end());
  std::cout << "final sorted range :";
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << ' ' << v[i];
  }
  std::cout << '\n';

  return 0;
}