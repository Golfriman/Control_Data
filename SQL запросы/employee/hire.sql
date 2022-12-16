CREATE OR REPLACE FUNCTION hireEmployee(_id INT)
RETURNS TEXT
AS $$
DECLARE
	_count INT:=0;
BEGIN
	UPDATE employee SET status = false WHERE idEmployee = _id RETURNING * INTO _count;
	IF (_count <> 0)
		THEN RETURN 'Успешно';
	ELSE RETURN 'Произошла ошибка при уволнении';
	END IF;
END; $$ LANGUAGE PLPGSQL;
UPDATE employee SET Status = true;
SELECT * FROM employee;
SELECT hireEmployee(1);