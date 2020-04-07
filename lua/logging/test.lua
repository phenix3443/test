package.path = package.path .. ";/Users/lsl/.luarocks/share/lua/5.3/?.lua;/home/lsl/.luarocks/share/lua/5.1/?.lua"
package.cpath = package.cpath .. ";/Users/lsl/.luarocks/lib/lua/5.3/?.so"

local lu = require("luaunit")
require("logging.console")

_G.testSuite = {}

function testSuite:setUp()
    self.logger =
        logging.console {
        timestampPattern = "%Y-%m-%d"
    }
end

function testSuite:tearDown()
    print("tear down")
end

function testSuite:test1()
    self.logger:info("logging.console test")
    self.logger:debug("debugging...")
    self.logger:error("error!")
end

function testFunction()
    lu.assertEquals(1, 2)
end

os.exit(lu.LuaUnit.run())
