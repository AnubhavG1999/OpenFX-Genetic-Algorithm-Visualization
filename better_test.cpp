#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src2/Genetics.h"
#include "../src/Individual.h"
#include <iostream>
#include <utility>

using namespace std;

TEST_CASE("Random number generator works fine") {
  int random_int_1=rand();
  int random_int_2=rand();

  REQUIRE(Genetics::random_num(random_int_1, random_int_2) != Genetics::random_num(random_int_2, random_int_1));
}

TEST_CASE("Gene Mutator works fine") {
  char mutated_member;
  mutated_member = Genetics::mutated_genes();
  bool flag = false;
  for(int i = 0; i < Genetics::GENES.size(); i++) {
    if (mutated_member == Genetics::GENES[i]) {
      flag = true;
    }
  }

  REQUIRE(flag == true);
}

TEST_CASE("Create Genome works fine") {
 string created_genome;
 created_genome = Genetics::create_gnome();

 REQUIRE(created_genome.size() == TARGET.size());
}

TEST_CASE("pop_front() works correctly") {
  LinkedList<int> test_list;
  test_list.push_back(2);
  test_list.push_back(3);
  test_list.push_back(4);
  test_list.pop_front();
  REQUIRE ( test_list.front() == 3 );
  REQUIRE ( test_list.size() == 2 );
}
