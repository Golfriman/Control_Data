DROP TABLE IF EXISTS Visitor CASCADE;
CREATE TABLE Visitor(
	idVisitor SERIAL PRIMARY KEY,
	fullName VARCHAR(255) NOT NULL, 
	series INT CHECK(series > 0),
	passportNumber INT CHECK(passportNumber > 0),
	phone VARCHAR(20) UNIQUE,
	UNIQUE (series, passportNumber)
);

DROP TABLE IF EXISTS TypeRoom CASCADE;
CREATE TABLE TypeRoom (
 	category varchar(100) PRIMARY KEY,
 	price INT NOT NULL CHECK (price > 0),
 	capacity INT NOT NULL,
 	sizeRoom INT NOT NULL,
 	bathroom BOOL NOT NULL,
 	typeBed VARCHAR(30) NOT NULL,
 	airConditioning BOOL NOT NULL
 );

 DROP TABLE IF EXISTS Room CASCADE;
 CREATE TABLE Room (
 	idRoom SERIAL PRIMARY KEY,
 	category VARCHAR(100) NOT NULL,
 	status VARCHAR(50),
 	viewFromTheWindow VARCHAR(100) NOT NULL,
 	FOREIGN KEY(category)
 	REFERENCES TypeRoom (category)
 );
 DROP TABLE IF EXISTS Booking CASCADE;
 CREATE TABLE Booking(
 	idBooking SERIAL PRIMARY KEY,
 	idVisitor INT CHECK (idVisitor > 0) NOT NULL,
 	idRoom INT CHECK(idRoom > 0) NOT NULL,
 	checkIn DATE NOT NULL,
 	checkOutFrom DATE NOT NULL,
 	numOfPeople SMALLINT CHECK( numOfPeople > 0) NOT NULL,
 	FOREIGN KEY (idVisitor)
 	REFERENCES Visitor (idVisitor),

 	FOREIGN KEY (idRoom)
 	REFERENCES Room(idRoom)
 );

 DROP TABLE IF EXISTS BookedRooms CASCADE;
 DROP TABLE IF EXISTS CheckIn CASCADE;
 CREATE TABLE CheckIn (
 	idCheckIn SERIAL PRIMARY KEY,
 	idRoom INT NOT NULL,
 	d_checkIn DATE NOT NULL,
 	numberOfPaidDays INT NOT NULL CHECK(numberOfPaidDays >= 0),
 	FOREIGN KEY(idRoom)
 	REFERENCES Room(idRoom)
 );

 DROP TABLE IF EXISTS Living CASCADE;
 CREATE TABLE Living (
 	idCheckIn INT,
 	idRoom INT,
 	PRIMARY KEY (idCheckIn, idRoom),

 	FOREIGN KEY (idCheckIn)
 	REFERENCES CheckIn (idCheckIn),
 	FOREIGN KEY (idRoom)
 	REFERENCES Room (idRoom)
 );

 DROP TABLE IF EXISTS Service CASCADE;
 CREATE TABLE Service (
 	typeService VARCHAR (100) PRIMARY KEY,
 	price INT NOT NULL CHECK (price > 0)
 );

 DROP TABLE IF EXISTS LivingService CASCADE;
 CREATE TABLE LivingService(
 	typeService VARCHAR (100),
 	idCheckIn INT,
 	num INT DEFAULT 0 CHECK(num >= 0) NOT NULL,
 	PRIMARY KEY (typeService, idCheckIn),

 	FOREIGN KEY (typeService)
 	REFERENCES Service (typeService),

 	FOREIGN KEY (idCheckIn)
 	REFERENCES CheckIn (idCheckIn)
 );

 DROP TABLE IF EXISTS Employee CASCADE;
 CREATE TABLE Employee (
 	idEmployee SERIAL PRIMARY KEY,
 	fullName VARCHAR (255) NOT NULL,
 	positionInTheHotel VARCHAR (255) NOT NULL,
 	phone VARCHAR(20) UNIQUE DEFAULT NULL,
 	birthday DATE NOT NULL
 );

DROP TABLE IF EXISTS WorkHotel CASCADE;

CREATE TABLE WorkHotel (
 	idWork SERIAL PRIMARY KEY,
 	idEmployee INT NOT NULL,
 	idRoom INT NOT NULL,
	nameWork VARCHAR(100) NOT NULL,
	time DATE NOT NULL DEFAULT now(),
 	FOREIGN KEY (idEmployee)
 	REFERENCES Employee (idEmployee),
 	FOREIGN KEY (idRoom)
 	REFERENCES Room (idRoom)
 );

