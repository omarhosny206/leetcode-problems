FROM ubuntu:latest

WORKDIR /leetcode

COPY . .

CMD ["/bin/bash"]