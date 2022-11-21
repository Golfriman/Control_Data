CREATE OR REPLACE FUNCTION addVisitor(_fullname VARCHAR(255), 
									  _passportSeries INT, 
									  _passportNumber INT, 
									  _phone VARCHAR(20))
RETURNS TEXT
AS $$
DECLARE
msg_text TEXT;
BEGIN
	BEGIN
		INSERT INTO visitor(fullname, series, passportnumber, phone) VALUES (_fullname, _passportSeries, _passportNumber, _phone);
		EXCEPTION WHEN OTHERS
		THEN 
		GET STACKED DIAGNOSTICS
		msg_text:=MESSAGE_TEXT;
		RETURN msg_text;
	END;
	RETURN 'Успешно';
END; $$ LANGUAGE PLPGSQL;

SELECT addVisitor('Григорьев Иванов Иванович', null, null, null);