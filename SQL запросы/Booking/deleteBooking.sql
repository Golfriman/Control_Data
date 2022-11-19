CREATE OR REPLACE FUNCTION deleteBooking(_idB INT)
RETURNS TEXT
AS $$
DECLARE 
	_count INT;
BEGIN
	DELETE FROM booking
	WHERE idBooking = _idB
	RETURNING * INTO _count;
	IF(_count = 1)
		THEN
			RETURN 'Удачно';
		ELSE
			RETURN 'Произошла ошибка при удалении';
	END IF;
	RETURN 'Что-то пошло не так!';
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM booking;
SELECT deleteBooking(3);