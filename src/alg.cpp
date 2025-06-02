// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <vector>
#include  <queue>
#include  <cmath>
#include  <algorithm>
#include  <functional>
#include  "tree.h"

static int factorial(int n) {
  int f = 1;
  for (int i = 2; i <= n; ++i) {
    f *= i;
  }
  return f;
}

PMTree::PMTree(const std::vector<char>& symbols) {
  root = new Node('\0');
  buildSubtree(root, symbols);
}

PMTree::~PMTree() {
  deleteSubtree(root);
}

void PMTree::buildSubtree(Node* node, std::vector<char> remaining) {
  if (remaining.empty()) return;
  for (size_t i = 0; i < remaining.size(); ++i) {
    char c = remaining[i];
    Node* child = new Node(c);
    node->children.push_back(child);
    std::vector<char> next = remaining;
    next.erase(next.begin() + i);
    buildSubtree(child, next);
  }
}

void PMTree::deleteSubtree(Node* node) {
  if (!node) return;
  for (Node* ch : node->children) {
    deleteSubtree(ch);
  }
  delete node;
}

void permutations(Node* node, std::vector<char>& path,
                 std::vector<std::vector<char>>& out) {
  path.push_back(node->value);
  if (node->children.empty()) {
    out.push_back(path);
  } else {
    for (Node* child : node->children) {
      permutations(child, path, out);
    }
  }
  path.pop_back();
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  std::vector<std::vector<char>> out;
  std::vector<char> path;
  if (tree.getRoot()) {
    permutations(tree.getRoot(), path, out);
  }
  return out;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
  auto all = getAllPerms(tree);
  if (num == 0 || num > all.size()) {
    return {};
  }
  return all[num - 1];
}

std::vector<char> getPerm2(PMTree& tree, int num) {
  std::vector<char> symbols;
  for (Node* child : tree.getRoot()->children) {
    symbols.push_back(child->value);
  }
  int n = symbols.size();
  int total = factorial(n);
  if (num == 0 || num > total) {
    return {};
  }
  int idx = num - 1;
  std::vector<char> result;
  result.reserve(n);
  for (int k = n; k >= 1; --k) {
    int block = factorial(k - 1);
    int pos = idx / block;
    idx %= block;
    result.push_back(symbols[pos]);
    symbols.erase(symbols.begin() + pos);
  }
  return result;
}
