#include <print>

#include "different_tests.hpp"

void LaunchTests() {
  std::println("Run all tests...");

  Tests::DirSnifferTests();

  std::println("Completed.");
}

int main(int argc, char** argv) {
  LaunchTests();
  return 0;
}
