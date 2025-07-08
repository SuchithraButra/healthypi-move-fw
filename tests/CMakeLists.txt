cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(smf_display_tests)

# Add test source files
target_sources(app PRIVATE 
    src/main.c
    # Core test is included via main.c to avoid duplicate definitions
)

# Add mock include directories  
target_include_directories(app PRIVATE 
    src
    src/mocks
    ../app/src
    ../app/src/sm
)

# Add compile definitions for testing
target_compile_definitions(app PRIVATE
    CONFIG_ZTEST=1
)
