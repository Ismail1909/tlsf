cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_COLOR_DIAGNOSTICS ON)


project(tlsf VERSION 0.0.1 LANGUAGES CXX)


# Build tlsf library
add_library(tlsf STATIC ${CMAKE_SOURCE_DIR}/src/tlsf.cpp)
target_include_directories(tlsf PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare( # The hash represents a commit, update it regularly
  googletest
  URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)
FetchContent_MakeAvailable(googletest)

# Enable Google Test
enable_testing()

# Build test binary & link it to gtest & the tlsf library
add_executable(
  tlsf_tests
  ${CMAKE_SOURCE_DIR}/tests/tlsf_tests.cpp
)
target_include_directories(tlsf_tests PUBLIC ${CMAKE_SOURCE_DIR}/include) # to include tlsf header

target_link_libraries(
  tlsf_tests
  GTest::gtest_main
  tlsf
)

# Add the test binary to gtest.
include(GoogleTest)
gtest_discover_tests(tlsf_tests)


# Add tester main console
add_executable(
    tlsf_tester
    ${CMAKE_SOURCE_DIR}/main/main.cpp
)

target_link_libraries(
    tlsf_tester
    tlsf
)
target_include_directories(tlsf_tester PUBLIC ${CMAKE_SOURCE_DIR}/include) # to include tlsf header


