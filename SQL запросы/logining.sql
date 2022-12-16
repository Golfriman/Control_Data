--DROP FUNCTION logining;

CREATE OR REPLACE FUNCTION logining(in_login TEXT, in_password TEXT, _position TEXT)
RETURNS TABLE(_idE INT, _result BOOL, fullname TEXT)
AS $$
BEGIN
	RETURN QUERY SELECT Employee.idEmployee, CASE 
											 WHEN Employee.positioninthehotel = _position THEN true
						   					 ELSE false END,
						Employee.fullname::TEXT
	FROM authorizationinsystem, Employee
	WHERE login = in_login and 
		  password = crypt(in_password, password) and
		  authorizationinsystem.idEmployee = employee.idEmployee and employee.status = true;
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM logining('Petuxova', '8246', '%');