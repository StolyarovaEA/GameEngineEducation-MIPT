# Install script for directory: D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-info.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-play.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-convert.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-cmp.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-metadata-set.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-metadata-get.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-interleave.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-deinterleave.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-concat.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile-salvage.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/include/sndfile.h"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/include/sndfile.hh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SndFileTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SndFileTargets.cmake"
         "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/CMakeFiles/Export/cmake/SndFileTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SndFileTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SndFileTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/CMakeFiles/Export/cmake/SndFileTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/CMakeFiles/Export/cmake/SndFileTargets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE RENAME "SndFileConfig.cmake" FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/SndFileConfig2.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/SndFileConfigVersion.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE FILES
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-info.1"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-play.1"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-convert.1"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-cmp.1"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-metadata-get.1"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-concat.1"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-interleave.1"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-salvage.1"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE RENAME "sndfile-metadata-set.1" FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-metadata-get.1")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE RENAME "sndfile-deinterleave.1" FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/man/sndfile-interleave.1")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/libsndfile" TYPE FILE FILES
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/index.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/libsndfile.jpg"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/libsndfile.css"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/print.css"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/api.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/command.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/bugs.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/formats.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/sndfile_info.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/new_file_type_howto.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/win32.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/FAQ.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/lists.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/embedded_files.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/octave.md"
    "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/docs/tutorial.md"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/sndfile.pc")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/code/GameEngineEducation-MIPT/SDKs/libsndfile-master/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
