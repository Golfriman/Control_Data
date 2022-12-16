CREATE OR REPLACE FUNCTION showServices(_id INT)
RETURNS TABLE (_typeSerivce TEXT, _count INT)
AS $$
BEGIN
	RETURN QUERY SELECT typeservice::TEXT, num
		FROM livingService
		WHERE idcheckin = _id;
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM showServices(2);
SELECT * FROM checkin;
INSERT INTO livingservice (typeservice, idcheckin, num) VALUES('Вызов такси', 32, 1);
SELECT * FROM visitor WHERE fullname LIKE 'Филимонов %';