FROM gcc:latest as build

RUN mkdir /usr/bin/gfortran 

COPY . /srcHttp

WORKDIR ./srcHttp

RUN apt-get update && \
    apt-get install libboost-all-dev libboost-program-options-dev \
    libpaho-mqttpp-dev libpaho-mqtt-dev\
    cmake -y

RUN cmake . && \
    make install


EXPOSE 8884 8080

ENTRYPOINT untitled

