local lu = require("luaunit")
local Date = require("pl.date")

function testDateTime()
    local d = Date(os.date("*t"))
    print(sp.block(d))
end

os.exit(lu.LuaUnit.run())
