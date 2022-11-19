CREATE OR REPLACE FUNCTION extendLiving(_idLiving INT,
										_countDays INT)
RETURNS TEXT
AS $$
DECLARE 
	_idR INT;
	_outD INT;
	_paid INT;
	_inD INT;
BEGIN
	SELECT idRoom, idCheckIn, numberOfPaidDays INTO _idR, _inD,  _paid
	FROM checkIn
	WHERE idCheckIn = _idLiving;
	
	SELECT checkOutFrom INTO _outD 
	FROM Booking
	WHERE idRoom = _idR and checkIn = _inD;
	
	IF (_inD + _paid + _countDays > _outD)
	THEN
		RETURN 'Ошибка: Больше чем забронировано';
	ELSE
		UPDATE checkIn SET numberOfPaidDays = _paid + _count WHERE idCheckin = _idLiving;
	END IF;
	
	RETURN 'Успешно';	
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM Booking;
SELECT * FROM CheckIN;