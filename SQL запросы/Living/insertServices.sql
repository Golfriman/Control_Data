			--Заселение
			--Удаляем записи, которые отсутсвуют в строке
			--Вставялем новые записи равные 0 если услуг нет в услугах_засления и услуга есть в таблице услуг
			--Увеличиваем каждую новую запись на 1
CREATE OR REPLACE PROCEDURE insertServicesLiving(_data TEXT, _id INT)	
AS $$
BEGIN
	DELETE FROM livingService WHERE typeservice NOT SIMILAR TO _data and idCheckin = _id;
	INSERT INTO livingService 
				SELECT service.typeservice, _id, 0
				FROM service,livingservice
				WHERE livingservice.typeservice NOT SIMILAR TO _data and service.typeservice SIMILAR TO _data;
	UPDATE livingservice SET num = num + 1;
END; $$ LANGUAGE PLPGSQL;