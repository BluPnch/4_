# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "4__autogen"
  "CMakeFiles/4__autogen.dir/AutogenUsed.txt"
  "CMakeFiles/4__autogen.dir/ParseCache.txt"
  )
endif()
