--DROP FUNCTION statisticCheckInHotel;
CREATE OR REPLACE FUNCTION statisticCheckInHotel()
RETURNS TABLE (countCheckin INT, days INT)
AS $$
BEGIN
	CREATE TEMP TABLE IF NOT EXISTS dateCheckin (countCheckin INT, days INT);
	DELETE FROM datecheckin;
	FOR i IN 0..30
	LOOP
		INSERT INTO dateCheckin SELECT COUNT(*), 30-i FROM Checkin, Booking 
		WHERE Checkin.idRoom = Booking.idRoom and Checkin.d_checkin = Booking.checkin 
											  and (CURRENT_DATE-i BETWEEN Checkin.d_checkin and Booking.checkoutfrom);
	END LOOP;
				 
	RETURN QUERY SELECT * FROM dateCheckin;		 
END; $$ LANGUAGE PLPGSQL;


SELECT * FROM statisticCheckInHotel();
SELECT * FROM visitor WHERE idVisitor = 22;
 SELECT DATE_PART('year', '2012-01-01'::date) - DATE_PART('year', '2011-10-02'::date);