local dogs = ngx.shared.dogs
dogs:set("foo","bar")
ngx.say(dogs:get("foo"))
