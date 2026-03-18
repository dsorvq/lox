add_executable(
  scanner_test
  scanner_test.cpp
)
target_link_libraries(
  scanner_test 
	${LIB_TARGET}
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(scanner_test)
