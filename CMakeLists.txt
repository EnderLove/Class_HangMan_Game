cmake_minimum_required(VERSION 3.15)

# Project name and language standard
project(HangmanGame LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable target from all source files in src
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

# Add include directories for headers
target_include_directories(${PROJECT_NAME} PRIVATE includes)

# Optional: if you have resource files to copy to build output
set(RESOURCE_FILES
    resources/*  # Adjust pattern as needed
)
foreach(RESOURCE_FILE ${RESOURCE_FILES})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FILE}
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endforeach()
message(STATUS "Source files: ${SOURCES}")
