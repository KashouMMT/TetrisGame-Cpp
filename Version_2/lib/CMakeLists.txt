# lib/CMakeLists.txt

add_library(tetrislib STATIC)

target_sources(tetrislib PRIVATE
  src/arraylist.c
)

# This must point to lib/include
target_include_directories(tetrislib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(tetrislib PUBLIC c_std_11)
