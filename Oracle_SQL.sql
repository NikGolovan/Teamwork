create table REALISATEURS(
      CODREAL char(6),
      NOMREAL char(60),
      NATIONREAL char(20),
      DNAISSREAL date,
      DDECREAL date,
      constraint PK_CODREAL primary key (CODREAL),
      constraint MIN_DATES check (DNAISSREAL < DDECREAL)
    );

create table FILMS(
      CODFILM char(6),
      TITREFILM char(60),
      DATESORTIE date,
      DUREE number(5),
      BUDGET number(15,2),
      CODREAL char(6),
      constraint PK_CODFILM primary key (CODFILM),
      constraint FK_CODREAL foreign key (CODREAL) references REALISATEURS,
      constraint MIN_BUDGET check (BUDGET > 0),
      constraint MIN_DUREE check (DUREE > 0)
    );

create table ACTEURS(
      CODACT char(6),
      NOMACT char(30),
      PRENOMACT char(30),
      NATIONACT char(30),
      SEXE char(1),
      DNAISSACT date,
      DDECACT date,
      constraint PK_CODACT primary key (CODACT),
      constraint MIN_DATESA check (DNAISSACT < DDECACT),
      constraint MIN_SEXE check (SEXE = 'F' OR SEXE = 'M')
    );

create table JOUENT(
      CODFILM char(6),
      NACT char(6),
      NOMPERS char(30),
      constraint PK_JOUENT primary key (CODFILM , NACT)
    );

#Faire attention a lordre de insertion des tables, ici REALISATEURS doit etre cree avant tout, parce aue qpres elle est referencé
#Absence de virgule (FILMS) pour le nombre entier et absence de valeurs pour acteurs
#SELECT TABLE-NAME FROM tables;
#DESC NOMTABLE;
#SELECT CONSTRAINT_NAME FROM USER_CONSTRAINTS;

insert into REALISATEURS values ('CAM043', 'James Cameron', 'Canadien', '16/08/1954', null);
insert into FILMS values('F011', 'Avatar', '16/12/2009', 162, 500000000, 'CAM043');
insert into FILMS values ('F012', 'Aliens, le retour', '08/10/1986', 137, 325000, 'CAM043');
insert into ACTEURS values('SIG32', 'Weaver', 'Sigourney', 'américaine', 'F', '08/10/1949', null);
insert into ACTEURS values('SIG33', 'Biehn', 'Michael', 'américain', 'M', '31/07/1956', null);
insert into JOUENT values ('F012', 'SIG32', 'Lieutenant Ellen Ripley');
insert into JOUENT values('F011','SIG32','Grace Augustine');
insert into JOUENT values('F011','SAM01','Jack Sully');
insert into JOUENT values('F011','SIG33','Médecin');

insert into realisateurs values('R0002','Scott','anglais','30/11/1937',NULL, NULL);
insert into realisateurs values('R0003','Mendes','anglais','01/08/1965',NULL, NULL);
insert into realisateurs values('R0004','Negulesco','américain','26/02/1900','18/07/1993');
insert into realisateurs values('R0005','Canet','français','10/04/1973',NULL, NULL);
insert into realisateurs values('R0006','Berry','français','01/07/1934','12/01/2009', NULL);
insert into realisateurs values('R0007','Boyle','anglais','20/10/1956',NULL, NULL);
insert into realisateurs values('R0008','Lellouche','français','05/07/1972',NULL, NULL);

insert into films values('F002', 'Aliens, le retour', '08/10/1986', 137, 123456,'R0001', NULL);
insert into films values('F003', 'Alien, le huitième passager', '12/09/1979',116, 32122,'R0002', NULL);
insert into films values('F004', 'Titanic', '07/07/1998', 194, 67889008, 'R0001', NULL);
insert into films values('F005', 'Les noces rebelles', '21/01/2009',125, 563215,'R0003', NULL);
insert into films values('F006', 'Titanic', NULL, 98, 12309,'R0004', NULL);
insert into films values('F007', 'Les petits mouchoirs', '20/10/2010', 154, 8765432, 'R0005', NULL);
insert into films values('F008', 'Ensemble c''est tout', '21/03/2007', 97, 542987, 'R0006', NULL);
insert into films values('F009', 'La plage', '16/02/2000', 119, 296306, 'R0007', NULL);
insert into films values('F010', 'Narco', '01/12/2004', 105, 328764, 'R0008', NULL);

alter table realisateurs add (PRENOMREAL char(60));
UPDATE FILMS SET BUDGET = BUDGET+BUDGET*(10/100) WHERE CODFILM='F012';
alter table FILMS add (CATEGORIE VARCHAR(20));

# TD 5
1) select *
   from FILMS
   where BUDGET > 1000000;
2) select *
   from ACTEURS
   where SEXE = 'F'
     and NATIONACT = 'américaine';
3) select NOMACT, PRENOMACT
   from ACTEURS
   where NATIONACT = 'français'
      or NATIONACT = 'belge';
4) select TITREFILM
   from FILMS, REALISATEURS
   where FILMS.CODREAL = REALISATEURS.CODREAL
     and NOMREAL = 'Cameron'
     and PRENOMREAL = 'James';
5) select NOMACT, PRENOMACT
   from ACTEURS A, FILMS F, JOUENT J
   where F.CODFILM = J.CODFILM
     and J.NACT = A.CODACT
     and F.TITREFILM = 'La plage';
