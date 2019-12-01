-- -*- coding:utf-8 -*-
package.path = package.path .. ';/usr/local/share/lua/5.1/?.lua'
package.cpath = package.cpath .. ';/usr/local/share/lua/5.1/?.so'



local string = require("string")

t = {a="a",b="b"}


function display ()
    print(os.time())
    print(t.a)
end





function main ()
	display()
end
