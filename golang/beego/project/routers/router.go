package routers

import (
	"github.com/phenix3443/test/golang/beego/project/controllers"
	"github.com/astaxie/beego"
)

func init() {
    beego.Router("/", &controllers.MainController{})
}
