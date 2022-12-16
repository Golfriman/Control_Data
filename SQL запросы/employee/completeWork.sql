CREATE OR REPLACE FUNCTION completeWork(_idE INT,
									    description TEXT,
									   	_idRoom INT)
RETURNS TEXT
AS $$
DECLARE _msg TEXT;
BEGIN
	BEGIN
		INSERT INTO workHotel(idEmployee, idRoom, namework, time) VALUES(_idE, _idRoom, description, current_date);
		EXCEPTION WHEN OTHERS 
		THEN 
			GET STACKED DIAGNOSTICS
			_msg:=MESSAGE_TEXT;
			RETURN _msg;
	END;
	RETURN 'успешно';
END; $$ LANGUAGE PLPGSQL;
DELETE FROM workHotel where idWork = 19
SELECT * FROM workHotel where time = current_date;
SELECT idRoom FROM room ORDER BY idRoom
SELECT * FROM completeWork(1, '100', 1)