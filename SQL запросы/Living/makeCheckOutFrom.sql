CREATE OR REPLACE FUNCTION makeCheckOut(_id INT)
RETURNS TEXT
AS $$
DECLARE
	_count INT := 0;
	_idRoom INT:=0;
	_idBooking INT;
BEGIN
	SELECT idBooking, Booking.idRoom INTO _idBooking, _idRoom FROM Booking, CheckIn 
	WHERE Booking.idRoom = CheckIn.idRoom and Booking.checkIn = CheckIn.d_checkIn and CheckIn.idCheckin = _id;
	UPDATE Room SET status='Требуется уборка' WHERE idRoom =_idRoom;
	UPDATE booking SET checkOutFrom = current_date-1 WHERE idBooking = _idBooking RETURNING * INTO _count;
	IF (_count > 0)
		THEN RETURN 'Успешно';
	ELSE RETURN 'Произошла ошибка';
	END IF;
	RETURN 'ОШИБКА: ЧТО-ТО ПОШЛО НЕ ПОПЛАНУ';
END; $$ LANGUAGE PLPGSQL;
SELECT * FROM visitor WHERE fullname = 'Рябков Артемий Геннадиевич';
SELECT makeCheckOut(11);