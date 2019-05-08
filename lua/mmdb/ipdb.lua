-- -*- coding:utf-8 -*-
--- ipdb
-- @module ip 信息解析.
-- @author:phenix3443@gmail.com

local mmdb = require("mmdb")
local class = require("pl.class")

local M = class()

--- 初始化函数
-- 初始化相关参数，该函数不需要手动调用。
-- @param city city 数据库
-- @param asn asn 数据库
function M:_init(country_db, city_db, asn_db)
    -- Download from http://dev.maxmind.com/geoip/geoip2/geolite2/
    self.country_db = assert(mmdb.read(country_db))
    self.city_db = assert(mmdb.read(city_db))
    self.isp_db = assert(mmdb.read(asn_db))
end

--- 获取IP相关的城市信息
-- @param ip
function M:get_coun_info(ip)
    local info = self.country_db:search_ipv4(ip)
    return info
end

--- 获取IP相关的城市信息
-- @param ip
function M:get_city_info(ip)
    local info = self.city_db:search_ipv4(ip)
    return info
end

--- 获取IP相关的 isp 信息
-- @param ip
function M:get_isp_info(ip)
    local info = self.isp_db:search_ipv4(ip)
    return info
end

return M
