cmake_minimum_required(VERSION 4.2)

project(secure_tourism_db_system LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Sql Widgets)

set(OPENSSL_ROOT_DIR "C:/msys64/mingw64")
find_package(OpenSSL REQUIRED)

add_executable(secure_tourism_db_system
        src/main.cpp
        src/Database.cpp
        include/Database.h
        src/SearchManager.cpp
        include/SearchManager.h
        src/EncryptionManager.cpp
        include/EncryptionManager.h
        include/Record.h
        src/Controller.cpp
        include/Controller.h
        include/mainwindow.h
        src/mainwindow.cpp
        forms/MainWindow.ui
)

target_include_directories(
        secure_tourism_db_system
        PRIVATE
        include
        ${OPENSSL_INCLUDE_DIR}
)

target_link_libraries(
        secure_tourism_db_system
        PRIVATE
        Qt6::Core
        Qt6::Sql
        Qt6::Widgets
        OpenSSL::Crypto
)

if(WIN32)
    find_program(WINDEPLOYQT_EXECUTABLE
            NAMES windeployqt.exe windeployqt
            HINTS
            "${Qt6_DIR}/../../../bin"
            "${Qt6_DIR}/../bin"
    )

    if(NOT WINDEPLOYQT_EXECUTABLE)
        message(FATAL_ERROR "windeployqt.exe not found")
    endif()

    add_custom_command(TARGET secure_tourism_db_system POST_BUILD
            COMMAND "${WINDEPLOYQT_EXECUTABLE}" --compiler-runtime "$<TARGET_FILE:secure_tourism_db_system>"
            COMMENT "Deploying Qt DLLs and compiler runtime"
    )

    add_custom_command(TARGET secure_tourism_db_system POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "C:/msys64/mingw64/bin/libcrypto-3-x64.dll"
            "$<TARGET_FILE_DIR:secure_tourism_db_system>"
            COMMENT "Copying OpenSSL runtime"
    )
endif()