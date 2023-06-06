cmake_minimum_required(VERSION 3.3) # Versão mínima do CMake

project(equals) # Nome do projeto
set(CMAKE_CXX_STANDARD 14) # Versão do C++ (opcional)

# Configuração do executável
add_executable(main main.cpp Equals.cpp Equals.h)