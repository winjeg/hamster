# rrcb -> run remote command in bash
**Execute remote commands in a bash shell, for mutil-servers**
- Operating different server instance with one command, and every thing runs just smoothly
- Easy to write ini file for beginners
- Automating everything in one file
- No need to write code, or confusing commands
- Works fine with `CI` systems such as Jenkins

可以用它方便的实现自动部署
不熟悉Bash的也可以用来做自己自动化的工具

## 1.RequireMents:
### Ubuntu:
```
sudo apt-get install expect
```
### Archlinux:
```
sudo pacman -S expect
```
### Fedora:
```
sudo yum install expect
```
## 2. edit the ini file
the ini file should be like this:

![ini_file](https://github.com/winjeg/shellutils/blob/master/rrcb/init.png)
```
1. It should not contain illegal charaters such as ' or "

2. file_n  the file to be copied to the remote sever

3. cmd_n  the command is to be executed on the remote sever

4. cmd_n_exp the expected output of the command on that remote server
n should be continous

5. file_n will be executed before cmd_n
```
## 3. encrypt the ini file
when the ini file is written, execute the following command
```
chmod a+x rrcb
./rrcb -e inifile conf
```
input twice the password for encrypt the ini file
## 4. execute
./rrcb conf password
sample output is like this:
![result](https://github.com/winjeg/shellutils/blob/master/rrcb/result.png)

## 5. more usage see the help content of this command
./rrcb -h



