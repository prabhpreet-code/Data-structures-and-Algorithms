
#include <iostream>
#include <map>
using namespace std;

//difference between map and unordered_map is that map prints the values in sorted way
int main()
{
  map<string, int> m;

  //insert
  m.insert(make_pair("mango", 100));
  m.insert(make_pair("apple", 200));
  m.insert(make_pair("banana", 300));
  m.insert(make_pair("peaches", 100));

  //print1
  for (auto p : m)
  {
    cout << p.first << " " << p.second << endl;
  }

  //erase
  m.erase("apple");

  //print2
  for (auto it = m.begin(); it != m.end(); it++)
  {
    cout << it->first << " " << it->second << endl;
  }

  //find1 --output--address
  auto it2 = m.find("banana");
  if (it2 != m.end())
  {
    cout << m["banana"] << endl;
  }
  else
  {
    cout << "not found sorry";
  }

  //find2

  int i = m.count("peaches");
  if (i)
  {
    cout << "present:"
         << " " << m["peaches"] << endl;
  }
  else
  {
    cout << "sorry not present";
  }

  return 0;

}
