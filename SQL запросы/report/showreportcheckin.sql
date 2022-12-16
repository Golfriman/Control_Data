CREATE OR REPLACE FUNCTION showReportCheckIn()
RETURNS TABLE(_idR INT, fullname TEXT)
AS $$
BEGIN
	RETURN QUERY SELECT Checkin.idRoom, visitor.fullname::TEXT
	FROM checkin, visitor, living
	WHERE checkin.idCheckin = living.idcheckin AND living.idVisitor = visitor.idVisitor AND checkin.d_checkin = CURRENT_DATE;
END; $$ LANGUAGE PLPGSQL;
SELECT * FROM showreportCheckin();
