CREATE OR REPLACE FUNCTION payRoom(_id INT, _days INT)
RETURNS TEXT
AS $$
DECLARE
	_status INT:=0;
	checkOutFrom DATE;
	d_checkIn DATE;
BEGIN
	SELECT Booking.checkOutFrom, CheckIn.d_checkIn INTO checkOutFrom, d_checkIn FROM Booking, CheckIn WHERE Booking.idRoom = CheckIn.idRoom and CheckIn.idCheckIn = _id; 
	UPDATE checkIn SET numberOfPaidDays = numberOfPaidDays + _days WHERE idCheckIn = _id AND checkIn.d_checkIn + _days <= checkOutFrom;
	IF (_status > 0 ) THEN RETURN 'Успешно продлено!';	
	ELSE 
		BEGIN
			IF (d_checkIn + _days > checkOutFrom) THEN RETURN 'Невозможно продлить, количество дней превышает бронирование';
			ELSE RETURN 'Ошибка продления';
			END IF;
		END;
	END IF;
	RETURN 'ЧТО-ТО ПОШЛО НЕ ПОПЛАНУ';
END; $$ LANGUAGE PLPGSQL;
SELECT payRoom(10, 10);