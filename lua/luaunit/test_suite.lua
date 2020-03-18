package.path = package.path .. ";/Users/lsl/.luarocks/share/lua/5.3/?.lua"
package.cpath = package.cpath .. ";/Users/lsl/.luarocks/lib/lua/5.3/?.so"

local lu = require("luaunit")

_G.testSuite = {}

function testSuite:setUp()
    self.name = "my test suite"
    print("set up")
end

function testSuite:tearDown()
    print("tear down")
end

function testSuite:test1()
    print(self.name," test 1")

end

function testSuite:test2()
    print(self.name, " test 2")
    lu.assertEquals(1,1)
end

function testFunction()
    lu.assertEquals(1,2)

end

os.exit(lu.LuaUnit.run())
