cmake_minimum_required(VERSION 3.15)

project(HangmanGame LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Gather all source files in src recursively
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

# Include headers from includes directory
target_include_directories(${PROJECT_NAME} PRIVATE includes)

# Gather resource files explicitly (fix Windows wildcard copy issue)
file(GLOB RESOURCE_FILES "resources/*")

# Copy each resource file to build output directory after build
foreach(RESOURCE_FILE ${RESOURCE_FILES})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${RESOURCE_FILE}
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endforeach()

message(STATUS "Source files: ${SOURCES}")
message(STATUS "Resource files: ${RESOURCE_FILES}")
