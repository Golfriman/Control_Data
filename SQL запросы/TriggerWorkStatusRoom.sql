CREATE OR REPLACE FUNCTION workStatusRoom()
RETURNS TRIGGER
AS $$
BEGIN
	IF (new.namework = 'Уборка') THEN
		UPDATE room 
		SET status = 'Убрано'
		WHERE idroom = new.idroom;
	END IF;
	RETURN NEW;
END; $$ LANGUAGE PLPGSQL;

CREATE TRIGGER workStatusRoom 
	AFTER INSERT ON workhotel
	FOR EACH ROW EXECUTE PROCEDURE workStatusRoom();