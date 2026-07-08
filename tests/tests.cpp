#include "catch2/catch_template_test_macros.hpp"
#include "catch2/catch_test_macros.hpp"

#include <concepts>

TEST_CASE("Testing 1, 2, 3...", "[test_tag]") {
  REQUIRE(true);
  REQUIRE(!false);
}

TEMPLATE_TEST_CASE("Template testing 1, 2, 3...", "[test_tag]", bool, int) {
  TestType const a{};
  TestType const b{};

  REQUIRE(std::same_as<TestType, TestType>);
  REQUIRE(std::same_as<decltype(a), decltype(b)>);
}
