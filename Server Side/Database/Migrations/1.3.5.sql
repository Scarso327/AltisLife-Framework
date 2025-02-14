USE `altislife`;

ALTER TABLE `players`
	ADD COLUMN `cop_wounded` TINYINT NOT NULL DEFAULT '0' AFTER `arrested`,
	ADD COLUMN `med_wounded` TINYINT NOT NULL DEFAULT '0' AFTER `cop_wounded`,
	ADD COLUMN `hato_wounded` TINYINT NOT NULL DEFAULT '0' AFTER `med_wounded`,
	ADD COLUMN `civ_wounded` TINYINT NOT NULL DEFAULT '0' AFTER `hato_wounded`;

DELIMITER //
CREATE PROCEDURE `resetWoundedPlayers`()
BEGIN
	UPDATE `players` SET `cop_wounded`='0', `med_wounded`='0', `hato_wounded`='0', `civ_wounded`='0';
END//
DELIMITER ;