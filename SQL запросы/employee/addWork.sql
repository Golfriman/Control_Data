CREATE OR REPLACE FUNCTION addWork(_idEmployee INT, _idRoom INT, _namework TEXT)
RETURNS TEXT
AS $$
BEGIN
	INSERT INTO workhotel(idEmployee, idroom, namework, time) VALUES(_idEmployee, _idroom, _namework, current_date);
	RETURN 'Успешно';
END; $$ LANGUAGE PLPGSQL;