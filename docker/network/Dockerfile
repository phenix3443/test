# 测试 docker 网络链接
From ubuntu
MAINTAINER phenix3443 "phenix3443@gmail.com"
RUN apt update
RUN apt install -y python3 wget
RUN wget https://bootstrap.pypa.io/get-pip.py
RUN python3 get-pip.py
RUN pip3 install redis
ADD main.py /usr/local
ENTRYPOINT ["python3"]
CMD ["/usr/local/main.py"]
