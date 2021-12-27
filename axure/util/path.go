package util

import (
	"os"
	"path/filepath"
	"runtime"
	"strings"

	"github.com/winjeg/hamster/log"
)

func CheckFileIsExist(filename string) bool {
	var exist = true
	if _, err := os.Stat(filename); os.IsNotExist(err) {
		exist = false
	}
	return exist
}

func GetCurrentPath(target string) string {
	var srcDir = ""
	// if the file is in a project
	if _, fileNameWithPath, _, ok := runtime.Caller(1); ok {
		if CheckFileIsExist(fileNameWithPath) {
			idx1 := strings.LastIndex(fileNameWithPath, "/")
			idx2 := strings.LastIndex(fileNameWithPath[:idx1], "/")
			srcDir = fileNameWithPath[:idx2]
		}
	}
	if len(srcDir) == 0 {
		srcDir = getExecutePath()
	}
	if target[0] == '/' {
		return srcDir + target
	} else {
		return srcDir + "/" + target
	}
}

// get config file from where the executables lies
func getExecutePath() string {
	dir, err := filepath.Abs(filepath.Dir(os.Args[0]))
	log.LogErr(err)
	return dir
}
