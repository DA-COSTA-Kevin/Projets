--
-- Drop tables
--

DROP TABLE IF EXISTS client CASCADE;
DROP TABLE IF EXISTS formule CASCADE;
DROP TABLE IF EXISTS groupe CASCADE;
DROP TABLE IF EXISTS preference CASCADE;
DROP TABLE IF EXISTS chambre CASCADE;
DROP TABLE IF EXISTS reservation CASCADE;
DROP TABLE IF EXISTS compte CASCADE;

--
-- Create table client
--

CREATE TABLE client (
	id_client serial PRIMARY KEY,
	 nom varchar(25) NOT NULL,
	 prenom varchar(25) NOT NULL,
	 date_n date,
	 adresse varchar(40) NOT NULL,
	 telephone char(10) NOT NULL,
	 taille int NOT NULL,
	 poids int NOT NULL,
	 pointure int NOT NULL,
	 niv_ski varchar(25) NOT NULL
);

--
-- Create table compte
--

CREATE TABLE compte (
	id serial PRIMARY KEY,
	ndc varchar(25),
	mdp varchar(25),
	rang varchar(25)
);


--
-- Create table formule
--

CREATE TABLE formule(
	id_formule int PRIMARY KEY,
	 nom_formule varchar(25) NOT NULL,
	 tarif int NOT NULL
);

--
-- Create table groupe
--

CREATE TABLE groupe(
	id_gp serial PRIMARY KEY,
	 nom_gp varchar(25) NOT NULL,
	 type_gp char(1) NOT NULL
);

--
-- Create table chambre
--

CREATE TABLE chambre(
	num_chambre int PRIMARY KEY,
	 capacité int NOT NULL,
	 etage int NOT NULL,
	 superficie int NOT NULL,
	 vue varchar(50) NOT NULL
);

--
-- Create table reservation
--

CREATE TABLE reservation(
	id_reservation serial PRIMARY KEY,
	 date_debut date NOT NULL,
	 date_fin date NOT NULL,
	 niv_pref int,
	 id_client int,
	 id_formule int,
	 id_gp int,
	 num_chambre int
);

--
-- Create table preference
--

CREATE TABLE preference(
	niv_pref int PRIMARY KEY,
	 nom_pref varchar(25)
);


--admin

INSERT INTO compte(ndc, mdp, rang) VALUES ('Administrateur', 'GustaveEiffel', 'Administrateur');

-- Data base for client

/*INSERT INTO client VALUES(1, 'Chen','Steve','40 avenue 75000',0168526595, 181, 61,43,'non skieur');
INSERT INTO client VALUES(2, 'Da Costa','Morgane','21 rue du puit 77129',0168526535, 160, 55,39,'non skieur');
INSERT INTO client VALUES(3, 'Chen','Emilie','40 avenue 75000',0168526595, 163, 53,37,'non skieur');
INSERT INTO client VALUES(4, 'Da Costa','Kevin','21 rue du puit 77129',0168526535, 181, 53,43,'non skieur');
INSERT INTO client VALUES(9999, 'beta','testeur','40 avenue 75000',0168526595, 181, 61,43,'non skieur');
*/
-- Data base for formule

INSERT INTO formule VALUES(0, 'En attente', 0);
INSERT INTO formule VALUES(1, 'Skieur', 510);
INSERT INTO formule VALUES(2, 'non Skieur', 420);
INSERT INTO formule VALUES(3, 'enfant skieur', 408);
INSERT INTO formule VALUES(4, 'enfant non skieur', 336);
INSERT INTO formule VALUES(5, 'bébé', 0);

/*
-- Data base for groupe

INSERT INTO groupe VALUES(1, 'jpp','G');
INSERT INTO groupe VALUES(2, 'soloQ','F');
*/

-- Data for chambre

INSERT INTO chambre VALUES(0, 0, 0, 0, 'default');
INSERT INTO chambre VALUES(13, 6, 1, 120, 'sur parking');
INSERT INTO chambre VALUES(133, 2, 2, 120, 'sur parking');
INSERT INTO chambre VALUES(13, 6, 3, 120, 'balcon');
INSERT INTO chambre VALUES(133, 2, 4, 120, 'balcon');

/*
-- Data base for reservation

INSERT INTO reservation VALUES(1, '2019-11-15', '2019-11-20', 1, 1, 2, 1, 13);
INSERT INTO reservation VALUES(2, '2019-11-15', '2019-11-20', 1, 2, 2, 1, 13);
INSERT INTO reservation VALUES(3, '2019-11-15', '2019-11-20', 0, 3, 1, 2, 13);
INSERT INTO reservation VALUES(4, '2019-11-15', '2019-11-20', 0, 9999, 1, 2, 13);
INSERT INTO reservation VALUES(5, '2019-11-15', '2019-11-20', 1, 4, 2, 1, 133);

*/

-- Data base for preference

INSERT INTO preference VALUES (0, 'rien');
INSERT INTO preference VALUES (1, 'imperatif');
INSERT INTO preference VALUES (2, 'souhaitable');
INSERT INTO preference VALUES (3, 'pas souhaitable');
INSERT INTO preference VALUES (4, 'interdit');


--
-- Name: reservation_id_client_fkey ; Type: FK CONSTRAINT;
--

ALTER TABLE reservation
    ADD CONSTRAINT reservation_id_client_fkey FOREIGN KEY (id_client) REFERENCES client(id_client);

--
-- Name: reservation_id_formule_fkey ; Type: FK CONSTRAINT;
--

ALTER TABLE reservation
    ADD CONSTRAINT reservation_id_formule_fkey FOREIGN KEY (id_formule) REFERENCES formule(id_formule);

--
-- Name: reservation_id_gp_fkey ; Type: FK CONSTRAINT;
--

ALTER TABLE reservation
    ADD CONSTRAINT reservation_id_gp_fkey FOREIGN KEY (id_gp) REFERENCES groupe(id_gp);

--
-- Name: reservation_num_chambre_fkey ; Type: FK CONSTRAINT;
--

ALTER TABLE reservation
    ADD CONSTRAINT reservation_num_chambre_fkey FOREIGN kEY (num_chambre) REFERENCES chambre(num_chambre);

--
-- Name: reservation_num_chambre_fkey ; Type: FK CONSTRAINT;
--

ALTER TABLE reservation
    ADD CONSTRAINT reservation_niv_pref_fkey FOREIGN KEY (niv_pref) REFERENCES preference(niv_pref);
