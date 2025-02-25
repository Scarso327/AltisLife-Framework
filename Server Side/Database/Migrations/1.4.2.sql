ALTER TABLE `groups`
	CHANGE COLUMN `level` `level` INT NULL DEFAULT '1' AFTER `name`;

UPDATE `groups` SET `groups`.`level` = `groups`.`level` + 1 WHERE `groups`.`level` != 5