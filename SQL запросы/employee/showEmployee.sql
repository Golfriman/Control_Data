--DROP FUNCTION showEmployee;

CREATE OR REPLACE FUNCTION showEmployee(_filter TEXT)
RETURNS TABLE(fullname TEXT, birth DATE, phone TEXT)
AS $$
BEGIN
	RETURN QUERY SELECT Employee.fullname::TEXT, birthday, Employee.phone::TEXT
	FROM Employee 
	WHERE positioninthehotel::TEXT LIKE _filter and status = true;
END; $$ LANGUAGE PLPGSQL;

SELECT showEmployee('Администратор');