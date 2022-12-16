CREATE OR REPLACE FUNCTION addEmployee(_fullname TEXT, 
									   _phone TEXT, 
									   _birth DATE,
									   _position TEXT)
RETURNS TEXT
AS $$
DECLARE _msg TEXT;
BEGIN
	BEGIN
		INSERT INTO Employee (fullname, positioninthehotel, phone, birthday) VALUES (_fullname, _position, _phone, _birth);
		EXCEPTION WHEN OTHERS THEN
		GET STACKED DIAGNOSTICS _msg := MESSAGE_TEXT;
		RETURN _msg;
	END;
	RETURN 'Успешно';
END; $$ LANGUAGE PLPGSQL;