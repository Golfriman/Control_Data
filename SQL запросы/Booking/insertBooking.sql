DROP FUNCTION insertBooking(int, varchar(255), VARCHAR(20), DATE, DATE, INT);
CREATE OR REPLACE FUNCTION insertBooking(_idR int,
										 _fullname VARCHAR(255),
										 _phone VARCHAR(20),
										 _checkIn DATE, 
										 _checkOut DATE, 
										 _numOfPeople INT,
										 _services TEXT)
RETURNS TEXT
AS $$
DECLARE
	_idV INT;
	_current INT;
BEGIN
	SELECT idVisitor INTO _idV
		FROM visitor
		WHERE phone = _phone and fullname = _fullname;
		
	SELECT MAX(idBooking) INTO _current FROM booking;
	_current := _current + 1;
	INSERT INTO booking (idVisitor, idRoom, checkIn, checkOutFrom, numOfPeople)
		VALUES
		(_idV, _idR, _checkIn, _checkOut, _numOfPeople);
		
	CALL insertServicesBooking(_services, _current);
	RETURN resultOperationBooking(_idV);
END; $$ LANGUAGE plpgsql;
--Проверка
SELECT * FROM booking;
SELECT * FROM visitor;
SELECT * FROM room;
SELECT insertBooking(5,'Твардовский Лука Святославович', '89939961949', '2022-09-04', '2022-09-04', 2,'(Вызов такси)');