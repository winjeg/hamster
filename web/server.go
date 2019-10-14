package web

import (
	"github.com/kataras/iris"
	"github.com/winjeg/hamster/depositor"
	"github.com/winjeg/hamster/log"
	"github.com/winjeg/hamster/router"
)

func Serve(port string) {
	app := iris.New()
	app.OnAnyErrorCode(func(ctx iris.Context) {
		_, err := ctx.HTML("<h1>不好意思，您访问的页面不存在或者有误</h1>")
		log.LogErr(err)
	})
	router.RegisterStaticPath(app)
	depositor.RegisterDepositor(app)
	log.LogErr(app.Run(iris.Addr(port)))
}
