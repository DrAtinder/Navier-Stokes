# Minimum CMake version requirement
cmake_minimum_required(VERSION 3.15)

# Project name and version
project(NSsolver VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable verbose makefile output (optional)
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Specify build type (optional, can also be set via command line)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add subdirectories
add_subdirectory(Mesh)
#add_subdirectory(Solver)
#add_subdirectory(Discretize)
#add_subdirectory(Boundary)
#add_subdirectory(Utils)
#add_subdirectory(Tests)

# Specify the executable target
add_executable(NSsolver main.cpp)

# Link the libraries created in the subdirectories
target_link_libraries(NSsolver PRIVATE Mesh) # Solver Discretize Boundary Utils)

# Include directories from submodules
target_include_directories(NSsolver PRIVATE
    ${PROJECT_SOURCE_DIR}/Mesh/include
    #${PROJECT_SOURCE_DIR}/Solver
    #${PROJECT_SOURCE_DIR}/Discretize
    #${PROJECT_SOURCE_DIR}/Boundary
    #${PROJECT_SOURCE_DIR}/Utils
)

# Optionally find and link external libraries
# Example for finding and linking MPI
# find_package(MPI REQUIRED)
# target_link_libraries(NavierStokesSolver PRIVATE MPI::MPI_CXX)

# Example for finding and linking CUDA
# find_package(CUDA REQUIRED)
# target_link_libraries(NavierStokesSolver PRIVATE CUDA::cudart)

# Enable testing (optional)
enable_testing()

