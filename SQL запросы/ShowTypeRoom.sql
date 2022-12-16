DROP FUNCTION showRooms();
CREATE OR REPLACE FUNCTION showRooms()
RETURNS TABLE (_id INT, category VARCHAR(100), _statusCleaning VARCHAR(255),_price INT, _size INT, _cap INT, _statusRoom TEXT)
AS $$
BEGIN
	RETURN QUERY (SELECT room.idRoom, room.category, room.status, typeroom.price,typeroom.sizeroom, typeroom.capacity, 'забронирован'
	FROM room, booking, typeroom
	WHERE typeroom.category = room.category and room.idRoom = booking.idRoom and booking.checkIn = current_date and room.idRoom NOT IN (SELECT idRoom FROM CheckIn WHERE CheckIn.d_CheckIn = current_date) 
	UNION
	(SELECT room.idRoom, room.category, room.status, typeroom.price, typeroom.sizeroom, typeroom.capacity, 'заселен'
	FROM room, checkIn, typeroom
	WHERE typeroom.category = room.category and room.idRoom = checkIn.idRoom and checkIn.d_checkIn + checkIn.numberOfPaidDays >= current_date)	UNION 
	
	(SELECT room.idRoom, room.category, room.status,typeroom.price,typeroom.sizeroom,typeroom.capacity, 'свободно'
	FROM room, typeroom
	WHERE typeroom.category = room.category and room.idRoom NOT IN (SELECT Booking.idRoom FROM Booking WHERE booking.checkIn = current_date) 
	 and room.idRoom NOT IN (SELECT CheckIn.idRoom FROM CheckIn WHERE checkIn.d_checkIn + checkIn.numberOfPaidDays >= current_date)));
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM showRooms() ORDER BY _id;