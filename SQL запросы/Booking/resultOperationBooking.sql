--DROP FUNCTION resultOperationBooking(int);
CREATE OR REPLACE FUNCTION resultOperationBooking(_idV INT)
RETURNS TEXT
AS $$
DECLARE
	res TEXT;
BEGIN
	IF EXISTS (SELECT * FROM LOG_BOOKING WHERE _idVisitor = _idV and _result = false)
		THEN res := 'Ошибка операции';
		ELSE res := 'Успешно';
	END IF;
	DELETE FROM LOG_BOOKING WHERE _idVisitor = _idV;
	RETURN res;
END; $$ LANGUAGE plpgsql;