# -*- coding:utf-8-*-
class Foo:
    cls_var = "cls_var"

    def __init__(self, name):
        print("construct Foo instance: " + name)
        self.instance_var = "instance var"

    @classmethod
    def cls_method(cls):
        print("in class method", type(cls))

    @staticmethod
    def static_methold():
        print("in static method")

    def instance_method(self):
        print("in instance method", type(self))


if __name__ == "__main__":
    for i in range(3, 10):
        print(i)
