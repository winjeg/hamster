package conf

import (
	config "github.com/winjeg/go-commons/conf"
	"sync"
)

type WebConfig struct {
	Path      string `yaml:"path"`
	UploadDir string `yaml:"uploadDir"`
}

type Server struct {
	Port string `yaml:"port"`
}

type Config struct {
	Web  WebConfig `yaml:"web"`
	Serv Server    `yaml:"server"`
}

var (
	once sync.Once
	conf *Config
)

func GetConf() *Config {
	if conf != nil {
		return conf
	} else {
		once.Do(getConf)
	}
	return conf
}

const configFile = "conf.yaml"

func getConf() {
	conf = new(Config)
	err := config.Yaml2Object(configFile, &conf)
	if err != nil {
		panic(err)
	}
}
