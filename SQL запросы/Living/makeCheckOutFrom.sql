CREATE OR REPLACE FUNCTION makeCheckOut(_id INT)
RETURNS TEXT
AS $$
DECLARE
	_count INT := 0;
	_idBooking INT;
BEGIN
	SELECT idBooking INTO _idBooking FROM Booking, CheckIn 
	WHERE Booking.idRoom = CheckIn.idRoom and Booking.checkIn = CheckIn.d_checkIn and CheckIn.idCheckin = _id;
	
	UPDATE booking SET checkOutFrom = current_date WHERE idBooking = _idBooking RETURNING * INTO _count;
	IF (_count > 0)
		THEN RETURN 'Успешно';
	ELSE RETURN 'Произошла ошибка';
	END IF;
	RETURN 'ОШИБКА: ЧТО-ТО ПОШЛО НЕ ПОПЛАНУ';
END; $$ LANGUAGE PLPGSQL;

SELECT makeCheckOut(11);