package log

import "github.com/winjeg/go-commons/log"

var logger = log.GetLogger(nil)

func LogErr(err error) {
	if err != nil {
		logger.Error(err)
	}
}
