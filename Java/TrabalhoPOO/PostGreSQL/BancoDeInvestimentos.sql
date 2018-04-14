-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2018-04-13 23:02:30.053

-- tables
-- Table: Aplicacao
CREATE TABLE Aplicacao (
    DESCRICAO VARCHAR(50)  NOT NULL,
    CODIGO VARCHAR(5)  NOT NULL,
    RISCO real  NOT NULL,
    RENDIMENTO real  NOT NULL,
    TIPO int  NOT NULL,
    CONSTRAINT Aplicacao_pk PRIMARY KEY (CODIGO)
);

-- Table: CarteiraInvestimentos
CREATE TABLE CarteiraInvestimentos (
    AplicacaoPrimariaCODIGO VARCHAR(5)  NOT NULL,
    Carteiracodigo VARCHAR(5)  NOT NULL,
    CONSTRAINT Carteiracodigo_pk PRIMARY KEY (Carteiracodigo),
    fatia real  NOT NULL
);

-- foreign keys
-- Reference: CarteiraInvestimentos_AplicacaoPrimaria  (table: CarteiraInvestimentos)
ALTER TABLE CarteiraInvestimentos ADD CONSTRAINT CarteiraInvestimentos_AplicacaoPrimaria 
    FOREIGN KEY (Carteiracodigo)
    REFERENCES Aplicacao (CODIGO)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- Reference: CarteiraInvestimentos_AplicacaoPrimaria  (table: CarteiraInvestimentos)
--ALTER TABLE CarteiraInvestimentos ADD CONSTRAINT CarteiraInvestimentos_AplicacaoPrimaria 
    --FOREIGN KEY (AplicacaoPrimariaCODIGO)
    --REFERENCES Aplicacao (CODIGO)  
    --NOT DEFERRABLE 
    --INITIALLY IMMEDIATE
--;

-- End of file.

select*
from aplicacao

select*
from CarteiraInvestimentos 
