cmake_minimum_required(VERSION 2.8)
project( Generate )
project( imgen )

add_subdirectory( Distortions )

add_executable( Generate Generate.cpp )

add_executable( imgen console_tool/ImageGen.cpp )

target_include_directories(Generate PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Distortions"
                          )

target_include_directories(imgen PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Distortions"
                          "${PROJECT_SOURCE_DIR}"
                          )

target_link_libraries( Generate PUBLIC Distortions)
target_link_libraries( imgen PUBLIC Distortions)
