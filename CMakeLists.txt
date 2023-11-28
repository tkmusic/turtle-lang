cmake_minimum_required(VERSION 3.10)
project(turtle)

set(CMAKE_C_STANDARD 11)

# Add the source files
set(SOURCE_FILES
    lexer.c
    parser.c
    interpreter.c
    main.c
)

# Add executable target
add_executable(turtle ${SOURCE_FILES})

# Set the output directory for the executable
set_target_properties(turtle PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Install the executable to a system variable (C:/Program Files/turtle)
install(TARGETS turtle
    DESTINATION "C:/Program Files/turtle"
)

# Include headers directory
target_include_directories(turtle PRIVATE ${CMAKE_SOURCE_DIR})