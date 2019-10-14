package web

import (
	"github.com/kataras/iris"
	"github.com/winjeg/hamster/depositor"
	"github.com/winjeg/hamster/log"
	logg2 "github.com/winjeg/go-commons/log"
	"github.com/winjeg/hamster/router"
)

var logger = logg2.GetLogger(nil)

func Serve(port string) {
	app := iris.New()
	app.Use(func(ctx iris.Context) {
		logger.WithField("Method", ctx.Method()).WithField("Path", ctx.Path()).Info()
		ctx.Next()
	})
	app.OnAnyErrorCode(func(ctx iris.Context) {
		_, err := ctx.HTML("<h1>不好意思，您访问的页面不存在或者有误</h1>")
		log.LogErr(err)
	})
	router.RegisterStaticPath(app)
	depositor.RegisterDepositor(app)
	log.LogErr(app.Run(iris.Addr(port)))
}
