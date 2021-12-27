package router

import (
	"github.com/kataras/iris"
	"github.com/winjeg/hamster/conf"
	"github.com/winjeg/hamster/log"
	"github.com/winjeg/hamster/store"
)

var (
	config = conf.GetConf()
	lite   = store.NewLiteStore()
)

func serveIndex(c iris.Context) {
	sites := lite.GetAll()
	c.ViewData("sites", sites)
	log.LogErr(c.View("index.html"))
}

func RegisterStaticPath(app *iris.Application) {
	// system path
	app.RegisterView(iris.HTML("./static", ".html"))
	app.StaticWeb("/static", "./static")
	app.Get("/", serveIndex)
	// static path
	route := config.Web.Path
	if route[0] == '.' {
		route = route[1:]
	}
	app.StaticWeb(route, config.Web.Path)
	log.LogErr(app.RefreshRouter())
}
