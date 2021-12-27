package main

import (
	"github.com/winjeg/hamster/conf"
	"github.com/winjeg/hamster/web"
)

var config = conf.GetConf()

func main() {
	web.Serve(config.Serv.Port)
}
