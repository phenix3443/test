# -*-coding:utf-8-*-
# author:liushangliang@xunlei.com
import json

import requests


def report(payload):

    r = requests.post(
        "http://127.0.0.1:1988/v1/push", data=json.dumps(payload))
    print(r.text)


if __name__ == "__main__":
    pass
