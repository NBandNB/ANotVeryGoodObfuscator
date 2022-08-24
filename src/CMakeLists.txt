set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(IncludeFiles ${CMAKE_SOURCE_DIR}/include/FileHandler.h ${CMAKE_SOURCE_DIR}/include/Graphical.h ${CMAKE_SOURCE_DIR}/include/Main.h ${CMAKE_SOURCE_DIR}/include/Obfuscate.h)

set(PROJECT_SOURCES
        fileChooser.cpp
        Main.cpp
        FileHandler.cpp
        MainWindow.cpp
        Obfuscate.cpp
        ReverseMessage.cpp
        ROT.cpp
        ToFile.cpp
        Binary.cpp
        ${IncludeFiles}
        )
        #MainWindow.ui
        #${TS_FILES})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ANotVeryGoodObfuscator
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET MakerBorrowDesktop APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(ANotVeryGoodObfuscator SHARED
                ${PROJECT_SOURCES}
                )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ANotVeryGoodObfuscator
                ${PROJECT_SOURCES}
                )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(ANotVeryGoodObfuscator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(ANotVeryGoodObfuscator PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

install(TARGETS ANotVeryGoodObfuscator
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MakerBorrowDesktop)
endif()