add_library(Prog
  SHARED
  Point.cpp Grid.cpp Player.cpp IA.cpp Game.cpp gamemanager.hpp)

install (TARGETS Prog
        DESTINATION lib)

file(
	GLOB
	headers
	*.hpp
)

install(FILES ${headers}
  DESTINATION include/${CMAKE_PROJECT_NAME})