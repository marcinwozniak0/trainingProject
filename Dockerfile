FROM debian:12 AS build
RUN apt-get update && \
    apt-get install -y build-essential cmake libgtest-dev ninja-build
RUN cd /usr/src/gtest && \
    cmake . && \
    make && \
    mv lib/*.a /usr/lib
WORKDIR /usr/src/app
COPY . .
RUN mkdir build && cd build && cmake -G Ninja .. && ninja


FROM debian:12 AS run
WORKDIR /usr/src/app
COPY --from=build /usr/src/app/build ./build
WORKDIR /usr/src/app/build
CMD ["./training_project"]

FROM debian:12 AS test
RUN apt-get update && apt-get install -y cmake
WORKDIR /usr/src/app
COPY --from=build /usr/src/app/build ./build
WORKDIR /usr/src/app/build
CMD ["ctest", "--output-on-failure"]
