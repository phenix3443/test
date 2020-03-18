package.path = package.path .. ";/Users/lsl/.luarocks/share/lua/5.3/?.lua"
package.cpath = package.cpath .. ";/Users/lsl/.luarocks/lib/lua/5.3/?.so"

local lu = require("luaunit")
local ffi = require("ffi")

function testFFI()
end

os.exit(lu.LuaUnit.run())
