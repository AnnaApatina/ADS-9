// Copyright 2022 NNTU-CS
#include <vector>
#include <string>

#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

struct Node {
  char value;
  std::vector<Node*> children;
  explicit Node(char v) : value(v) {}
};
class PMTree {
 public:
  explicit PMTree(const std::vector<char>& symbols);
  ~PMTree();
  Node* getRoot() const { return root; }

 private:
  Node* root;
  void buildSubtree(Node* node, std::vector<char> remaining);
  void deleteSubtree(Node* node);
};
std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<char> getPerm2(PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
