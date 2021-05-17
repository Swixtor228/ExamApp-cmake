cmake_minimum_required(VERSION 3.12)

set(APP_PROJECT_NAME Application)

add_executable(${APP_PROJECT_NAME}
	src/main.cpp
)

#
target_link_libraries(${APP_PROJECT_NAME} Library)
target_compile_features(${APP_PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${APP_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)