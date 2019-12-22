add_library(ScarletRenderer SHARED 
    Source/Scarlet/RenderBuffer.cpp
    Source/Scarlet/Scene.cpp
    Source/Scarlet/Renderer.cpp
    Source/Scarlet/Camera.cpp
    Source/Scarlet/Renderables/Sphere.cpp
    Source/Scarlet/Renderables/Renderable.cpp
    Source/Scarlet/Math/Vector2F.cpp
    Source/Scarlet/Math/Vector3F.cpp
    Source/Scarlet/Math/Vector4F.cpp
    Source/Scarlet/Math/Mat4x4.cpp
    Source/Scarlet/Materials/MaterialLibrary.cpp
    Source/Scarlet/Materials/NormalMaterial.cpp
    Source/Scarlet/Materials/ColorMaterial.cpp
    Source/Scarlet/AccelerationStructures/FlatStructure.cpp
    Source/Scarlet/Objects/Color.cpp
    Source/Scarlet/Objects/Ray.cpp
    Source/Scarlet/Objects/Pixel.cpp
    Source/Scarlet/Utils/Timer.cpp)
target_include_directories(ScarletRenderer PUBLIC Headers/)