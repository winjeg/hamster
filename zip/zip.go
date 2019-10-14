package zip

import (
	"archive/zip"
	"github.com/winjeg/hamster/log"
	"github.com/winjeg/hamster/util"
	"io/ioutil"
	"os"
	"strings"
)

func Unzip(fileName, dest string) error {
	// Open a zip archive for reading.
	target := util.GetCurrentPath(dest)
	r, err := zip.OpenReader(fileName)
	if err != nil {
		log.LogErr(err)
		return err
	}
	defer r.Close()

	// Iterate through the files in the archive,
	// printing some of their contents.
	for _, f := range r.File {
		rc, err := f.Open()
		if err != nil {
			log.LogErr(err)
			return err
		}
		data, fErr := ioutil.ReadAll(rc)
		ignoreErr(fErr)
		name := target + "/" + f.Name
		writeErr := writeFile(name, data)
		log.LogErr(rc.Close())
		log.LogErr(writeErr)
	}
	return nil
}

func ignoreErr(err error) {
}

func writeFile(filename string, data []byte) error {
	if !util.CheckFileIsExist(filename) {
		idx := strings.LastIndex(filename, "/")
		path := filename[:idx]
		log.LogErr(os.MkdirAll(path, 0755))
		f, err := os.Create(filename)
		ignoreErr(err)
		log.LogErr(f.Close())
		if err != nil {
			return err
		}
	}
	ioErr := ioutil.WriteFile(filename, data, 0666)
	ignoreErr(ioErr)
	return nil
}
