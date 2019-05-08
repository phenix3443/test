-- 在这里修改luarocks安装lua lib 之后的目录
package.path = "/usr/local/lib/lua/5.1/?.lua;"..package.path
package.cpath = "/usr/local/lib/lua/5.1/?.so;"..package.cpath

local sp = require("serpent")
local IPDB = require("ipdb")

local function test(ip)
    local ipdb = IPDB("GeoLite2-Country.mmdb", "GeoLite2-City.mmdb", "GeoLite2-ASN.mmdb")


    local coun_info = ipdb:get_coun_info(ip)
    local city_info = ipdb:get_city_info(ip)
    local isp_info = ipdb:get_isp_info(ip)

    print(sp.block(coun_info))
    -- print(sp.block(city_info))
    -- print(sp.block(isp_info))

    -- print(
    --     city_info.country.iso_code,
    --     city_info.country.names["en"],
    --     city_info.country.names["zh-CN"],

    --     (city_info.city and city_info.city.names["zh-CN"]) or "未知",

    --     isp_info.autonomous_system_number,
    --     isp_info.autonomous_system_organization
    -- )
end

-- local ip = "213.215.63.11" -- 欧洲 法国 波尔多
-- local ip = "2607:f8b0:4004:801::100e" --google
local ip = "13.232.158.182" -- 印度 孟买
-- local ip = "114.119.117.18" -- 中国 广州 联通
test(ip)
