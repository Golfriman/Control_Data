CREATE OR REPLACE FUNCTION changeCleanStatus(_idRoom INT, 
											 _status TEXT)
RETURNS TEXT
AS $$
DECLARE _msg TEXT;
BEGIN
	BEGIN
	UPDATE room SET status = _status WHERE idRoom = _idRoom;
	EXCEPTION WHEN OTHERS THEN
	GET STACKED DIAGNOSTICS
		_msg:=MESSAGE_TEXT;
		RETURN _msg;
	END;
	RETURN 'Успешно';
END; $$ LANGUAGE PLPGSQL;

SELECT changecleanstatus(1, 'Требуется уборка');

SELECT * FROM room;