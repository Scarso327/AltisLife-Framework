ALTER TABLE `vehicles`
	ADD COLUMN `upgrades` TEXT NOT NULL AFTER `texture`;

UPDATE `vehicles` SET `upgrades` = '"[]"';

UPDATE `players` SET `bankacc` = 150000  WHERE `bankacc` = 125000 AND `cash` = 0;