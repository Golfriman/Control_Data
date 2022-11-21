--DROP FUNCTION updateBooking;
CREATE OR REPLACE FUNCTION updateBooking(_idB int,
										 _idV int,
										 _idR int, 
										 _checkIn DATE, 
										 _checkOut DATE, 
										 _numOfPeople INT,
										 _data TEXT)
RETURNS TEXT
AS $$
DECLARE 
	res TEXT;
BEGIN 
		BEGIN
		UPDATE booking 
			SET idRoom = _idR,
				checkIn = _checkIn,
				checkOutFrom = _checkOut,
				numOfPeople = _numOfPeople
			WHERE idBooking = _idB;
		res :=resultOperationBooking(_idV);
		if(res = 'Успешно') THEN CALL insertServicesBooking(_data, _idB); END IF;
		EXCEPTION WHEN OTHERS THEN
		GET STACKED DIAGNOSTICS
		res:=MESSAGE_TEXT;
		RETURN res;
		END;
	return res;
END; $$ LANGUAGE plpgsql;

SELECT * FROM Booking;
--Проверочные значения
SELECT updateBooking(4,4, 5, '2023-10-04', '2023-11-04', 2, '(Вызов такси)');
