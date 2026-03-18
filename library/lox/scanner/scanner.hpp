#pragma once

#include <span>
#include <vector>

#include "lox/token/token.hpp"

namespace lox {

class Scanner {
 public:
  explicit Scanner(std::span<char> source);

  Token ScanNext();
  std::vector<Token> ScanAll();

 private:
	bool IsAtEnd();

	char Advance();
	bool AdvanceIfMatch(char c);

	char Peek();

	Token MakeToken(TokenType type);

 private:
  std::span<char> source_;
	size_t start_{0};
	size_t current_{0};
	size_t line_{1};
};

}  // namespace lox
