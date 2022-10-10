drop trigger crypt_password on authorization_view;

create or replace function crypt_pass() returns trigger as
$$
DECLARE
	p text :=crypt(password, gen_salt('md5'));
	l text :=login;
BEGIN
	update authorizationinsystem
			set password = p
			where login = l;
	return new;
END;
$$
language plpgsql;
DROP VIEW authorization_view;
CREATE VIEW authorization_view as 
SELECT firstname, secondname, login, password
FROM authorizationinsystem;

CREATE TRIGGER crypt_password
	INSTEAD OF INSERT or update on authorization_view
	for each row
	execute procedure crypt_pass();