set(EXP2SVG_SOURCES
  Main.cpp
  SVGCanvas.cpp
)

set(EXP2SVG_HEADERS
  SVGCanvas.h
)

add_executable(Expression2SVG ${EXP2SVG_SOURCES} ${EXP2SVG_HEADERS})
target_link_libraries(Expression2SVG FuncDrawLib)
