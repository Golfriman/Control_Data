--DROP FUNCTION showbooking(int);
CREATE OR REPLACE FUNCTION showBooking(duration int)
RETURNS TABLE (ID_BOOKING INT,
			   ID_ROOM INT,
			   ID_VISITOR INT,
			   FULLNAME VARCHAR(255),
			   CHECK_IN DATE,
			   CHECK_OUT DATE,
			   NUM_OF_PEOPLE SMALLINT,
			   _phone VARCHAR(20))
AS $$
BEGIN 
	RETURN QUERY
			SELECT DISTINCT booking.idbooking, booking.idroom, visitor.idVisitor, visitor.fullname,  booking.checkin, booking.checkoutfrom, booking.numofpeople, visitor.phone
			FROM booking, visitor, checkin
			WHERE booking.idvisitor = visitor.idvisitor 
				AND booking.idvisitor NOT IN (SELECT living.idVisitor FROM living WHERE living.idCheckIn = checkin.idCheckIn)
				AND booking.checkIn BETWEEN CURRENT_DATE AND CURRENT_DATE + duration; 
END; $$ LANGUAGE plpgsql;

--select showbooking(30);
				  