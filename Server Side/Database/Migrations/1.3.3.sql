ALTER TABLE `vehicles`
	ADD COLUMN `ignoreCondtions` TINYINT NOT NULL DEFAULT (0) AFTER `upgrades`;

UPDATE `vehicles` SET `ignoreCondtions` = 0;