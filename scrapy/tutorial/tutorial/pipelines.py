# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html


class TutorialPipeline(object):
    def process_item(self, item, spider):
        return item


class QuotesPipeline(object):
    def __init__(self):
        self.csv_file = open("quotes_2.csv", "w")

    def process_item(self, item, spider):
        text = item.get("text")
        author = item.get("author")
        self.csv_file.write("{},{}\n".format(text, author))
        return item

    def close_spider(self, spider):
        self.csv_file.close()
