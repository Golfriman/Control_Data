CREATE OR REPLACE PROCEDURE changeStatusRooms()
LANGUAGE SQL
AS $$
BEGIN
	UPDATE room SET status = 'Требуется уборка' 
	where room.idroom NOT IN (SELECT idroom 
						  FROM workhotel 
						  where namework = 'Уборка' and 
						  		workhotel.time BETWEEN CURRENT_DATE - 3 and CURRENT_DATE)
END; $$