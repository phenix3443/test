# -*- coding: utf-8 -*-
# author:liushangliang@xunlei.com
import scrapy
from datetime import datetime, timedelta
from res_spider.items import FilmInfoItem


class YgdyNewestSpider(scrapy.Spider):
    # 爬取阳光电影最近更新的资源
    name = 'ygdy_newest'
    start_urls = ['http://www.ygdy8.net/html/gndy/dyzz/index.html']

    continue_next_page = True  # 是否继续分析下一页

    def parse(self, response):
        # 查找最新更新的电影
        for film in response.xpath('//*[@class="co_content8"]/ul/td/table'):
            detail_link = film.xpath('./tr[2]/td[2]/b/a/@href').extract_first()
            update_time = film.xpath('./tr[3]/td[2]/font/text()').re(
                "\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}")[0]

            # 只分析最近两个小时新增的资源
            diff = datetime.now() - datetime.strptime(update_time,
                                                      "%Y-%m-%d %H:%M:%S")
            if diff < timedelta(days=3):
                yield response.follow(detail_link, callback=self.parse_detail)
            else:
                self.continue_next_page = False

        # 爬取下一页
        next_page = response.xpath(
            '//*[@class="co_content8"]/div/td/a[last()-1]/@href'
        ).extract_first()
        if self.continue_next_page:
            yield response.follow(next_page, callback=self.parse)

    def parse_detail(self, response):
        download_link = response.xpath(
            '//td[@style="WORD-WRAP: break-word"]/a/@href').extract_first()
        fi = FilmInfoItem()
        fi["name"] = "hello"
        fi["url"] = download_link
        yield fi
