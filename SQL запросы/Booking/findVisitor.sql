--DROP FUNCTION findVisitor;
CREATE OR REPLACE FUNCTION findVisitor(_phone VARCHAR(20))
RETURNS TABLE(phone VARCHAR(20), fullname VARCHAR(255))
AS $$
DECLARE
	_fullname VARCHAR(255);
	__phone VARCHAR(20);
	_countPhones INT :=0;
	r visitor%rowtype;
BEGIN
	_phone:=_phone || '%';
	FOR r IN
		SELECT * FROM visitor WHERE visitor.phone LIKE _phone
	LOOP
		_countPhones:=_countPhones+1;
		_fullname :=r.fullname;
		__phone:=r.phone;
	END LOOP;
	CASE _countPhones
		WHEN 0 THEN RETURN QUERY SELECT 'Не найден'::VARCHAR(20), ''::VARCHAR(255);
		WHEN 1 THEN RETURN QUERY SELECT __phone, _fullname;
		ELSE RETURN QUERY SELECT 'похожих'::VARCHAR(20), _countPhones::VARCHAR(255);
	END CASE;
	RETURN QUERY SELECT 'ОШИБКА'::VARCHAR(20), 'ОШИБКА'::VARCHAR(20);
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM findVisitor('890690');
