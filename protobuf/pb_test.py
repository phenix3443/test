# -*- coding:utf-8; -*-
from . import addressbook_pb2


def write_data():
    address_book = addressbook_pb2.AddressBook()
    person = address_book.people.add()
    person.name = "john Doe"
    person.id = 123
    person.email = "jdoe@example.com"

    with open("data.txt", "wb") as f:
        f.write(address_book.SerializeToString())


def read_data():
    address_book = addressbook_pb2.AddressBook()
    with open("data.txt", "rb") as f:
        address_book.ParseFromString(f.read())

    print(address_book.people[0].name)


if __name__ == "__main__":
    write_data()
    read_data()
