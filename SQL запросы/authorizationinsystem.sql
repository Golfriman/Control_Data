/*DROP VIEW authorization_view;
DROP TABLE authorizationinsystem;*/

CREATE TABLE authorizationinsystem (
	login TEXT,
	password TEXT,
	idEmployee INT,
	FOREIGN KEY(idEmployee)
	REFERENCES Employee(idEmployee)
);
select * from employee;
SELECT * FROM authorizationinsystem;
insert into authorization_view(login, password, idEmployee) VALUES ('Petuxova', '8246', 9);

