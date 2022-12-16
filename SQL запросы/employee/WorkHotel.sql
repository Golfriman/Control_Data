CREATE OR REPLACE FUNCTION converterWork(_nameWork TEXT)
RETURNS TEXT
AS $$
DECLARE ans TEXT;
BEGIN
	ans:= CASE
			WHEN _namework ~'^[0-9]' THEN'Оплачено засление ' || _namework || ' руб'
			WHEN EXISTS (SELECT * FROM service WHERE typeservice = _nameWork) THEN 'Услуга ' || _nameWork
			ELSE _namework
		   END;
	RETURN ans;
END; $$ LANGUAGE PLPGSQL;

CREATE OR REPLACE FUNCTION showWorkInHotel(cur DATE)
RETURNS TABLE (_empl TEXT, _work TEXT, _where INT)
AS $$
BEGIN
	RETURN QUERY SELECT fullname::TEXT, converterWork(namework), idRoom 
	FROM WorkHotel, Employee 
	WHERE WorkHotel.idEmployee = Employee.idEmployee and WorkHotel.time = cur;
END; $$ LANGUAGE PLPGSQL;

SELECT showWorkInHotel('21.11.2022');