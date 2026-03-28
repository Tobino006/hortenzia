cmake_minimum_required(VERSION 4.0)
project(AdoHortenziak VERSION 1.0 DESCRIPTION "Ado x Hortenzia collab")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        main.cpp
)

# Homebrew prefix na Apple Silicon
set(HOMEBREW_PREFIX "/opt/homebrew")

# include pre DPP (dpp/dpp.h je v ${HOMEBREW_PREFIX}/include/dpp/dpp.h)
target_include_directories(${PROJECT_NAME} PRIVATE
        ${HOMEBREW_PREFIX}/include
)

# linkovanie libdpp + potrebné systémové knižnice
target_link_libraries (${PROJECT_NAME}
        ${HOMEBREW_PREFIX}/lib/libdpp.dylib
)
