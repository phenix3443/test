local Person = require("person")

local Man = Person.new()

Man.gender = "male"

function Man.new()
    return setmetatable({}, {__index = Man})     -- 注意
end

function Man.get_gender(self)
    return self.gender
end

return Man
