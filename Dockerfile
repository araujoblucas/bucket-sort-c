FROM ubuntu:latest

RUN apt update
RUN apt install -y --no-install-recommends apt-utils
RUN apt -y install curl
RUN apt install libgomp1
RUN apt list --upgradable
RUN apt install build-essential -y

CMD ["bash"]

