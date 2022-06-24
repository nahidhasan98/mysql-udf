# mysql-udf

### references

#### c
- raptor_udf (https://github.com/0xdea/exploits/blob/master/mysql/raptor_udf.c)
- mysql_udf (https://github.com/mysqludf/lib_mysqludf_sys)

#### go
- dveeden blog (https://databaseblog.myname.nl/2015/10/a-mysql-udf-written-in-go.html)
- dveeden (https://github.com/dveeden/udf_fileexists_go/blob/master/udf_fileexists_go.go)
- BrianLeishman (https://gist.github.com/BrianLeishman/1720c3c3d47b799d5dd913cedea654c5)

#### go build command
go build -buildmode=c-shared -o run_go.so && cp run_go.so /usr/lib64/mysql/plugin/run_go.so