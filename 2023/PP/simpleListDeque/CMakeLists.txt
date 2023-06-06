cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT simpleNodeDeque)
set(EXECUTABLE deque)
set(MAIN_PATH main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/Deque/include)
# link_libraries()

project(${PROJECT}})

# configurar lib

add_executable(
    ${EXECUTABLE} 
    ${MAIN_PATH}
    ${PROJECT_SOURCE_DIR}/Deque/src/Deque.cpp
    ${PROJECT_SOURCE_DIR}/Deque/src/Node.cpp
)

target_include_directories(${EXECUTABLE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Deque/include)
target_include_directories(${EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}/Deque/src)