6) select A1.NOMACT, A1.PRENOMACT, A1.DNAISSACT
   from ACTEURS A1, ACTEURS A2
   where extract(year from A1.DNAISSACT) = extract(year from A2.DNAISSACT)
     and A2.NOMACT = 'Dujardin'
     and A2.PRENOMACT = 'Jean';
7) select NOMREAL, PRENOMREAL
   from REALISATEURS R, FILMS F
   where DATESORTIE > DDECREAL
     and TITREFILM = 'Ensemble c''est tout';
8) select distinct TITREFILM, NOMREAL
   from FILMS F, REALISATEURS R, JOUENT J
   where F.CODREAL = R.CODREAL
     and J.CODFILM = F.CODFILM
     and NOMPERS = 'Lieutenant Ellen Ripley';
9) select NOMREAL
   from REALISATEURS
   where CODREAL
    incount(distinct NACT)
  (select CODREAL
   from REALISATEURS
   MINUS
   select CODREAL
   from FILMS F, ACTEURS A, JOUENT J
   where A.CODACT = J.NAC
     and J.CODFILM = F.CODFILM
     and (A.NATIONACT = 'américain' or A.NATIONACT = 'américaine')
   );
10) select distinct R.CODREAL, NOMREAL, PRENOMREAL
    from REALISATEURS R, FILMS F, ACTEURS A, JOUENT J
    where R.CODREAL = F.CODREAL
      and A.CODACT = J.NACT
      and J.CODFILM = F.CODFILM
      and A.NATIONACT != 'américain'
      and A.NATIONACT != 'américaine';
11) select TITREFILM, DATESORTIE, BUDGET
    from FILMS F, REALISATEURS R
    where F.CODREAL = R.CODREAL
      and DATESORTIE - DNAISSREAL < 40 * 365;

# TD 6
# Question 3
a) select distinct NATIONACT
   from ACTEURS;
b) select NOMREAL, PRENOMREAL
   from REALISATEURS
   where NATIONREAL = 'américain'
     and CODREAL not in (select CODREAL
                         from JOUENT J, ACTEURS A, FILMS F
                         where J.NACT = A.CODACT
                           and F.CODFILM = J.CODFILM
                           and NATIONACT = 'français');

# TD 7
1) select count(CODFILM)
   from FILMS;
2) select count(distinct F.CODFILM)
   from FILMS F, REALISATEURS R, ACTEURS A, JOUENT J
   where F.CODREAL = R.CODREAL
     and F.CODFILM = J.CODFILM
     and A.CODACT = J.NACT
     and R.NOMREAL = 'Cameron'
     and A.SEXE = 'F'
     and extract(year from A.DNAISSACT) > '1970';
3) select count(distinct NACT)
   from FILMS F, REALISATEURS R, JOUENT J
   where F.CODREAL = R.CODREAL
     and F.CODFILM = J.CODFILM
     and R.NOMREAL = 'Cameron';
4) select max(BUDGET)
   from FILMS;
5) select TITREFILM
   from FILMS
   where BUDGET = (select max(BUDGET)
                   from FILMS);
6) select sum(BUDGET)
   from FILMS F, REALISATEURS R
   where F.CODREAL = R.CODREAL
     and R.NOMREAL = 'Cameron';

# Utilisation du GROUP BY
1) select R.CODREAL, NOMREAL, count(F.CODFILM)
   from REALISATEURS R, FILMS F
   where R.CODREAL = F.CODREAL
   group by R.CODREAL, NOMREAL;
2) select NOMREAL, NATIONREAL, count(distinct NACT)
   from REALISATEURS R, FILMS F, JOUENT J
   where F.CODREAL = R.CODREAL
     and F.CODFILM = J.CODFILM
   group by R.CODREAL, R.NOMREAL, R.NATIONREAL;
3) select NOMREAL, NATIONREAL, sum(BUDGET)
   from REALISATEURS R, FILMS F
   where R.CODREAL = F.CODREAL
     and CATEGORIE = 'science fiction'
   group by R.CODREAL, NOMREAL, NATIONREAL;
4) select NOMREAL, NATIONREAL, count(F.CODFILM)
   from REALISATEURS R, FILMS F
   where R.CODREAL = F.CODREAL
   group by R.CODREAL, NOMREAL, NATIONREAL, CATEGORIE;
   
# Utilisation du having
1) select NOMACT, PRENOMACT
   from ACTEURS A, JOUENT J
   where J.NACT = A.CODACT
      and NATIONACT = 'américain'
      or NATIONACT = 'américaine'
   group by A.CODACT, NOMACT, PRENOMACT
   having count(J.CODFILM) > 2;
2) select NOMREAL, NATIONREAL
   from REALISATEURS R, FILMS F
   where R.CODREAL = F.CODREAL
     and CATEGORIE = 'science fiction'
   group by R.CODREAL, NOMREAL, NATIONREAL
   having sum(BUDGET) > 1000000;
3) select NOMACT, PRENOMACT
   from ACTEURS A, JOUENT J
   where J.NACT = A.CODACT
   group by CODACT, NOMACT, PRENOMACT
   having count() > (select count(CODFILM)
                     from ACTEURS A, JOUENT J
                     where A.CODACT = J.NACT
                       and NOMACT = 'Winslet'
                       and PRENOMACT = 'Kate');
5) select CODACT, PRENOMACT
   from ACTEURS A, JOUENT J,
   where A.CODACT = J.CODACT
   group by A.CODACT, NOMACT, PRENOMACT
   having count(CODFILM) = (select max(count(CODFILM))
                            from JOUENT
                            group by NACT);
