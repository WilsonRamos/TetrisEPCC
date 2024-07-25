cmake_minimum_required(VERSION 3.10)
project(TetrisGameEPCC)

# Upper defines
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_SOURCE_DIR}>)

# Ajusta las rutas según sea necesario
set(TARGET_EXEC TetrisGameEPCC)
set(SFML_DIR "C:/SFML-2.6.1-vs2022/lib/cmake/SFML")

find_package(SFML 2.6.1 COMPONENTS system window graphics audio REQUIRED)

# Set sources
set(SOURCE_FILES
	src/Main.cpp
	src/GameFacade.cpp
	src/Board.cpp
	src/SoundManager.cpp
	src/ShapeFactory.cpp
	src/UI/UIFrame.cpp
	src/Shapes/ShapeBase.cpp
	src/Shapes/ShapeTypes.cpp
)

# Main Compilation Section
add_executable(${TARGET_EXEC} ${SOURCE_FILES})
target_include_directories(${TARGET_EXEC} PRIVATE "C:/SFML-2.6.1-vs2022/lib/cmake/SFML")
target_link_libraries(${TARGET_EXEC} sfml-system sfml-window sfml-graphics sfml-audio)
