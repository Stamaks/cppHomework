#set(core_SRCS ADD ALL SOURCE FILES HERE)

#add_library(core ${core_SRCS})
add_executable(xipoint_main
        main.cpp
        xipoint.cpp
        xipoint.h
        )
#target_link_libraries(exe core)