CREATE OR REPLACE FUNCTION showHotelStatus()
RETURNS TABLE(_free INT, _occupied INT, _booked INT, _overdue INT)
AS $$
DECLARE
	all_room INT:=0;
	value2 INT:=0;
	value3 INT:=0;
	value4 INT:=0;
BEGIN
	SELECT COUNT(idRoom) INTO all_room FROM Room;
	SELECT COUNT(DISTINCT Booking.idRoom)INTO value2 FROM Booking WHERE checkIn = CURRENT_DATE and Booking.idRoom NOT IN(SELECT idRoom FROM checkin WHERE d_checkIn = CURRENT_DATE);
	SELECT COUNT(DISTINCT CheckIn.idRoom) INTO value3 FROM CheckIn, Booking WHERE CheckIn.idRoom = Booking.idRoom and CheckIn.d_checkIn >= CURRENT_DATE and Booking.CheckOutFrom <= CURRENT_DATE;
	SELECT COUNT(CheckIn.idRoom) INTO value4 FROM CheckIn, Booking WHERE CheckIn.idRoom = Booking.idRoom and Booking.checkIn >= CURRENT_DATE and Booking.CheckOutFrom <= CURRENT_DATE and CheckIn.d_checkIn + numberOfPaidDays < CURRENT_DATE;
	RETURN QUERY SELECT all_room - value2 - value3, value3, value2, value4;
END; $$ LANGUAGE PLPGSQL;



SELECT * FROM checkin WHERE d_checkIn = CURRENT_DATE;
SELECT * FROM Booking;
SELECT * FROM insertbooking(1, _fullname, _phone, _checkin, _checkout, _numofpeople, _services)
SELECT COUNT(DISTINCT CheckIn.idRoom) FROM CheckIn, Booking
WHERE CheckIn.idRoom = Booking.idRoom and CheckIn.d_checkIn >= CURRENT_DATE and Booking.CheckOutFrom <= CURRENT_DATE;
SELECT * FROM showHotelStatus();