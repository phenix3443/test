# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html


class TutorialPipeline(object):
    def process_item(self, item, spider):
        return item


class CSVPipeline(object):
    def open_spider(self, spider):
        self.csv_file = open("quotes.csv", "w")

    def close_spider(self, spider):
        self.csv_file.close()

    def process_item(self, item, spider):
        if spider.name == "quotes":
            text = item.get("text")
            author = item.get("author")
            self.csv_file.write("{},{}\n".format(text, author))
            return item


class JsonWritePipeline():
    def open_spider(self):
        pass

    def process_item(self, item, spider):
        pass

    def close_spider(self):
        pass
