# Add all the .cpp files to a variable
file(GLOB CPP_FILES *.cpp)

# Add the source files to the executable target
target_sources(vernam PRIVATE ${CPP_FILES})