# Use an official GCC runtime as a parent image
FROM gcc:latest

# Install CMake, git and update
RUN apt-get update && \
    apt-get install -y cmake git libgtest-dev qtbase5-dev qt5-qmake qtbase5-dev-tools && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Build and install googletest
RUN cd /usr/src/gtest && \
    cmake . && \
    make && \
    cp *.a /usr/lib