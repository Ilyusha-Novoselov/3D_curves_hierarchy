project(curves_lib)

set(LIB_HDR
    Circle/circle.h
    Curve/curve.h
    Ellipse/ellipse.h
    Helix/helix.h
    Point/point.h
    Directives/directive.h
)

set(LIB_SRC
    Circle/circle.cpp
    Ellipse/ellipse.cpp
    Helix/helix.cpp
)

add_library(curves_lib SHARED ${LIB_SRC} ${LIB_HDR}  )

target_include_directories(curves_lib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/Circle"
    "${CMAKE_CURRENT_SOURCE_DIR}/Curve"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ellipse"
    "${CMAKE_CURRENT_SOURCE_DIR}/Helix"
    "${CMAKE_CURRENT_SOURCE_DIR}/Point"
    "${CMAKE_CURRENT_SOURCE_DIR}/Directives"
)

target_compile_definitions(curves_lib PUBLIC CURVES_DLL_EXPORT)
