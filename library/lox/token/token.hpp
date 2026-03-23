#pragma once

#include <array>
#include <optional>
#include <string>
#include <string_view>

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
  kBang,
  kEqual,
  kLess,
  kGreater,

  kBangEqual,
  kEqualEqual,
  kLessEqual,
  kGreaterEqual,

  kString,
  kNumber,

  kAnd,
  kClass,
  kElse,
  kFalse,
  kFor,
  kFun,
  kIf,
  kNil,
  kOr,
  kPrint,
  kReturn,
  kSuper,
  kThis,
  kTrue,
  kVar,
  kWhile,

  kIdentifier,

  kEOF,

  kError,
};

constexpr std::optional<lox::TokenType> KeywordToTokenType(
    std::string_view lexeme) {
  struct KeywordEntry {
    std::string_view lexeme;
    lox::TokenType type;
  };

  constexpr std::array<KeywordEntry, 16> kKeywords = {{
      {"and", lox::TokenType::kAnd},
      {"class", lox::TokenType::kClass},
      {"else", lox::TokenType::kElse},
      {"false", lox::TokenType::kFalse},
      {"for", lox::TokenType::kFor},
      {"fun", lox::TokenType::kFun},
      {"if", lox::TokenType::kIf},
      {"nil", lox::TokenType::kNil},
      {"or", lox::TokenType::kOr},
      {"print", lox::TokenType::kPrint},
      {"return", lox::TokenType::kReturn},
      {"super", lox::TokenType::kSuper},
      {"this", lox::TokenType::kThis},
      {"true", lox::TokenType::kTrue},
      {"var", lox::TokenType::kVar},
      {"while", lox::TokenType::kWhile},
  }};

  for (const auto& entry : kKeywords) {
    if (entry.lexeme == lexeme) {
      return entry.type;
    }
  }
  return std::nullopt;
}

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
