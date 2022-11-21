--DROP FUNCTION statisticCheckInHotel;
CREATE OR REPLACE FUNCTION statisticCheckInHotel()
RETURNS TABLE(countCheckIn INT, days INT)
AS $$
DECLARE maxRoom REAL:=0;
BEGIN
	SELECT COUNT(idRoom)INTO maxRoom FROM room;
	RETURN QUERY SELECT ((COUNT(idCheckIn)::REAL/maxRoom)*100)::int, 30 - (CURRENT_DATE - d_checkIn)::int
				 FROM CheckIn 
				 WHERE d_checkIn + 30 >= CURRENT_DATE
				 GROUP BY d_checkIn;
END; $$ LANGUAGE PLPGSQL;
SELECT * FROM statisticCheckInHotel();
 SELECT DATE_PART('year', '2012-01-01'::date) - DATE_PART('year', '2011-10-02'::date);