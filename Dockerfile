FROM ubuntu:22.04
LABEL maintainer="Bira Lavor <umeneses@42sp.org.br>"
LABEL description="Dockerfile for 42SP's CPP projects"
LABEL version="1.0"

# Install required packages
RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    cmake \
    git \
    python3 \
    python3-pip \
    python3-venv \
    libreadline-dev \
    libgtest-dev \
    valgrind

# Clone GoogleTest
RUN git clone https://github.com/google/googletest.git /googletest

# Build and install GoogleTest
RUN cd /googletest && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install

# Create a non-root user
ARG USER_ID=1000
ARG GROUP_ID=1000
RUN groupadd -g ${GROUP_ID} developer && \
    useradd -u ${USER_ID} -g ${GROUP_ID} -m -s /bin/bash developer

# Create and set permissions for workspace
RUN mkdir -p /workspace && \
    chown developer:developer /workspace
# Switch to non-root user
USER developer

# Set working directory for projects
WORKDIR /workspace

# Default command
CMD ["/bin/bash"]