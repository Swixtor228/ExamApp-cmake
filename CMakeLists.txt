cmake_minimum_required(VERSION 3.12)

project(ExamApplication)

set(PROJECT_NAME ExamApp)

add_subdirectory(lib)
add_subdirectory(app)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Application)