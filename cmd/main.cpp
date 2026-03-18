#include <iostream>
#include <print>
#include <string>

#include "lox/scanner/scanner.hpp"

int main() {
  std::string source;
  std::getline(std::cin, source);

  lox::Scanner scanner(source);
  auto tokens = scanner.ScanAll();

  for (const auto& token : tokens) {
    std::println("l: {}", token.lexeme_);
  }
}
