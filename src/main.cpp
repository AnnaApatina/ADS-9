// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include "tree.h"

int main() {
  //tree use
  std::vector<char> in = {'1', '2', '3'};
  PMTree tree(in);
  auto all = getPerms(tree);
  for (auto& perm : all) {
    for (char c : perm)
      std::cout << c;
    std::cout << '\n';
  }
  //getPerm1-2
  auto p1 = getPerm1(tree, 1);
  auto p2 = getPerm2(tree, 2);
  for (char c : p1)
    std::cout << c;
  for (char c : p2)
    std::cout << c;
  std::cout << '\n';
  //time plot
  
  return 0;
}
