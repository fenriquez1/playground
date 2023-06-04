enable_testing()

add_executable(
  main_test
  MainTest.cpp
)

target_include_directories(main_test PRIVATE ./include)

target_link_libraries(
  main_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(main_test)
