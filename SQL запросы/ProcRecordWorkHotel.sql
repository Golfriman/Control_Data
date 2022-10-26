CREATE OR REPLACE PROCEDURE recordWorkHotel(ID_SOTR INT, ID_ROOM INT, NAME_WORK VARCHAR(255))
LANGUAGE SQL
BEGIN ATOMIC
	INSERT INTO workhotel (idemployee, idroom, namework, time)
	VALUES (ID_SOTR, ID_ROOM, NAME_WORK, current_date);
END;

CALL recordworkhotel(8, 1, 'Уборка');
