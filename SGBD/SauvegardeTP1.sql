/*
--Q2.2-1-a
ALTER TABLE COUNTRY
    add constraint fkCountryProvince 
    foreign key (Province,code)
    references Province(name,country);
ALTER TABLE Province
    add constraint fkProvinceCountry
    foreign key (Country)
    references Country(code);
ALTER TABLE COUNTRY
    add constraint fkCountryCapital
    foreign key (Capital,province,code)
    references City(name,province,country);
ALTER TABLE City
    add constraint fkCityProvince
    foreign key (Province,country)
    references Province(name,country);
    
    --contrainte impossible car pb dans bd
ALTER TABLE Province
    add constraint fkProvinceCapital
    foreign key (Capital,country,name)
    references City(name,country,province);
*/
/*
    --Q2.2-1-b
ALTER TABLE COUNTRY
    add constraint uniqueCountryCode 
    unique (name);
*/
/*
     --Q2.2-1-c
ALTER TABLE Borders
    add Constraint checkBorderLength
    check (Length>=0.);
ALTER TABLE Country
    add Constraint checkCountryName
    check (name is not null);
ALTER TABLE Language
    add Constraint checkLanguagePercentage
    check (percentage<=100. and percentage >=0.);
*/
/*
     --Q2.2-3
     --les contraintes circulaires limite la modification :
     -- solution 1 : désactivé momentanément les contraintes
     -- solution 2 : faire tout les insert avec null dans les attributs non clefs puis modifié ces attributs (marche pas si contraintes sur les nulls) 
select * from country where name ='Atlantis';
select * from country where code ='AT';
select * from country where code ='TIS';
INSERT INTO country VALUES ('Atlan','AT',null,null,200,100000);
INSERT INTO country VALUES ('Tis','TIS',null,null,300,100000);
*/
/*
     --Q2.3-1
select name from country order by name asc;
*/
/*
     --Q2.3-2
select O.abbreviation,count(*) as nbMembre
from Organization O,is_member M
WHERE O.abbreviation = M.ORGANIZATION
group by O.abbreviation;

select max(O.NAME)
from Organization O,is_member M
WHERE O.abbreviation = M.ORGANIZATION
group by O.abbreviation
having count(*) = (
    select max(count(*)) as nbMembre
    from Organization O,is_member M
    WHERE O.abbreviation = M.ORGANIZATION
    group by O.abbreviation
    );
*/
/*
     --Q2.3-3
select country, sum(population) as citadins
     from City
     group by country;

with popCitadine as(
     select country, sum(population) as citadins
     from City
     group by country
)
select C.code, P.citadins/C.population as tauxCitadins
from popCitadine P, country C
where P.country = C.code;
*/
/*
     --Q2.3-11
with bordersPerCountry (country,length) as(
    select C.CODE, sum(B.length)
    from Borders B, Country C
    where C.CODE=B.country1 OR C.CODE=B.country2
    group by C.CODE
)

select C.Name, sum(B.length) as frontiere
from Continent C, ENCOMPASSES E , bordersPerCountry B
where C.Name=E.continent AND E.country=B.country
group by C.Name;
*/
/*
    --Q2.3-17. Écrire en PL/SQL une solution qui prend en paramètre un code de pays et qui affiche son nom ainsi que le nombre de pays frontaliers.
    --ATTENTION select ... into ... MIEUX avec des cursors

create or replace function nbPaysVoisins1
(
    CodeCountry$ in Country.code%type
)
return number
is
    NameCountry$ Country.name%type;
    nbVoisins$ number;
begin
    select max(C.name), count(*) into NameCountry$, nbVoisins$
    from Borders B, Country C
    where (C.CODE=B.country1 OR C.CODE=B.country2) and C.code=CodeCountry$;
    return nbVoisins$;
end;
/

create or replace function getNameFromCountryCode
(
    CodeCountry$ in Country.code%type
)
return country.name%type
is
    
    name$ varchar(32);
begin
    select name into name$ from country where code =CodeCountry$;
    return name$;
end;
/

select getNameFromCountryCode('D') from dual;
select nbPaysVoisins1('F') from dual;
*/
/*
--question 19
select country
from (  select independence, country
        from politics
        )
where to_char(independence,'D') = 1;
*/
/*
--question 20
CREATE OR REPLACE PROCEDURE INSERT_COUNTRY 
(
  NAME$ IN COUNTRY.NAME%TYPE 
, CODE$ IN COUNTRY.CODE%TYPE 
, CAPITAL$ IN COUNTRY.CAPITAL%TYPE 
, PROVINCE$ IN COUNTRY.PROVINCE%TYPE 
, AREA$ IN COUNTRY.AREA%TYPE 
, POPULATION$ IN COUNTRY.POPULATION%TYPE 
)

IS

  MonExeption EXCEPTION;

BEGIN

  RAISE MonExeption;
    INSERT INTO country VALUES (NAME$, CODE$, CAPITAL$, PROVINCE$, AREA$, POPULATION$);
  
  EXCEPTION
    WHEN MonExeption THEN 
    raise_application_error(-20001,'ImpossibleDinsererLeTuple');
END INSERT_COUNTRY;

EXECUTE INSERT_COUNTRY('INSALI','INS','GASTONB','IF',4000,7000);
*/
/*
-Q2.4
select 'grant select on '||table_name||' to fmutin;' as SEL from user_tables;
select 'grant update on '||tDéclencheurs
able_name||' to fmutin;' as MAJ from user_tables;
-- avec ctrl+F5 dans la sortie du script
*/
/*
-- Q2.5 - 1
CREATE OR REPLACE TRIGGER INDEPENDENCE_BEFORE_TODAY 
AFTER INSERT OR UPDATE ON POLITICS
FOR EACH ROW

BEGIN
  IF (:NEW.Independence > SYSDATE)
  THEN RAISE_APPLICATION_ERROR(-20004,'La date d indépendance doit être inférieure à la date du jour');
  END IF;
END;

update politics set independence='28 11 2018' where country = 'AL';
*/
/*
-- Q2.5 - 2
CREATE OR REPLACE TRIGGER VERIFCOUNTRYALPHA 
BEFORE INSERT OR UPDATE ON Country
FOR EACH ROW
BEGIN
  FOR i IN 1..LENGTH(:NEW.code) LOOP
    IF (ASCII( SUBSTR(:NEW.code,i,1))>90 OR ASCII( SUBSTR(:NEW.code,i,1))<65)THEN
      RAISE_APPLICATION_ERROR(-20054,'Le code entré est non validé par la street #MAJ #alpha');
    END IF ;
  END LOOP ;
END;

update country set code='28' where code = 'AL';
*/

/*
-- Q2.5 - 2
ALTER TABLE country ADD border_length number(7);

--
create or replace procedure update_length_border_country_1
(
  country$ in country.code%TYPE
)

is 
  length_border$ country.BORDER_LENGTH%TYPE;
begin
    select sum(B.length) 
    into length_border$
    from Borders B, Country C
    where country$=B.country1 
       OR country$=B.country2
    ;
    
    update COUNTRY 
    set BORDER_LENGTH = length_border$
    where code = country$;
    
end;

--
create or replace procedure genere_length_border
as 
  CURSOR pays$ IS
    select code
    from country;
  length_border$ country.BORDER_LENGTH%TYPE;
begin 
  for country$ in pays$
  loop
    update_length_border_country_1(country$.code);
  end loop;
end genere_length_border;

EXECUTE genere_length_border;


*/