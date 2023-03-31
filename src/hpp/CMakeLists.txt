# Add all the .hpp files to a variable
file(GLOB HPP_FILES *.hpp)

# Add the header files to the vernam target
target_sources(vernam PRIVATE ${HPP_FILES})