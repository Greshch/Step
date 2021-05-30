cmake_minimum_required(VERSION 3.10)
project(step)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD 20)

#https://kinoprofi.vip/19728-taynaya-zhizn-2020.html


include_directories(include)
#set(C_MAKE_CPP_COMPILER clang++)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(step  src/main.cpp)

#target_link_libraries(${PROJECT_NAME} -lglut -lGLU -lGL)
#target_link_libraries(${PROJECT_NAME} -lGL -lglut -lGLEW)
#target_link_libraries(${PROJECT_NAME} #[[-lglfw3]] -lGL -lX11 -lpthread -lXrandr -lXi -ldl)
#target_link_libraries(${PROJECT_NAME} GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor assimp)
#target_link_libraries(${PROJECT_NAME}  -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -ldl -lXinerama -lXcursor)
