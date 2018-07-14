local Person = {
    name = "default"
}

function Person.new()
    return setmetatable({}, {__index = Person})     -- 注意
end

function Person.set_name(self, name)
    self.name = name
end

function Person.say(self)
    local msg = string.format("hello, i am %s", self.name)
    print(msg)
end

return Person
