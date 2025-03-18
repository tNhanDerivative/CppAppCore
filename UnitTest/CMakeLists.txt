cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)

project(TestCppAppCore LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        bf66935e07825318ae519675d73d0f3e313b3ec6 
)
FetchContent_MakeAvailable(googletest)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp CONFIGURE_DEPENDS)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
                                                ${CMAKE_SOURCE_DIR}
                                                ${CMAKE_SOURCE_DIR}/Core
                                                )

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

