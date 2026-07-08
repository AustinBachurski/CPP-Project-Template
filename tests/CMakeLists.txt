add_executable(tests)

target_sources(tests PRIVATE
  tests.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

enable_warnings_for_target(tests)
enable_address_sanitizer_for_target(example)
enable_undefined_behavior_sanitizer_for_target(example)

catch_discover_tests(tests)
