cmake_minimum_required(VERSION 3.23) # Versão mínima do CMake

project(CIRCULARLIST) # Nome do projeto
set(CMAKE_CXX_STANDARD 14) # Versão do C++ (opcional)

# Configuração do executável
add_executable(main main.cpp Node.h CircularList.h Roulette.h Node.cpp CircularList.cpp Roulette.cpp)