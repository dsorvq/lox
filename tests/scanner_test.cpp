#include "lox/scanner/scanner.hpp"

#include <gtest/gtest.h>

#include "lox/token/token.hpp"

TEST(ScannerTest, SingleTokens) {
  std::string input = "(){},.-+;/*";
  lox::Scanner scanner(input);

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
  lox::Scanner scanner(input);

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

TEST(ScannerTest, ComparisonAndEqualityTokens) {
  std::string input = "! = < > != == <= >= ";
  lox::Scanner scanner(input);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 9);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kBang);
  EXPECT_EQ(tokens[0].lexeme_, "!");
  EXPECT_EQ(tokens[1].type_, lox::TokenType::kEqual);
  EXPECT_EQ(tokens[1].lexeme_, "=");
  EXPECT_EQ(tokens[2].type_, lox::TokenType::kLess);
  EXPECT_EQ(tokens[2].lexeme_, "<");
  EXPECT_EQ(tokens[3].type_, lox::TokenType::kGreater);
  EXPECT_EQ(tokens[3].lexeme_, ">");
  EXPECT_EQ(tokens[4].type_, lox::TokenType::kBangEqual);
  EXPECT_EQ(tokens[4].lexeme_, "!=");
  EXPECT_EQ(tokens[5].type_, lox::TokenType::kEqualEqual);
  EXPECT_EQ(tokens[5].lexeme_, "==");
  EXPECT_EQ(tokens[6].type_, lox::TokenType::kLessEqual);
  EXPECT_EQ(tokens[6].lexeme_, "<=");
  EXPECT_EQ(tokens[7].type_, lox::TokenType::kGreaterEqual);
  EXPECT_EQ(tokens[7].lexeme_, ">=");
  EXPECT_EQ(tokens[8].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[8].lexeme_, "");
}

TEST(ScannerTest, SingleStringToken) {
  std::string input = "\"some <= string\"";
  lox::Scanner scanner(input);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 2);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kString);
  EXPECT_EQ(tokens[0].lexeme_, "\"some <= string\"");
  EXPECT_EQ(tokens[1].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[1].lexeme_, "");
}

TEST(ScannerTest, MultipleStringTokens) {
  std::string input = "!= \"some\" <= \"other\" ==";
  lox::Scanner scanner(input);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 6);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kBangEqual);
  EXPECT_EQ(tokens[0].lexeme_, "!=");

  EXPECT_EQ(tokens[1].type_, lox::TokenType::kString);
  EXPECT_EQ(tokens[1].lexeme_, "\"some\"");

  EXPECT_EQ(tokens[2].type_, lox::TokenType::kLessEqual);
  EXPECT_EQ(tokens[2].lexeme_, "<=");

  EXPECT_EQ(tokens[3].type_, lox::TokenType::kString);
  EXPECT_EQ(tokens[3].lexeme_, "\"other\"");

  EXPECT_EQ(tokens[4].type_, lox::TokenType::kEqualEqual);
  EXPECT_EQ(tokens[4].lexeme_, "==");

  EXPECT_EQ(tokens[5].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[5].lexeme_, "");
}

TEST(ScannerTest, NumberToken) {
  std::string input = "1234 != 543.3";
  lox::Scanner scanner(input);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 4);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kNumber);
  EXPECT_EQ(tokens[0].lexeme_, "1234");

  EXPECT_EQ(tokens[1].type_, lox::TokenType::kBangEqual);
  EXPECT_EQ(tokens[1].lexeme_, "!=");

  EXPECT_EQ(tokens[2].type_, lox::TokenType::kNumber);
  EXPECT_EQ(tokens[2].lexeme_, "543.3");

  EXPECT_EQ(tokens[3].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[3].lexeme_, "");
}

TEST(ScannerTest, OneKeyword) {
  std::string input = "and";
  lox::Scanner scanner(input);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 2);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kAnd);
  EXPECT_EQ(tokens[0].lexeme_, "and");
  EXPECT_EQ(tokens[1].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[1].lexeme_, "");
}

