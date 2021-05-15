# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
include_directories(${CMAKE_SOURCE_DIR}/src)
message(${CMAKE_SOURCE_DIR}/src)
file(GLOB SRCPP ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library (Graph ${SRCPP})

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (Graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
