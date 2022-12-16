DROP FUNCTION acceptBooking;
CREATE OR REPLACE FUNCTION acceptBooking(who INT,
										 _idB INT,
										 _countDays INT,
										 _fullnames TEXT[],
										 _series INT[],
										 _num INT[],
										 _phone TEXT[])
RETURNS TEXT AS $$
DECLARE
	SIZE_ARRAY INT := array_length(_fullnames, 1);
	i INT:=1;
	CURRENT_CHECK_IN_ID INT;
	_idRoom INT;
	CURRENT_ID_VISITOR INT;
	msg_txt TEXT;
	countMoney INT;
BEGIN
	BEGIN
	--Проверка на то что бронирование вообще существует, не знаю просто так
	IF NOT EXISTS(SELECT * FROM booking where idBooking = _idB) THEN RETURN 'Ошибка отсутсвует такое бронирование'; END IF;
	
	SELECT idRoom INTO _idRoom FROM booking where idBooking = _idB; --Получаем информацию о забронированной комнате
	INSERT INTO checkIn (idRoom, d_checkIn, numberOfPaidDays) VALUES(_idRoom, current_date, _countDays); -- Создаем заселение
	
	SELECT price*_countDays INTO countMoney FROM room, typeroom WHERE idRoom = _idRoom and room.category = typeroom.category;
	INSERT INTO workhotel (idEmployee, idRoom, namework, time) VALUES(who, _idRoom, countMoney::TEXT, CURRENT_DATE);
	
	SELECT MAX(idCheckIn) INTO CURRENT_CHECK_IN_ID FROM checkIn; -- Получаем текущий id заселения
	WHILE i <= SIZE_ARRAY LOOP
		IF(_fullnames[i] = 'Ребенок') THEN 
		BEGIN 
			i:=i+1; 
			CONTINUE; 
		END; END IF; 

		SELECT idVisitor INTO CURRENT_ID_VISITOR
			FROM visitor
			WHERE fullname = _fullnames[i] and ((series = _series[i] and passportnumber = _num[i]) or phone = _phone[i]);

		IF (CURRENT_ID_VISITOR IS NULL) THEN --Если таких посетителей не было в системе обновляем информацию о них
		BEGIN
			INSERT INTO visitor (fullname, series, passportnumber, phone) VALUES
			(_fullnames[i], _series[i], _num[i], _phone[i]);
			SELECT MAX(idVisitor) INTO CURRENT_ID_VISITOR FROM visitor;
		END;
		END IF;
		
		INSERT INTO living (idcheckin, idvisitor) VALUES (CURRENT_CHECK_IN_ID, CURRENT_ID_VISITOR); --Заполняем информацию о посетителях к заселению
		CURRENT_ID_VISITOR := NULL;
		i := i+1;
	END LOOP;
	
	INSERT INTO livingService(typeservice, idCheckin, num) SELECT typeservies,CURRENT_CHECK_IN_ID, _type FROM pre_service_booking WHERE idBooking = _idB;
	INSERT INTO WORKHOTEL(IDEMPLOYEE, IDROOM, NAMEWORK, TIME) SELECT WHO, _IDROOM, typeservies, CURRENT_DATE FROM pre_service_booking WHERE idBooking = _idB;
	EXCEPTION WHEN OTHERS THEN
	GET STACKED DIAGNOSTICS
	msg_txt:=MESSAGE_TEXT;
	RETURN msg_txt;
	END;
	RETURN 'Удачно';
END; $$ LANGUAGE PLPGSQL;

SELECT * FROM acceptBooking(1 ,55, 1, '{"Черенкова Евдокия Данииловна","Ребенок"}', '{null,null}', '{null,null}', '{"89568106981",""}');
SELECT * FROM visitor where fullname = 'Черенчикова Евдокия Данииловна' and phone = '89568106981'
SELECT * FROM acceptBooking(1 ,55, 1, '{"Черенкова Евдокия Данииловна","Ребенок"}', '{nullnul}', '{nullnul}', '{"89568106981",""}');