ALTER TABLE `vehicles`
	ADD COLUMN `upgrades` TEXT NOT NULL AFTER `texture`;

UPDATE `vehicles` SET `upgrades` = '"[]"';