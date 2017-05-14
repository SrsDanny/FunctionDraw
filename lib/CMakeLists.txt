set(FUNC_DRAW_LIB_SOURCES
  drawing/Color.cpp
  drawing/Figure.cpp
  drawing/Axes.cpp
  expression/ParseException.cpp
  expression/Parser.cpp
)

set(FUNC_DRAW_LIB_HEADERS
  drawing/Color.h
  drawing/Figure.h
  drawing/GeometricTypes.h
  drawing/ICanvas.h
  drawing/LineBuilder.h
  drawing/NormalizingTransformBuilder.h
  drawing/Range.h
  drawing/Axes.h
  expression/Expression.h
  expression/ExpressionBuilder.h
  expression/ExpressionGrammar.h
  expression/ParseException.h
  expression/Parser.h
)

source_group("Source Files\\drawing" REGULAR_EXPRESSION "drawing/.*\\.cpp")
source_group("Source Files\\expression" REGULAR_EXPRESSION "expression/.*\\.cpp")
source_group("Header Files\\drawing" REGULAR_EXPRESSION "drawing/.*\\.h")
source_group("Header Files\\expression" REGULAR_EXPRESSION "expression/.*\\.h")

add_library(FuncDrawLib ${FUNC_DRAW_LIB_SOURCES} ${FUNC_DRAW_LIB_HEADERS})
target_include_directories(FuncDrawLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
