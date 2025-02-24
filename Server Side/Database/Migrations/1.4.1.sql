INSERT INTO `settings` (`setting`, `value`) VALUES ('NextSeason', '2025-3-12');
INSERT INTO `settings` (`setting`, `value`) VALUES ('Season', '0');

ALTER TABLE `logs`
	CHANGE COLUMN `content` `content` TEXT NULL COLLATE 'utf8mb4_general_ci' AFTER `pid`,
	ADD COLUMN `jsonContent` JSON NULL AFTER `content`;
	ADD COLUMN `season` INT NOT NULL DEFAULT '0' AFTER `jsonContent`;
