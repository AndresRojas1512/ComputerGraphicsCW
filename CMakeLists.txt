cmake_minimum_required(VERSION 3.5)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Set the project name and version
project(MyQtProject VERSION 0.1 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the necessary Qt packages
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Gui)

# Enable AUTOMOC, AUTOUIC, and AUTORCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add source files
set(PROJECT_SOURCES
    addlight.cpp

    facade.cpp
    main.cpp
    mainwindow.cpp
    mathelems.cpp

    objectdelete.cpp

    sceneinf.cpp

    specialgraphicsview.cpp
)

# Add header files
set(PROJECT_HEADERS
    addlight.hpp
    config.hpp

    facade.hpp
    mainwindow.h
    mathelems.hpp

    objectdelete.hpp

    sceneinf.hpp

    specialgraphicsview.hpp
)

# Add UI files
set(PROJECT_UIS



    addlight.ui



    mainwindow.ui

    objectdelete.ui

)

# Define target executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MyQtProject
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_UIS}
        drawer.hpp
        drawer.cpp
        vertex.hpp
        vertex.cpp

        facet.hpp
        facet.cpp
        polygonmodel.hpp
        polygonmodel.cpp
        light.hpp
        light.cpp





        microatxmotherboardconfig.hpp
        componentprimitives.hpp
        atxmotherboardconfig.hpp
        miniitxmotherboardconfig.hpp
        cpuconfig.hpp

        configmanager.hpp
        configmanager.cpp
        atxmotherboardconfig.cpp
        basemotherboardconfig.hpp
        microatxmotherboardconfig.cpp
        miniitxmotherboardconfig.cpp
        ramconfig.hpp
        ramconfig.cpp
        componentprimitives.cpp
        gpuconfig.hpp
        cpuconfig.cpp
        gpuconfig.cpp
        colorconfig.hpp
        colorconfig.cpp


    )
else()
    add_executable(MyQtProject
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_UIS}
    )
endif()

# Link libraries
target_link_libraries(MyQtProject PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)

# Deployment/installation rules, analogous to qmake's INSTALLS
if(UNIX AND NOT ANDROID)
    set_target_properties(MyQtProject PROPERTIES
        INSTALL_RPATH_USE_LINK_PATH TRUE
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "/opt/$${TARGET}/bin"
    )
    install(TARGETS MyQtProject RUNTIME DESTINATION "/opt/$${TARGET}/bin")
endif()

# Finalization code for Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MyQtProject)
endif()
