set(FUNC_DRAW_LIB_SOURCES
  drawing/Color.cpp
  drawing/Figure.cpp
  expression/ParseException.cpp
  expression/Parser.cpp
)

set(FUNC_DRAW_LIB_HEADERS
  drawing/Color.hpp
  drawing/Figure.hpp
  drawing/GeometricTypes.hpp
  drawing/ICanvas.hpp
  drawing/LineBuilder.hpp
  drawing/PointTransform.hpp
  drawing/Range.hpp
  expression/Expression.hpp
  expression/ExpressionBuilder.hpp
  expression/ExpressionGrammar.hpp
  expression/ParseException.hpp
  expression/Parser.hpp
)

source_group("Source Files\\drawing" REGULAR_EXPRESSION "drawing/.*\\.cpp")
source_group("Source Files\\expression" REGULAR_EXPRESSION "expression/.*\\.cpp")
source_group("Header Files\\drawing" REGULAR_EXPRESSION "drawing/.*\\.hpp")
source_group("Header Files\\expression" REGULAR_EXPRESSION "expression/.*\\.hpp")

add_library(FuncDrawLib ${FUNC_DRAW_LIB_SOURCES} ${FUNC_DRAW_LIB_HEADERS})
target_include_directories(FuncDrawLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
