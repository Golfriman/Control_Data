delete from authorizationinsystem;

insert into authorizationinsystem(firstname, secondname, login, password)
	values('giga', 'chad', '1', '1');

select * from authorizationinsystem;

update authorizationinsystem set password = '2' where login = '1'