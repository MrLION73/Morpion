cmake_minimum_required(VERSION 3.16)
project(Morpion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME} WIN32
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    "${CMAKE_CURRENT_SOURCE_DIR}/ressources/icons/icon.res"
)


# --- Partie installation & packaging ---

include(InstallRequiredSystemLibraries)

set(CPACK_GENERATOR "ZIP;NSIS")
set(CPACK_PACKAGE_NAME "Morpion")
set(CPACK_PACKAGE_VERSION "1.0.0")

set(CPACK_NSIS_DISPLAY_NAME "Jeu Morpion")
set(CPACK_NSIS_PACKAGE_NAME "Morpion")
set(CPACK_NSIS_EXECUTABLES_DIRECTORY ".")
set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)

# ✅ Raccourci sur le bureau
set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "
  CreateShortCut \\\"$DESKTOP\\\\Morpion.lnk\\\" \\\"$INSTDIR\\\\Morpion.exe\\\"
")

set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
  "Delete \\\"$DESKTOP\\\\Morpion.lnk\\\""
)

# ✅ Optionnel : entrée dans le menu Démarrer
set(CPACK_NSIS_MENU_LINKS "Morpion.exe" "Morpion")

include(CPack)

# Installer l’exécutable dans la racine
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)

install(FILES
    ${CMAKE_BINARY_DIR}/deploy/libgcc_s_seh-1.dll
    ${CMAKE_BINARY_DIR}/deploy/Qt6Core.dll
    ${CMAKE_BINARY_DIR}/deploy/libstdc++-6.dll
    ${CMAKE_BINARY_DIR}/deploy/libwinpthread-1.dll
    ${CMAKE_BINARY_DIR}/deploy/Qt6Widgets.dll
    ${CMAKE_BINARY_DIR}/deploy/Qt6Gui.dll
    ${CMAKE_BINARY_DIR}/deploy/libicuuc77.dll
    ${CMAKE_BINARY_DIR}/deploy/libicuin77.dll
    ${CMAKE_BINARY_DIR}/deploy/libb2-1.dll
    ${CMAKE_BINARY_DIR}/deploy/libdouble-conversion.dll
    ${CMAKE_BINARY_DIR}/deploy/libzstd.dll
    ${CMAKE_BINARY_DIR}/deploy/libpcre2-16-0.dll
    ${CMAKE_BINARY_DIR}/deploy/zlib1.dll
    ${CMAKE_BINARY_DIR}/deploy/libmd4c.dll
    ${CMAKE_BINARY_DIR}/deploy/libfreetype-6.dll
    ${CMAKE_BINARY_DIR}/deploy/libharfbuzz-0.dll
    ${CMAKE_BINARY_DIR}/deploy/libpng16-16.dll
    ${CMAKE_BINARY_DIR}/deploy/libicudt77.dll
    ${CMAKE_BINARY_DIR}/deploy/libglib-2.0-0.dll
    ${CMAKE_BINARY_DIR}/deploy/libgraphite2.dll
    ${CMAKE_BINARY_DIR}/deploy/libintl-8.dll
    ${CMAKE_BINARY_DIR}/deploy/libbrotlidec.dll
    ${CMAKE_BINARY_DIR}/deploy/libbz2-1.dll
    ${CMAKE_BINARY_DIR}/deploy/libpcre2-8-0.dll
    ${CMAKE_BINARY_DIR}/deploy/libiconv-2.dll
    ${CMAKE_BINARY_DIR}/deploy/libbrotlicommon.dll
    DESTINATION .
)


# Plugin Qt obligatoire
install(DIRECTORY ${CMAKE_BINARY_DIR}/deploy/platforms DESTINATION .)
