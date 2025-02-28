project(ExampleApp VERSION 0.1)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp CMAKE_CONFIGURE_DEPENDS)
add_executable(${PROJECT_NAME} ${SRC_FILES})

if(NOT CMAKE_BUILD_TYPE)
	message("Build Type not set, defaulting to Debug...")
	set(CMAKE_BUILD_TYPE Debug)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_definitions(${PROJECT_NAME} PUBLIC _DEBUG=1)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC 
                                                ${CMAKE_CURRENT_SOURCE_DIR}/src 
                                                ${CMAKE_SOURCE_DIR}/Core
                                                )
                                                
target_link_libraries(${PROJECT_NAME} PUBLIC Core)
