#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct Node
{
  char left;
  char right;
};

vector<Node> nodes(26);

void preorder(char node)
{
  if (node == '.')
    return;
  cout << node;
  preorder(nodes[node - 'A'].left);
  preorder(nodes[node - 'A'].right);
}

void inorder(char node)
{
  if (node == '.')
    return;
  inorder(nodes[node - 'A'].left);
  cout << node;
  inorder(nodes[node - 'A'].right);
}

void postorder(char node)
{
  if (node == '.')
    return;
  postorder(nodes[node - 'A'].left);
  postorder(nodes[node - 'A'].right);
  cout << node;
}

int main()
{
  fastio;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    char node_item, left_item, right_item;
    cin >> node_item >> left_item >> right_item;
    nodes[node_item - 'A'] = {left_item, right_item};
  }

  preorder('A');
  cout << '\n';
  inorder('A');
  cout << '\n';
  postorder('A');
}