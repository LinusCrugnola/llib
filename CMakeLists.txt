cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 20)
enable_testing()

# define folders
set(LLIB_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LLIB_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

# include google test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# include sources and tests
include(cmake/llibSources.cmake)
include(cmake/llibTests.cmake)

# compile llib sources in static library
add_library(
    llib
    STATIC
    ${LLIB_SOURCES}
)
target_include_directories(
    llib
    PUBLIC
    include
    PRIVATE
    ${LLIB_SRC_DIR}
    ${LLIB_TEST_DIR}
)
target_compile_options(
    llib
    PUBLIC
    -DUNIT_TEST -Wextra -pedantic -Werror --coverage
)

# build tests
project(llibUnitTests)
add_executable(
    ${PROJECT_NAME}
    test/UnitTests.cpp
    ${LLIB_TESTS}
)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    include
    src
    test
)
target_compile_options(
    ${PROJECT_NAME}
    PUBLIC -DUNIT_TEST -Wextra -pedantic -Werror --coverage
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

#link test-executable
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    gtest GTest::gtest_main pthread llib
)
target_link_options(
    ${PROJECT_NAME}
    PUBLIC
    --coverage
)