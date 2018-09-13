set(core_SRCS main.cpp
        xipoint.cpp
        xipoint.h)

add_library(core ${core_SRCS})
#add_executable(xipoint_main
#        main.cpp
#        xipoint.cpp
#        xipoint.h
#        )
#target_link_libraries(exe core)