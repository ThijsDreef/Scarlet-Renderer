project(Scarlet-Renderer)

# to build shared library on windows
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
set (BUILD_SHARED_LIBS=TRUE)
# to export all files to the same folder
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(Source/Scarlet-Renderer)
add_subdirectory(Source/Scarlet-Client)
add_subdirectory(Source/Scarlet-Server)
add_subdirectory(Source/Scarlet-Standalone)
