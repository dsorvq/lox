#include "lox/scanner/scanner.hpp"

#include <gtest/gtest.h>

#include "lox/token/token.hpp"

TEST(ScannerTest, SingleTokens) {
  std::string input = "(){},.-+;/*";
  std::vector<char> source(input.begin(), input.end());
  std::span<char> source_span(source);
  lox::Scanner scanner(source_span);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 12);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kLeftParent);
  EXPECT_EQ(tokens[0].lexeme_, "(");
  EXPECT_EQ(tokens[1].type_, lox::TokenType::kRightParent);
  EXPECT_EQ(tokens[1].lexeme_, ")");
  EXPECT_EQ(tokens[2].type_, lox::TokenType::kLeftBrace);
  EXPECT_EQ(tokens[2].lexeme_, "{");
  EXPECT_EQ(tokens[3].type_, lox::TokenType::kRightBrace);
  EXPECT_EQ(tokens[3].lexeme_, "}");
  EXPECT_EQ(tokens[4].type_, lox::TokenType::kComma);
  EXPECT_EQ(tokens[4].lexeme_, ",");
  EXPECT_EQ(tokens[5].type_, lox::TokenType::kDot);
  EXPECT_EQ(tokens[5].lexeme_, ".");
  EXPECT_EQ(tokens[6].type_, lox::TokenType::kMinus);
  EXPECT_EQ(tokens[6].lexeme_, "-");
  EXPECT_EQ(tokens[7].type_, lox::TokenType::kPlus);
  EXPECT_EQ(tokens[7].lexeme_, "+");
  EXPECT_EQ(tokens[8].type_, lox::TokenType::kSemicolon);
  EXPECT_EQ(tokens[8].lexeme_, ";");
  EXPECT_EQ(tokens[9].type_, lox::TokenType::kSlash);
  EXPECT_EQ(tokens[9].lexeme_, "/");
  EXPECT_EQ(tokens[10].type_, lox::TokenType::kStar);
  EXPECT_EQ(tokens[10].lexeme_, "*");
  EXPECT_EQ(tokens[11].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[11].lexeme_, "");
}

TEST(ScannerTest, SingleTokensWithWhitespaces) {
  std::string input = "( ) { } \t, \n\t\t. - + ; / *";
  std::vector<char> source(input.begin(), input.end());
  std::span<char> source_span(source);
  lox::Scanner scanner(source_span);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 12);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kLeftParent);
  EXPECT_EQ(tokens[0].lexeme_, "(");
  EXPECT_EQ(tokens[1].type_, lox::TokenType::kRightParent);
  EXPECT_EQ(tokens[1].lexeme_, ")");
  EXPECT_EQ(tokens[2].type_, lox::TokenType::kLeftBrace);
  EXPECT_EQ(tokens[2].lexeme_, "{");
  EXPECT_EQ(tokens[3].type_, lox::TokenType::kRightBrace);
  EXPECT_EQ(tokens[3].lexeme_, "}");
  EXPECT_EQ(tokens[4].type_, lox::TokenType::kComma);
  EXPECT_EQ(tokens[4].lexeme_, ",");
  EXPECT_EQ(tokens[5].type_, lox::TokenType::kDot);
  EXPECT_EQ(tokens[5].lexeme_, ".");
  EXPECT_EQ(tokens[6].type_, lox::TokenType::kMinus);
  EXPECT_EQ(tokens[6].lexeme_, "-");
  EXPECT_EQ(tokens[7].type_, lox::TokenType::kPlus);
  EXPECT_EQ(tokens[7].lexeme_, "+");
  EXPECT_EQ(tokens[8].type_, lox::TokenType::kSemicolon);
  EXPECT_EQ(tokens[8].lexeme_, ";");
  EXPECT_EQ(tokens[9].type_, lox::TokenType::kSlash);
  EXPECT_EQ(tokens[9].lexeme_, "/");
  EXPECT_EQ(tokens[10].type_, lox::TokenType::kStar);
  EXPECT_EQ(tokens[10].lexeme_, "*");
  EXPECT_EQ(tokens[11].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[11].lexeme_, "");
}
