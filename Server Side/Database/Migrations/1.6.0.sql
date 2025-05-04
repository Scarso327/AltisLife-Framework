ALTER TABLE `houses`
	ADD COLUMN `upkeepDaysLeft` INT NULL DEFAULT '30' AFTER `upgrades`;

DELIMITER //
CREATE PROCEDURE `decreaseHousingUpKeepDays`()
BEGIN
	UPDATE `houses` SET `upkeepDaysLeft` = `upkeepDaysLeft` - 1 WHERE `upkeepDaysLeft` > 0;
END//
DELIMITER ;