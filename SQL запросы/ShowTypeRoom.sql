DROP FUNCTION showRooms();
CREATE OR REPLACE FUNCTION showRooms()
RETURNS TABLE (_id INT, _statusCleaning VARCHAR(255), _statusRoom TEXT)
AS $$
BEGIN
	RETURN QUERY (SELECT room.idRoom, room.status, 'забронирован'
	FROM room, booking
	WHERE room.idRoom = booking.idRoom and booking.checkIn = current_date and room.idRoom NOT IN (SELECT idRoom FROM CheckIn WHERE CheckIn.d_CheckIn = current_date) 
	UNION
	(SELECT room.idRoom, room.status, 'заселен'
	FROM room, checkIn
	WHERE room.idRoom = checkIn.idRoom and checkIn.d_checkIn + checkIn.numberOfPaidDays > current_date)	UNION 
	
	(SELECT room.idRoom, room.status, 'свободно'
	FROM room
	WHERE room.idRoom NOT IN (SELECT Booking.idRoom FROM Booking WHERE booking.checkIn = current_date) 
	 and room.idRoom NOT IN (SELECT CheckIn.idRoom FROM CheckIn WHERE checkIn.d_checkIn + checkIn.numberOfPaidDays > current_date)));
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM showRooms() ORDER BY _id;