--查看当前数据库的相关编码集。
show variables like 'character%'; 

--如果存在school则删除
drop database if exists school;  
--建立库school
create database school;  
--打开库SCHOOL
use school;  
--建立表TEACHER
drop table if exists teacher;
create table teacher
(  
    id int(5) auto_increment not null primary key,
    name char(10) not null,
    address varchar(50) not null,
    inyear date not null
)default charset=utf8;

insert into teacher values(1, 'a', 'b', '1990-01-01');
insert teacher(name, address, inyear) values('a', '西安', '1990-01-01');