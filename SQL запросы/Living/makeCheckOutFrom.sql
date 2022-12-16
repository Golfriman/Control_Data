CREATE OR REPLACE FUNCTION makeCheckOut(_id INT)
RETURNS TEXT
AS $$
DECLARE
	_count INT := 0;
	_idRoom INT:=0;
	_idBooking INT;
	_msg TEXT;
	_idV INT;
BEGIN
	BEGIN
		SELECT idBooking, Booking.idRoom, Booking.IdVisitor INTO _idBooking, _idRoom, _idV FROM Booking, CheckIn 
		WHERE Booking.idRoom = CheckIn.idRoom and Booking.checkIn = CheckIn.d_checkIn and CheckIn.idCheckin = _id;
		DELETE FROM LOG_BOOKING WHERE _idVisitor = _idV;
		UPDATE Room SET status='Требуется уборка' WHERE idRoom =_idRoom;
		UPDATE booking SET  checkOutFrom = current_date-1 WHERE idBooking = _idBooking RETURNING * INTO _count;
		EXCEPTION WHEN OTHERS THEN GET STACKED DIAGNOSTICS _msg:= MESSAGE_TEXT; RETURN _msg;
		END;
		IF (_count > 0)
			THEN RETURN 'Успешно';
		ELSE RETURN 'Произошла ошибка';
		END IF;
END; $$ LANGUAGE PLPGSQL;
SELECT * FROM visitor WHERE fullname = 'Рябков Артемий Геннадиевич';
select * from booking;
SELECT makeCheckOut(11);
SELECT makeCheckOut(32);