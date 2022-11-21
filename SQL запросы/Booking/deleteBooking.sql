CREATE OR REPLACE FUNCTION deleteBooking(_idB INT)
RETURNS TEXT
AS $$
DECLARE 
	msg_text TEXT;
	_count INT;
BEGIN
	BEGIN
		DELETE FROM booking
		WHERE idBooking = _idB RETURNING * INTO _count;
		IF(_count>0) THEN RETURN 'Успешно'; 
		ELSE RETURN 'ОШИБКА: Нельзя удалить, того чего нет!!'; END IF;
		
		EXCEPTION WHEN OTHERS THEN
		GET STACKED DIAGNOSTICS
		msg_text:=MESSAGE_TEXT;
		RETURN msg_text;
	END;
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM booking;
SELECT deleteBooking(3);