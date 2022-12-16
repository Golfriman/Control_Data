DROP FUNCTION showEmployee_fullname;
CREATE OR REPLACE FUNCTION showEmployee_fullname(_user INT, _filter TEXT)
RETURNS TABLE(fullname TEXT, birth DATE, phone TEXT, _id INT)
AS $$
BEGIN
	RETURN QUERY SELECT Employee.fullname::TEXT, birthday, Employee.phone::TEXT, idEmployee
	FROM Employee 
	WHERE Employee.fullname::TEXT LIKE _filter and status=true and idEmployee <> _user;
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM showEmployee('%%')
SELECT * FROM showEmployee_fullname(2, '%%')
SELECT * FROM showRooms() ORDER BY _ID

UPDATE Employee SET status = true WHERE fullname LIKE 'Брагин%'


SELECT * FROM showEmployee_fullname('%', 1);