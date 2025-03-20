ALTER TABLE `players`
	ADD COLUMN `dmscomlevel` ENUM('0','1','2','3') NOT NULL DEFAULT '0' AFTER `dmslevel`,
	ADD COLUMN `dmshammerlevel` ENUM('0','1','2','3') NOT NULL DEFAULT '0' AFTER `dmscomlevel`,
	ADD COLUMN `dmsairlevel` ENUM('0','1','2','3') NOT NULL DEFAULT '0' AFTER `dmshammerlevel`;
