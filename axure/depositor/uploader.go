package depositor

import (
	"github.com/winjeg/hamster/store"
	"github.com/winjeg/hamster/zip"
	"strings"
)

var liteStore = store.NewLiteStore()

func uploadAndRegister(fileName, author string) error {
	// 1. unzio to target dir
	err := zip.Unzip(fileName, config.Web.Path)
	if err != nil {
		return err
	}
	// 3. store it to db
	route := config.Web.Path
	if route[0] == '.' {
		route = route[1:]
	}
	route += getPath(fileName) + "/start.html"
	err = liteStore.Store(author, route)
	if err != nil {
		return err
	}
	return nil
}

func getPath(fileName string) string {
	dotIndex := strings.LastIndex(fileName, ".")
	slashIndex := strings.LastIndex(fileName, "/")
	if dotIndex == -1 || slashIndex == -1 {
		return fileName
	}
	return fileName[slashIndex:dotIndex]
}
