#!/bin/bash

BUILD_IMAGE="my_cpp_build_image"
RUNTIME_IMAGE="my_cpp_runtime_image"

usage() {
    echo "Usage: $0 [--all | --build | --run]"
    echo "  --all     Build and run the final image (all stages)"
    echo "  --build   Build only the build stage"
    echo "  --run     Build and run only the runtime stage"
    exit 1
}

build_stage() {
    echo "Building the build stage..."
    docker build --target build -t $BUILD_IMAGE . && echo "Build stage completed."
}

run_stage() {
    echo "Building the run stage..."
    docker build --target run -t $RUNTIME_IMAGE . && echo "Run stage completed."
    echo "Running the run stage..."
    docker run --rm $RUNTIME_IMAGE
}

test_stage() {
    echo "Building the test stage..."
    docker build --target test -t $RUNTIME_IMAGE . && echo "Test stage completed."
    echo "Running the test stage..."
    docker run --rm $RUNTIME_IMAGE
}

all_stages() {
    echo "Building the final image..."
    docker build -t $RUNTIME_IMAGE . && echo "Final image build completed."
    echo "Running the final image..."
    docker run --rm $RUNTIME_IMAGE
}

if [[ $# -eq 0 ]]; then
    all_stages
    exit 0
fi

case "$1" in
    --all)
        all_stages
        ;;
    --build)
        build_stage
        ;;
    --run)
        run_stage
        ;;
    --test)
        test_stage
        ;;
    *)
        usage
        ;;
esac
