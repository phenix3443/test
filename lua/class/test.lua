local Person = require("person")
local p = Person.new()
p:set_name("wahaha")            -- 注意，对象的函数引用是冒号
p:say()                 --  hello, i am wahaha

local Man = require("man")
local m = Man.new()
m:set_name("kangshifu")
m:say()                         -- hello, i am kangshifu
print(m:get_gender())                  -- i am male
