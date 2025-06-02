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
  //time plot - text
   // std::ofstream csv("result/experiment.csv");
   //  if (!csv.is_open()) {
   //      std::cerr << "Не удалось открыть файл для записи!\n";
   //      return 1;
   //  }

   //  csv << "n,time_getAllPerms,time_getPerm1,time_getPerm2\n";

   //  std::mt19937 rng(std::random_device{}());

   //  for (int n = 1; n <= 8; ++n) {
   //      std::vector<char> symbols;
   //      for (int i = 0; i < n; ++i)
   //          symbols.push_back('A' + i);

   //      PMTree testTree(symbols);

   //      int total = factorial(n);
   //      std::uniform_int_distribution<> dist(1, total);
   //      int num = dist(rng);

   //      // Замер времени для getAllPerms
   //      auto start = std::chrono::high_resolution_clock::now();
   //      getAllPerms(testTree);
   //      auto end = std::chrono::high_resolution_clock::now();
   //      double time_all = std::chrono::duration<double, std::milli>(end - start).count();

   //      // Замер времени для getPerm1
   //      start = std::chrono::high_resolution_clock::now();
   //      getPerm1(testTree, num);
   //      end = std::chrono::high_resolution_clock::now();
   //      double time_p1 = std::chrono::duration<double, std::milli>(end - start).count();

   //      // Замер времени для getPerm2
   //      start = std::chrono::high_resolution_clock::now();
   //      getPerm2(testTree, num);
   //      end = std::chrono::high_resolution_clock::now();
   //      double time_p2 = std::chrono::duration<double, std::milli>(end - start).count();

   //      csv << n << "," << time_all << "," << time_p1 << "," << time_p2 << "\n";
   //  }

   //  csv.close();

   //  std::cout << "Результаты эксперимента сохранены в файл result/experiment.csv\n";
  return 0;
}
