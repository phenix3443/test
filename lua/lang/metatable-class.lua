-- -*-coding:utf-8 -*-
--
local Animal = {}
Animal.__index = Animal         -- 类只是一个带有指向自身的 __index 键的表

function Animal:set_name(name)
    self.name = name
end

-- 封装
function Animal.new()           -- 创建一个对象包括创建一个表，并将其 metatable 设置为该类
    return setmetatable({}, Animal)
end

print("封装测试")
local a = Animal.new()
a:set_name("animal")
print(a.name)                   -- animal

-- 继承
local Dog = Animal.new()
Dog.__index = Dog     --  类只是一个带有指向自身的 __index 键的表
function Dog.new()              -- 创建一个对象包括创建一个表，并将其 metatable 设置为该类
    return setmetatable({}, Dog)
end

function Dog.speak()
    return "bark"
end

print("继承测试")
local d = Dog.new()
d:set_name("dog")
print(d.speak())                -- bark

-- 多态
local Cat = Animal.new()
Cat.__index = Cat     -- -- 类只是一个带有指向自身的 __index 键的表
function Cat.new()              -- 创建一个对象包括创建一个表，并将其 metatable 设置为该类
    return setmetatable({}, Cat)
end

function Cat.speak()
    return "meow"
end

function Animal:welcome()
    return self.name ..":" .. self.speak()
end

print("多态测试")
local c = Cat.new()
c:set_name("cat")
print(d:welcome())              -- dog:bark
print(c:welcome())              -- cat:meow

print("tostring test")
function Animal:__tostring()
    return self.name ..":" .. self.speak()
end

Dog.__tostring = Animal.__tostring
Cat.__tostring = Animal.__tostring

print(d,c)                      -- dog:bark	cat:meow
