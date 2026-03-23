#include "scanner.hpp"

#include <cassert>
#include <cctype>
#include <iostream>
#include <print>
#include <string>

#include "lox/token/token.hpp"

namespace lox {

Scanner::Scanner(std::span<char> source)
    : source_(source) {
}

Token Scanner::ScanNext() {
  SkipWhitespace();

  start_ = current_;

  if (IsAtEnd()) {
    return MakeToken(TokenType::kEOF);
  }

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

    case '!':
      return MakeToken(AdvanceIfMatch('=') ? TokenType::kBangEqual
                                           : TokenType::kBang);
    case '=':
      return MakeToken(AdvanceIfMatch('=') ? TokenType::kEqualEqual
                                           : TokenType::kEqual);
    case '<':
      return MakeToken(AdvanceIfMatch('=') ? TokenType::kLessEqual
                                           : TokenType::kLess);
    case '>':
      return MakeToken(AdvanceIfMatch('=') ? TokenType::kGreaterEqual
                                           : TokenType::kGreater);

    case '"':
      return MakeStringToken();

    default:
      if (IsDigit(c)) {
        return MakeNumberToken();
      }

      // TODO: better error handling
      std::print(std::cerr, "Unexpected symbol");
      return MakeToken(TokenType::kError);
  }
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

char Scanner::PeekNext() {
  if (current_ + 1 >= source_.size()) {
    return '\0';
  }

  return source_[current_ + 1];
}

bool Scanner::IsDigit(char c) {
  return std::isdigit(c) == 1;
}

Token Scanner::MakeToken(TokenType type) {
  return Token(type, std::string(source_.data() + start_, current_ - start_));
}

Token Scanner::MakeStringToken() {
  while (Peek() != '"') {
    if (Peek() == '\n') {
      ++line_;
    }
    Advance();
  }

  if (IsAtEnd()) {
    // TODO: better error handing
    std::print(std::cerr, "Unterminated string");
  }

  Advance();
  return MakeToken(TokenType::kString);
}

Token Scanner::MakeNumberToken() {
  while (IsDigit(Peek())) {
    Advance();
  }

  if (Peek() == '.') {
    Advance();
    while (IsDigit(Peek())) {
      Advance();
    }
  }

  return MakeToken(TokenType::kNumber);
}

void Scanner::SkipWhitespace() {
  while (!IsAtEnd()) {
    auto c = Peek();
    switch (c) {
      case ' ':
      case '\t':
      case '\r':
        Advance();
        break;
      case '\n':
        ++line_;
        Advance();
        break;
      default:
        return;
    }
  }
}

}  // namespace lox
