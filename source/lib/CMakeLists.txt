set(FUNC_DRAW_LIB_SOURCES
  drawing/Color.cpp
  drawing/Figure.cpp
  expression/ParseException.cpp
  expression/Parser.cpp
)

add_library(FuncDrawLib ${FUNC_DRAW_LIB_SOURCES})
target_include_directories(FuncDrawLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
