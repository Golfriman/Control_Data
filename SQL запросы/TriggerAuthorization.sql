drop trigger crypt_password on authorization_view;

create or replace function crypt_pass() returns trigger as
$$
DECLARE
	p text :=crypt(new.password, gen_salt('md5'));
	l text :=new.login;
BEGIN
	IF (TG_OP = 'INSERT') THEN insert into authorizationinsystem (login, password, idEmployee) VALUES(l, p, new.idEmployee);
	ELSE update authorizationinsystem
			set password = p
			where idEmployee = new.idEmployee;
	END IF;
	return new;
END;$$ language plpgsql;


DROP VIEW authorization_view;
CREATE VIEW authorization_view as 
SELECT login, password, idEmployee
FROM authorizationinsystem;

CREATE TRIGGER crypt_password
	INSTEAD OF INSERT or update on authorization_view
	for each row
	execute procedure crypt_pass();