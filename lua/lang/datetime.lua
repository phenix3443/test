local lu = require("luaunit")
local sp = require("serpent")

function today_start()
    local d = os.date("*t")
    d.hour = 0
    d.min = 0
    d.sec = 0
    return d
end

function next_day_start()
    local d = today_start()
    local next_day = os.date("*t", os.time(d) + 86400)
    return next_day
end

function testDateTime()
    local d = next_day_start()
    print(sp.block(d))
end

os.exit(lu.LuaUnit.run())
