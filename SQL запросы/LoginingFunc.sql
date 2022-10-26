DROP FUNCTION logining;
CREATE OR REPLACE FUNCTION logining(in_login TEXT, in_password TEXT)
RETURNS TABLE (firstname VARCHAR(255), secondname VARCHAR(255))
AS $$
BEGIN
	RETURN QUERY SELECT authorizationinsystem.firstname, authorizationinsystem.secondname 
	FROM authorizationinsystem
	WHERE login = in_login and password = crypt(in_password, password);
END;
$$ LANGUAGE 'plpgsql';

select * from logining('1', '4');