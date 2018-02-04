# -*- coding: utf-8 -*-
import scrapy
from tutorial.items import QuoteItem


class QuotesSpider(scrapy.Spider):
    name = 'quotes'
    custom_settings = {
        'ITEM_PIPELINES': {
            'tutorial.pipelines.CSVPipeline': 400
        }
    }
    allowed_domains = ['quotes.toscrape.com']
    start_urls = ['http://quotes.toscrape.com/page/1/']

    def parse(self, response):
        for quote in response.css('div.quote'):
            qi = QuoteItem()
            qi["text"] = quote.css('span.text::text').extract_first()
            qi["author"] = quote.css('small.author::text').extract_first()
            yield qi

        next_page = response.css('li.next a::attr(href)').extract_first()
        if next_page is not None:
            yield response.follow(next_page, callback=self.parse)
