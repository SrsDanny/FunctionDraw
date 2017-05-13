set(CALC_SOURCES
  Main.cpp
)

add_executable(Calculator ${CALC_SOURCES})
target_link_libraries(Calculator FuncDrawLib)
