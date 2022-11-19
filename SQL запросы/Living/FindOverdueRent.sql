DROP FUNCTION findOverdueRent();
CREATE OR REPLACE FUNCTION findOverdueRent()
RETURNS TABLE (_idCheckIn INT)
AS $$
BEGIN
	RETURN QUERY
		SELECT idCheckIn 
		FROM CheckIn, Booking
		WHERE CheckIn.d_checkIn = Booking.checkIn and CheckIn.idRoom = Booking.idRoom
			 and CheckIn.d_checkIn + CheckIn.numberOfPaidDays < current_date
			 and Booking.checkOutFrom > current_date
			 
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM findOverdueRent();