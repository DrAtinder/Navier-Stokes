# Specify the include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Glob the source and header files
file(GLOB SOURCES *.cpp)
file(GLOB HDRS include/*.h)

# Create the library from the source files
add_library(Mesh SHARED ${SOURCES} ${HDRS})

# Optionally specify where to place the compiled library
set_target_properties(Mesh PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

