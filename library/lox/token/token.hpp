#pragma once

#include <string>

namespace lox {

enum class TokenType {
  kLeftParent,
  kRightParent,
  kLeftBrace,
  kRightBrace,
  kComma,
  kDot,
  kMinus,
  kPlus,
  kSemicolon,
  kSlash,
  kStar,

  kEOF,
};

struct Token {
  Token() {
  }

  Token(TokenType type, std::string lexeme)
      : type_(type),
        lexeme_(std::move(lexeme)) {
  }

  TokenType type_;
  std::string lexeme_;
};

}  // namespace lox