TEST(ScannerTest, Keywords) {
  std::string input =
      "and class else false for fun if nil or print return super this true var "
      "while";
  std::vector<char> source(input.begin(), input.end());
  std::span<char> source_span(source);
  lox::Scanner scanner(source_span);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 17);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kAnd);
  EXPECT_EQ(tokens[0].lexeme_, "and");
  EXPECT_EQ(tokens[1].type_, lox::TokenType::kClass);
  EXPECT_EQ(tokens[1].lexeme_, "class");
  EXPECT_EQ(tokens[2].type_, lox::TokenType::kElse);
  EXPECT_EQ(tokens[2].lexeme_, "else");
  EXPECT_EQ(tokens[3].type_, lox::TokenType::kFalse);
  EXPECT_EQ(tokens[3].lexeme_, "false");
  EXPECT_EQ(tokens[4].type_, lox::TokenType::kFor);
  EXPECT_EQ(tokens[4].lexeme_, "for");
  EXPECT_EQ(tokens[5].type_, lox::TokenType::kFun);
  EXPECT_EQ(tokens[5].lexeme_, "fun");
  EXPECT_EQ(tokens[6].type_, lox::TokenType::kIf);
  EXPECT_EQ(tokens[6].lexeme_, "if");
  EXPECT_EQ(tokens[7].type_, lox::TokenType::kNil);
  EXPECT_EQ(tokens[7].lexeme_, "nil");
  EXPECT_EQ(tokens[8].type_, lox::TokenType::kOr);
  EXPECT_EQ(tokens[8].lexeme_, "or");
  EXPECT_EQ(tokens[9].type_, lox::TokenType::kPrint);
  EXPECT_EQ(tokens[9].lexeme_, "print");
  EXPECT_EQ(tokens[10].type_, lox::TokenType::kReturn);
  EXPECT_EQ(tokens[10].lexeme_, "return");
  EXPECT_EQ(tokens[11].type_, lox::TokenType::kSuper);
  EXPECT_EQ(tokens[11].lexeme_, "super");
  EXPECT_EQ(tokens[12].type_, lox::TokenType::kThis);
  EXPECT_EQ(tokens[12].lexeme_, "this");
  EXPECT_EQ(tokens[13].type_, lox::TokenType::kTrue);
  EXPECT_EQ(tokens[13].lexeme_, "true");
  EXPECT_EQ(tokens[14].type_, lox::TokenType::kVar);
  EXPECT_EQ(tokens[14].lexeme_, "var");
  EXPECT_EQ(tokens[15].type_, lox::TokenType::kWhile);
  EXPECT_EQ(tokens[15].lexeme_, "while");
  EXPECT_EQ(tokens[16].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[16].lexeme_, "");
}

TEST(ScannerTest, Identifiers) {
  std::string input = "foo bar baz _underscore _123 camelCase PascalCase";
  lox::Scanner scanner(input);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 8);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[0].lexeme_, "foo");
  EXPECT_EQ(tokens[1].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[1].lexeme_, "bar");
  EXPECT_EQ(tokens[2].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[2].lexeme_, "baz");
  EXPECT_EQ(tokens[3].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[3].lexeme_, "_underscore");
  EXPECT_EQ(tokens[4].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[4].lexeme_, "_123");
  EXPECT_EQ(tokens[5].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[5].lexeme_, "camelCase");
  EXPECT_EQ(tokens[6].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[6].lexeme_, "PascalCase");
  EXPECT_EQ(tokens[7].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[7].lexeme_, "");
}

TEST(ScannerTest, KeywordsAndIdentifiersMixed) {
  std::string input = "if ify var variable class classy";
  std::vector<char> source(input.begin(), input.end());
  std::span<char> source_span(source);
  lox::Scanner scanner(source_span);

  std::vector<lox::Token> tokens = scanner.ScanAll();

  ASSERT_EQ(tokens.size(), 7);

  EXPECT_EQ(tokens[0].type_, lox::TokenType::kIf);
  EXPECT_EQ(tokens[0].lexeme_, "if");

  EXPECT_EQ(tokens[1].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[1].lexeme_, "ify");

  EXPECT_EQ(tokens[2].type_, lox::TokenType::kVar);
  EXPECT_EQ(tokens[2].lexeme_, "var");

  EXPECT_EQ(tokens[3].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[3].lexeme_, "variable");

  EXPECT_EQ(tokens[4].type_, lox::TokenType::kClass);
  EXPECT_EQ(tokens[4].lexeme_, "class");

  EXPECT_EQ(tokens[5].type_, lox::TokenType::kIdentifier);
  EXPECT_EQ(tokens[5].lexeme_, "classy");

  EXPECT_EQ(tokens[6].type_, lox::TokenType::kEOF);
  EXPECT_EQ(tokens[6].lexeme_, "");
}
