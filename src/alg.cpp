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
  std::sort(remaining.begin(), remaining.end());
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
    for (Node* child : tree.getRoot()->children) {
      path.clear();
      permutations(child, path, out);
    }
  }
  return out;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
  auto all = getAllPerms(tree);
  if (num <= 0 || num > static_cast<int>(all.size())) {
    return {};
  }
  return all[num - 1];
}

int countPerm(Node* node) {
  if (!node || node->children.empty()) {
    return 1;
  }
  int total = 0;
  for (Node* child : node->children) {
    total += countPerm(child);
  }
  return total;
}

bool navPerm(Node* node, int& targIdx, int& currIdx,
             std::vector<char>& path) {
  if (!node) return false;
  path.push_back(node->value);
  if (node->children.empty()) {
    if (currIdx == targIdx) {
      return true;
    } else {
      ++currIdx;
      path.pop_back();
      return false;
    }
  }
  for (Node* child : node->children) {
    int subCount = countPerm(child);
    if (targIdx <= subCount + currIdx - 1) {
      if (navPerm(child, targIdx, currIdx, path)) {
        return true;
      }
    } else {
      currIdx += subCount;
    }
  }
  path.pop_back();
  return false;
}

std::vector<char> getPerm2(PMTree& tree, int num) {
  if (!tree.getRoot() || num <= 0 || tree.getRoot()->children.empty()) {
    return {};
  }
  int idx = 1;
  for (Node* child : tree.getRoot()->children) {
    std::vector<char> path;
    int subCount = countPerm(child);
    if (num <= subCount) {
      if (navPerm(child, num, idx, path)) {
        path.insert(path.begin(), child->value);
        return path;
      }
      break;
    } else {
      idx += subCount;
    }
  }
  return {};
}
