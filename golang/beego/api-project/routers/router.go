package routers

import (
	"github.com/astaxie/beego"
	"github.com/phenix3443/test/golang/beego/api-project/controllers"
)

func init() {
	beego.Router("/", &controllers.MainController{})
}
