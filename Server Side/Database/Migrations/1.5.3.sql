ALTER TABLE `warrants`
ADD COLUMN `faction` VARCHAR(10) NOT NULL COLLATE 'utf8mb4_general_ci' AFTER `pid`,
ADD INDEX `faction` (`faction`);

UPDATE `warrants`
SET
	`faction` = 'Civilian';

UPDATE `players`
SET
	`playtime` = '0';

ALTER TABLE `players` CHANGE COLUMN `cop_wounded` `cop_wounded` TINYINT NOT NULL DEFAULT '0' AFTER `cop_blacklisted`,
CHANGE COLUMN `playtime` `cop_playtime` INT NOT NULL DEFAULT (0) COLLATE 'utf8mb4_general_ci' AFTER `cop_wounded`,
CHANGE COLUMN `med_wounded` `med_wounded` TINYINT NOT NULL DEFAULT '0' AFTER `med_blacklisted`,
ADD COLUMN `med_playtime` INT NOT NULL DEFAULT (0) AFTER `med_wounded`,
CHANGE COLUMN `hato_wounded` `hato_wounded` TINYINT NOT NULL DEFAULT '0' AFTER `hato_blacklisted`,
ADD COLUMN `hato_playtime` INT NOT NULL DEFAULT (0) AFTER `hato_wounded`,
CHANGE COLUMN `prison_timer` `prison_timer` INT NOT NULL DEFAULT '0' AFTER `arrested`,
CHANGE COLUMN `civ_wounded` `civ_wounded` TINYINT NOT NULL DEFAULT '0' AFTER `prison_timer`,
ADD COLUMN `civ_playtime` INT NOT NULL DEFAULT (0) AFTER `civ_wounded`,
ADD COLUMN `dmslevel` ENUM('0','1','2','3','4','5','6','7','8','9','10') NOT NULL DEFAULT '0' AFTER `civ_playtime`,
ADD COLUMN `dms_licenses` TEXT NOT NULL COLLATE 'utf8mb4_general_ci' AFTER `civ_playtime`,
ADD COLUMN `dms_perks` TEXT NOT NULL COLLATE 'utf8mb4_general_ci' AFTER `dms_licenses`,
ADD COLUMN `dms_gear` TEXT NOT NULL COLLATE 'utf8mb4_general_ci' AFTER `dms_perks`,
ADD COLUMN `dms_stats` VARCHAR(25) NOT NULL DEFAULT '"[100,100,0]"' COLLATE 'utf8mb4_general_ci' AFTER `dms_gear`,
ADD COLUMN `dms_daily_tasks` TEXT NOT NULL COLLATE 'utf8mb4_general_ci' AFTER `dms_stats`,
ADD COLUMN `dms_weekly_tasks` TEXT NOT NULL COLLATE 'utf8mb4_general_ci' AFTER `dms_daily_tasks`,
ADD COLUMN `dms_arrested` TINYINT NOT NULL DEFAULT '0' AFTER `dms_weekly_tasks`,
ADD COLUMN `dms_prison_timer` INT NOT NULL DEFAULT '0' AFTER `dms_arrested`,
ADD COLUMN `dms_wounded` TINYINT NOT NULL DEFAULT '0' AFTER `dms_prison_timer`,
ADD COLUMN `dms_playtime` INT NOT NULL DEFAULT (0) AFTER `dms_wounded`;

UPDATE `players`
SET
	`dms_licenses` = '"[]"',
	`dms_perks` = '"[]"',
	`dms_gear` = '"[]"',
	`dms_stats` = '"[]"',
	`dms_daily_tasks` = '"[]"',
	`dms_weekly_tasks` = '"[]"';

ALTER TABLE `players` CHANGE COLUMN `arrested` `civ_arrested` TINYINT NOT NULL DEFAULT '0' AFTER `civ_weekly_tasks`,
CHANGE COLUMN `prison_timer` `civ_prison_timer` INT NOT NULL DEFAULT '0' AFTER `civ_arrested`;

CREATE TABLE `players_playtime` (
	`id` INT NOT NULL AUTO_INCREMENT,
	`pid` VARCHAR(17) NOT NULL COLLATE 'utf8mb4_general_ci',
	`cop_playtime` INT NOT NULL DEFAULT '0',
	`med_playtime` INT NOT NULL DEFAULT '0',
	`hato_playtime` INT NOT NULL DEFAULT '0',
	`civ_playtime` INT NOT NULL DEFAULT '0',
	`dms_playtime` INT NOT NULL DEFAULT '0',
	`when` TIMESTAMP NOT NULL DEFAULT (now()),
	PRIMARY KEY (`id`) USING BTREE,
	INDEX `FK_players_playtime` (`pid`) USING BTREE,
	CONSTRAINT `FK_players_playtime` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON UPDATE NO ACTION ON DELETE CASCADE
)
COLLATE='utf8mb4_general_ci'
ENGINE=InnoDB
;

DELIMITER //
CREATE PROCEDURE `processPlaytime`()
BEGIN
	INSERT INTO `players_playtime` (`pid`, `cop_playtime`, `med_playtime`, `hato_playtime`, `civ_playtime`, `dms_playtime`)
		SELECT `pid`, `cop_playtime`, `med_playtime`, `hato_playtime`, `civ_playtime`, `dms_playtime` FROM `players`;
END//
DELIMITER ;