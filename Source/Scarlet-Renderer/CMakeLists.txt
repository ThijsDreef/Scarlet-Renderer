


add_library(ScarletRenderer SHARED 
    Source/Scarlet/renderer.cpp
    Source/Scarlet/Math/Vector3F.cpp)
target_include_directories(ScarletRenderer PUBLIC Headers/)