cmake_minimum_required (VERSION 3.16.1)
project (LabFivePartOne VERSION 1.2.3.4 )
add_executable(LabFive LabFivePartOne.c)
install(TARGETS LabFive DESTINATION bin)
install(FILES LabFivePartOne.c DESTINATION src) 

