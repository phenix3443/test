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
    f1 = Foo("foo1")
    f2 = Foo("foo2")

    print(f1.instance_var is f2.instance_var)  # True
    print(f1.cls_var is f2.cls_var)  # True
    print(f1.cls_method is f2.cls_method)  # False
    print(f1.static_methold is f2.static_methold)  # True

    f1.instance_method()
    # Foo.instance_method()  # error

    f1.cls_method()
    Foo.cls_method()

    f1.static_methold()
    Foo.static_methold()
