CREATE OR REPLACE FUNCTION payCheckIn(_idE INT,
									  _idR INT,
									  _work TEXT)
RETURNS VOID
AS $$
BEGIN
	INSERT INTO WorkHotel (idEmployee, idRoom, nameWork) VALUES(_idE, _idR, _work);
END; $$ LANGUAGE PLPGSQL;

SELECT payCheckIn(1, 1, '100');
INSERT INTO workhotel (idEmployee, idroom, namework, time) VALUES(1, 1, 'Будильник', '21-11-2022')