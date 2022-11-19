DROP FUNCTION topServices();
CREATE OR REPLACE FUNCTION topServices()
RETURNS TABLE (_type VARCHAR(100), _count BIGINT)
AS $$
BEGIN
	RETURN QUERY 
		SELECT typeservice, SUM(num)
		FROM LivingService, CheckIn
		WHERE LivingService.idCheckIn = CheckIn.idCheckIn and checkIn.d_checkIn between (current_date - 30) and current_date
		GROUP BY typeservice 
		ORDER BY SUM(num) DESC
		LIMIT 10;
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM topServices();

