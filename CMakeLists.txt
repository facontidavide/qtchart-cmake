cmake_minimum_required(VERSION 2.8.8)

project(qtchart_cmake)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

add_definitions( -std=c++11
    -DQT_NO_OPENGL -DQT_STATIC
    ${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -fPIC")

include_directories(${Qt5Widgets_INCLUDE_DIRS})

SET( SOURCES
    src/charts/chartdataset.cpp
    src/charts/chartpresenter.cpp
    src/charts/chartthememanager.cpp
    src/charts/qchart.cpp
    src/charts/qchartview.cpp
    src/charts/qabstractseries.cpp
    src/charts/chartbackground.cpp
    src/charts/chartelement.cpp
    src/charts/chartitem.cpp
    src/charts/scroller.cpp
    src/charts/charttitle.cpp
    src/charts/qpolarchart.cpp
    )

set ( PRIVATE_HEADERS
    src/charts/chartdataset_p.h
    src/charts/chartitem_p.h
    src/charts/chartpresenter_p.h
    src/charts/chartthememanager_p.h
    src/charts/chartbackground_p.h
    src/charts/chartelement_p.h
    src/charts/chartconfig_p.h
    src/charts/qchart_p.h
    src/charts/qchartview_p.h
    src/charts/scroller_p.h
    src/charts/qabstractseries_p.h
    src/charts/charttitle_p.h
    src/charts/charthelpers_p.h
    src/charts/qchartglobal_p.h
    src/charts/glwidget_p.h
)

SET( PUBLIC_HEADERS
    src/charts/qchart.h
    src/charts/qchartglobal.h
    src/charts/qabstractseries.h
    src/charts/qchartview.h
    src/charts/chartsnamespace.h
    src/charts/qpolarchart.h
    )

set(QTCHARTS_BUILD_DIR ${PROJECT_BINARY_DIR})


set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)

file(GLOB INCLUDE_QFILES "include/QtCharts*")

message(STATUS "QTCHARTS_BUILD_DIR = ${QTCHARTS_BUILD_DIR} ")

file(COPY ${PRIVATE_HEADERS}  DESTINATION  ${QTCHARTS_BUILD_DIR}/QtCharts/private )
file(COPY ${PUBLIC_HEADERS}   DESTINATION  ${QTCHARTS_BUILD_DIR}/QtCharts )
file(COPY ${INCLUDE_QFILES}   DESTINATION  ${QTCHARTS_BUILD_DIR}/ )

add_subdirectory( src/charts/animations)
add_subdirectory( src/charts/areachart)
add_subdirectory( src/charts/axis)
add_subdirectory( src/charts/barchart)
add_subdirectory( src/charts/boxplotchart)
add_subdirectory( src/charts/candlestickchart)
add_subdirectory( src/charts/domain)
add_subdirectory( src/charts/legend)
add_subdirectory( src/charts/layout)
add_subdirectory( src/charts/linechart)
add_subdirectory( src/charts/piechart)
add_subdirectory( src/charts/scatterchart)
add_subdirectory( src/charts/splinechart)
add_subdirectory( src/charts/themes)
add_subdirectory( src/charts/xychart)


add_library(qtchart STATIC
    ${PUBLIC_HEADERS}
    ${PRIVATE_HEADERS}
    ${SOURCES}
    $<TARGET_OBJECTS:animations>
    $<TARGET_OBJECTS:areachart>
    $<TARGET_OBJECTS:axis>
    $<TARGET_OBJECTS:barchart>
    $<TARGET_OBJECTS:boxplotchart>
    $<TARGET_OBJECTS:candlestickchart>
    $<TARGET_OBJECTS:domain>
    $<TARGET_OBJECTS:layout>
    $<TARGET_OBJECTS:legend>
    $<TARGET_OBJECTS:linechart>
    $<TARGET_OBJECTS:piechart>
    $<TARGET_OBJECTS:scatterchart>
    $<TARGET_OBJECTS:splinechart>
#    $<TARGET_OBJECTS:themes>
    $<TARGET_OBJECTS:xychart>
    )

target_include_directories( qtchart BEFORE PRIVATE
    src
    ${QTCHARTS_BUILD_DIR}/QtCharts
    ${QTCHARTS_BUILD_DIR}/
)


