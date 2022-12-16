CREATE OR REPLACE FUNCTION findVisitor(_fullname TEXT, 
									   _series TEXT,
									   _number TEXT)
RETURNS TABLE (_FIO TEXT, _idRoom INT, _dateCheckin DATE, _dateCheckOut DATE)
AS $$
BEGIN
	RETURN QUERY SELECT Visitor.fullname::TEXT, booking.idRoom, booking.checkIn, booking.checkoutfrom 
	FROM visitor, booking
	WHERE visitor.fullname LIKE _fullname and (visitor.series::TEXT LIKE _series and visitor.passportnumber::TEXT LIKE _number) and booking.idVisitor = visitor.idVisitor;
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM findVisitor('Филимонов Тимур Моисеевич%', '%', '%');