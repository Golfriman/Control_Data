INSERT INTO authorizationinsystem (login, password, idEmployee) VALUES ('Hohlova1975', '1975', 8)
INSERT INTO authorizationinsystem (login, password, idEmployee) VALUES ('Dmitrieva', '1987', 6)
INSERT INTO authorizationinsystem (login, password, idEmployee) VALUES ('Shukina', '1980', 7)

INSERT INTO authorizationinsystem (login, password, idEmployee) VALUES ('Titova', '1976', 13);
INSERT INTO authorizationinsystem (login, password, idEmployee) VALUES ('Ershova', '1984', 19);
SELECT * FROM employee ;
UPDATE authorizationinsystem SET password = password WHERE login = 'Hohlova1975'
SELECT * FROM authorizationinsystem;