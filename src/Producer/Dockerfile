FROM gcc:latest as build

RUN mkdir /usr/bin/gfortran 

COPY . /srcProducer

WORKDIR ./srcProducer

RUN apt-get update && \
    apt-get install libboost-all-dev libboost-program-options-dev \
    libpaho-mqttpp-dev libpaho-mqtt-dev libpq5\
    postgresql \
    cmake -y

RUN cmake . && \
    make install
    
COPY ./config/pg_hba.conf /etc/postgresql/15/main/pg_hba.conf

ENTRYPOINT /initDatabase

