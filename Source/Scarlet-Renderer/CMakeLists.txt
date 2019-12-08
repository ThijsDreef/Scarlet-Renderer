add_library(ScarletRenderer SHARED 
    Source/Scarlet/RenderBuffer.cpp
    Source/Scarlet/Math/Vector3F.cpp
    Source/Scarlet/Math/Mat4x4.cpp
    Source/Scarlet/Materials/MaterialLibrary.cpp
    Source/Scarlet/Objects/Color.cpp
    Source/Scarlet/Objects/Ray.cpp
    Source/Scarlet/Objects/Pixel.cpp)
target_include_directories(ScarletRenderer PUBLIC Headers/)