#include "scanner.hpp"

#include <cassert>
#include <string>

namespace lox {

Scanner::Scanner(std::span<char> source)
    : source_(source) {
}

Token Scanner::ScanNext() {
  start_ = current_;

  char c = Advance();

  switch (c) {
    case '(':
      return MakeToken(TokenType::kLeftParent);
    case ')':
      return MakeToken(TokenType::kRightParent);
    case '{':
      return MakeToken(TokenType::kLeftBrace);
    case '}':
      return MakeToken(TokenType::kRightBrace);
    case ',':
      return MakeToken(TokenType::kComma);
    case '.':
      return MakeToken(TokenType::kDot);
    case '-':
      return MakeToken(TokenType::kMinus);
    case '+':
      return MakeToken(TokenType::kPlus);
    case ';':
      return MakeToken(TokenType::kSemicolon);
    case '/':
      return MakeToken(TokenType::kSlash);
    case '*':
      return MakeToken(TokenType::kStar);
  }

  return MakeToken(TokenType::kEOF);
}

std::vector<Token> Scanner::ScanAll() {
  std::vector<Token> tokens;

  for (Token token = ScanNext();; token = ScanNext()) {
    tokens.push_back(std::move(token));

    if (tokens.back().type_ == TokenType::kEOF) {
      break;
    }
  }

  return tokens;
}

bool Scanner::IsAtEnd() {
  assert(current_ <= source_.size());
  return current_ == source_.size();
}

char Scanner::Advance() {
  if (IsAtEnd()) {
    return '\0';
  }
  return source_[current_++];
}

bool Scanner::AdvanceIfMatch(char c) {
  if (IsAtEnd() || source_[current_] != c) {
    return false;
  }

  ++current_;
  return true;
}

char Scanner::Peek() {
  if (IsAtEnd()) {
    return '\0';
  }

  return source_[current_];
}

Token Scanner::MakeToken(TokenType type) {
  return Token(type, std::string(source_.data() + start_, current_ - start_));
}

}  // namespace lox
