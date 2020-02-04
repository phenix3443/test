# -*- coding:utf-8; -*-

from ruamel.yaml import YAML


if __name__ == "__main__":
    with open("test.yml", "r") as f:
        # doc = f.readlines()
        yaml = YAML()
        data = yaml.load(f)
        print(data)
        print(data["dict"])
        print(data["child_dict"]["key1"])
        # print(data["kv_split_dict"][["key1", "key2"]])
        print(data["inline_array"][0])
        print(data["array"])
        print(data["companies"][0]["name"])
        print(type(data["base_type"]["boolean"]))
        print(type(data["base_type"]["string"]))
