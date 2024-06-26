# Craig Scratchley, June 2023
# gdb initialization file for ENSC 251

# stop execution of program being debugged when an exception is thrown
catch throw

#set debug infrun 1
set logging overwrite on
set logging on

# allow viewing of source code for (some) libraries
#set debuginfod enabled on

# don't step inside C++ standard library functions and operators 
skip -gfi /usr/include/c++/*/*/*
skip -gfi /usr/include/c++/*/*
skip -gfi /usr/include/c++/*

#set history expansion

# allow breakpoint at functions like halt before they are loaded.
#set breakpoint pending on
#break halt
