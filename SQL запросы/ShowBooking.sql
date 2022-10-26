--DROP FUNCTION showbooking(int);
CREATE OR REPLACE FUNCTION showBooking(duration int)
RETURNS TABLE (ID_BOOKING INT,
			   ID_ROOM INT,
			   FULLNAME VARCHAR(255),
			   CHECK_IN DATE,
			   CHECK_OUT DATE,
			   NUM_OF_PEOPLE SMALLINT)
AS $$
BEGIN 
	RETURN QUERY
			SELECT booking.idbooking, idroom, visitor.fullname,  checkin, checkoutfrom, numofpeople
			FROM booking, visitor
			WHERE booking.idvisitor = visitor.idvisitor and checkin between current_date and current_date + duration;
END; $$ LANGUAGE plpgsql;

--select * from showbooking(10);
				  