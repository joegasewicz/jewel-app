cmake_minimum_required(VERSION 3.23)
project(jewel_app)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(jewel_app
        main.cpp
        elements/BaseElement.cpp elements/BaseElement.h
        elements/Shank.cpp elements/Shank.h
        elements/Types.h
        gui/Gui.cpp gui/Gui.h
        gui/MainFrame.cpp gui/MainFrame.h gui/panels/SideBar.cpp gui/panels/SideBar.h)

target_link_libraries(jewel_app ${wxWidgets_LIBRARIES})
