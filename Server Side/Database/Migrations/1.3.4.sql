ALTER TABLE `players`
	ADD COLUMN `seglevel` ENUM('0','1','2','3') NOT NULL DEFAULT '0' AFTER `uclevel`;
