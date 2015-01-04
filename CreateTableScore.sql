CREATE TABLE `gamedb`.`score` (
    `idScore` INT NOT NULL AUTO_INCREMENT,
    `valScore` INT NOT NULL,
    `date` VARCHAR(45) NOT NULL,
    PRIMARY KEY (`idScore`)
)  COMMENT='Score du joueur fait durant une partie'score;