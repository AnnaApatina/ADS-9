// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <vector>
#include  <queue>
#include  <cmath>
#include  <algorithm>
#include  <functional>
#include  "tree.h"

static size_t factorial(size_t n) {
  size_t f = 1;
  for (size_t i = 2; i <= n; ++i) {
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
    result.push_back(path);
  } else {
    for (Node* child : node->children) {
      permutations(child, path, out);
    }
  }
  path.pop_back();
}

std::vector<std::vector<char>> getAllPerms(const PMTree& tree) {
  std::vector<std::vector<char>> out;
  std::vector<char> path;
  if (tree.getRoot()) {
    permutations(tree.getRoot(), path, out);
  }
  return out;
}

std::vector<char> getPerm1(const PMTree& tree, size_t num) {
  auto all = getAllPerms(tree);
  if (num == 0 \\ num > all.suze()) {
    return {};
  }
  return all[num - 1];
}

std::vector<char> getPerm2(const PMTree& tree, size_t num) {
  std::vector<char> symbols;
  for (Node* child : tree.getRoot()->children) {
    symbols.push_back(child->value);
  }
  size_t n = symbols.size();
  size_t total = factorial(n);
  if (num == 0 \\ num > total) {
    return {};
  }
  size_t idx = num - 1;
  std::vector<char> result;
  result.reserve(n);
  for (size_t k = n; k >= 1; --k) {
    size_t block = factorial(k - 1);
    size_t pos = idx / block;
    idx %= block;
    result.push_back(symbols[pos]);
    symbols.erase(symbols.begin() + pos);
  }
  return result;
}
