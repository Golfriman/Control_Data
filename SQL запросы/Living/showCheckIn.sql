CREATE OR REPLACE FUNCTION showCheckIn()
RETURNS TABLE (_id INT, status TEXT)
AS $$
BEGIN
	RETURN QUERY SELECT idCheckIn, CASE WHEN d_checkIn + numberofpaiddays - current_date > 0 THEN 'оплачно' ELSE 'просрочено' END
	FROM Booking, CheckIn 
	WHERE (Booking.idRoom = CheckIn.idRoom and Booking.checkin = CheckIn.d_checkIn);
END; $$ LANGUAGE PLPGSQL;

select * from showCheckIn();