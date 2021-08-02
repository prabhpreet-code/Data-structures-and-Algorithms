#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int x)
  {
    data = x;
    left = NULL;
    right = NULL;
  }
};

void vertical_order(Node *root, map<int, vector<int>> &m, int d = 0)
{

  if (root == NULL)
  {
    return;
  }

  m[d].push_back(root->data); //push part. data to the key
  vertical_order(root->left, m, d - 1);  //left side deduct 1
  vertical_order(root->right, m, d + 1); //right side add 1

}

int main()
{
  //nodes of tree
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  root->right->left = new Node(6);
  root->right->right = new Node(7);

  root->right->right->right = new Node(9);
  root->left->right->right = new Node(8);

  //hashmap to store the same values related to particular keys
  map<int, vector<int>> m;
  vertical_order(root, m);

  // print
  for (auto it : m)
  {
    cout << it.first << "->";
    for (auto ip : it.second)
    {
      cout << ip << ",";
    }
    cout << endl;
  }

  return 0;
}