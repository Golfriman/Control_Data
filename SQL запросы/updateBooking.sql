--DROP FUNCTION updateBooking;
CREATE OR REPLACE PROCEDURE updateBooking(_idB int, 
										 _idR int, 
										 _checkIn DATE, 
										 _checkOut DATE, 
										 _numOfPeople INT)
AS $$
BEGIN 
	UPDATE booking 
		SET idRoom = _idR,
			checkIn = _checkIn,
			checkOutFrom = _checkOut,
			numOfPeople = _numOfPeople
		WHERE idBooking = _idB;
END; $$ LANGUAGE plpgsql;

--Проверочные значения
CALL updateBooking(2, 5, '2022-09-04', '2022-09-04', 2);
SELECT resultOperationBooking(2);
