ALTER TABLE `houses`
	ADD COLUMN `upkeepDaysLeft` INT NULL DEFAULT '30' AFTER `upgrades`;

DELIMITER //
CREATE PROCEDURE `decreaseHousingUpKeepDays`()
BEGIN
	UPDATE `houses` SET `upkeepDaysLeft` = `upkeepDaysLeft` - 1 WHERE `upkeepDaysLeft` > 0;
END//
DELIMITER ;

ALTER TABLE `mail`
	ADD COLUMN `daysUntilExpiry` INT NULL DEFAULT NULL AFTER `data`;

DROP PROCEDURE `deleteOldMail`;

DELIMITER //
CREATE PROCEDURE `deleteOldMail`()
BEGIN
	DELETE FROM mail WHERE `claimed`='1' OR `daysUntilExpiry` IS NOT NULL AND `daysUntilExpiry` <= 0;
END//
DELIMITER ;

DELIMITER //
CREATE PROCEDURE `decreaseMailDaysUntilExpiry`()
BEGIN
	UPDATE `mail` SET `daysUntilExpiry` = `daysUntilExpiry` - 1 WHERE `daysUntilExpiry` IS NOT NULL AND `daysUntilExpiry` > 0;
END//
DELIMITER ;

UPDATE `mail` SET `daysUntilExpiry` = 14  WHERE `type` != 'Money' AND `daysUntilExpiry` IS NULL;