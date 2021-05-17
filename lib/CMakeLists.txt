cmake_minimum_required(VERSION 3.12)

set(LIB_PROJECT_NAME Library)

set(LIB_PUBLIC_INCLUDES
	includes/App/Application.hpp
	includes/App/FileManager.hpp
	includes/App/LibraryApp.hpp
	includes/App/MassiveEditor.hpp
	includes/App/Log.hpp
)

set(LIB_PRIVATE_INCLUDES
	src/App/Application.cpp
	src/App/FileManager.cpp
	src/App/LibraryApp.cpp
	src/App/MassiveEditor.cpp
)

add_library(${LIB_PROJECT_NAME} STATIC
	${LIB_PUBLIC_INCLUDES}
	${LIB_PRIVATE_INCLUDES}
)

target_include_directories(${LIB_PROJECT_NAME} PUBLIC includes)
target_compile_features(${LIB_PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(../external/spdlog/ ${CMAKE_CURRENT_BINARY_DIR}/spdlog/)
target_link_libraries(${LIB_PROJECT_NAME} PRIVATE spdlog)
