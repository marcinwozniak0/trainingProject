FROM debian:12 as build
RUN apt-get update && \
    apt-get install -y build-essential
WORKDIR /usr/src/app
COPY . .
RUN clang --version
RUN g++ -std=c++23 -o my_program main.cpp


FROM debian:12 AS run
WORKDIR /usr/src/app
COPY --from=build /usr/src/app/my_program .
CMD ["./my_program"]

