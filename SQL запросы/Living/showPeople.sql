CREATE OR REPLACE FUNCTION showPeople(_id INT)
RETURNS TABLE(fullname VARCHAR(255), phone VARCHAR(20))
AS $$
BEGIN
	RETURN QUERY SELECT visitor.fullname, visitor.phone 
	FROM living, visitor
	WHERE living.idCheckIn = _id and living.idVisitor = visitor.idVisitor;
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM showPeople(10);

SELECT * FROM visitor WHERE fullname LIKE 'Грошев%';