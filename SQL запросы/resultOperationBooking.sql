CREATE OR REPLACE FUNCTION resultOperationBooking(_idB INT)
RETURNS TEXT
AS $$
DECLARE
	res TEXT;
BEGIN
	IF EXISTS (SELECT * FROM LOG_BOOKING WHERE _idBooking = _idB and _result = false)
		THEN res := 'Ошибка операции';
		ELSE res := 'Успешно';
	END IF;
	DELETE FROM LOG_BOOKING WHERE _idBooking = _idB;
	RETURN res;
END; $$ LANGUAGE plpgsql;