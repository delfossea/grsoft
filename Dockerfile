FROM ubuntu:latest

RUN apt-get update && apt-get install -y gcc

WORKDIR /opt

COPY soft /opt

CMD [ "/opt/soft" ]
