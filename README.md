# hamster
axure 产品原型分享网站

## 产品介绍 (product introduction)
hamster 是一个简单的用于托管静态网站的工具， 目前我主要用来托管`axure`的原型文件  
hamster is a tool for serving static sites, especially for `axure` generated sites 

##  Build（如何构建）

```bash
go build .
```
复制conf.yaml 和打包成的可执行文件到服务器上， 和可以执行文件放到一起  
运行 `./hamster`

## 示例：Demo
![image](https://user-images.githubusercontent.com/7270177/66741200-89c74d80-eea7-11e9-948d-7de55da71129.png)

### 如何使用
![usage](https://user-images.githubusercontent.com/7270177/66741154-63a1ad80-eea7-11e9-8423-23fbea644bcd.gif)

## conf.yaml 配置文件详解
```yaml
web:
  path: ./products  # 放静态文件的目录
  uploadDir: ./uploads # 上传到服务器的目录
server:
  port: :8080 # 监听的端口， listen port
```
