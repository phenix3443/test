# -*-coding:utf-8-*-
# author:liushangliang@xunlei.com

import time

import falcon

payload = [{
    "endpoint": "test-endpoint",
    "metric": "test-metric",
    "timestamp": int(time.time()),
    "step": 60,
    "value": 1,
    "counterType": "GAUGE",
    "tags": "role=slave"
}]

if __name__ == "__main__":
    falcon.report(payload)
