ALTER TABLE `players`
	CHANGE COLUMN `daily_tasks` `cop_daily_tasks` TEXT NOT NULL DEFAULT '"[]"' COLLATE 'utf8mb4_general_ci' AFTER `cop_stats`,
	CHANGE COLUMN `weekly_tasks` `cop_weekly_tasks` TEXT NOT NULL DEFAULT '"[]"' COLLATE 'utf8mb4_general_ci' AFTER `cop_daily_tasks`,
	ADD COLUMN `med_daily_tasks` TEXT NOT NULL DEFAULT '"[]"' AFTER `med_stats`,
	ADD COLUMN `med_weekly_tasks` TEXT NOT NULL DEFAULT '"[]"' AFTER `med_daily_tasks`,
	ADD COLUMN `hato_daily_tasks` TEXT NOT NULL DEFAULT '"[]"' AFTER `hato_stats`,
	ADD COLUMN `hato_weekly_tasks` TEXT NOT NULL DEFAULT '"[]"' AFTER `hato_daily_tasks`,
	CHANGE COLUMN `civ_stats` `civ_stats` VARCHAR(25) NOT NULL DEFAULT '"[100,100,0]"' COLLATE 'utf8mb4_general_ci' AFTER `civ_gear`,
	ADD COLUMN `civ_daily_tasks` TEXT NOT NULL DEFAULT '"[]"' AFTER `civ_stats`,
	ADD COLUMN `civ_weekly_tasks` TEXT NOT NULL DEFAULT '"[]"' AFTER `civ_daily_tasks`;

-- Reset the altered columns
UPDATE players SET cop_daily_tasks = '"[]"';
UPDATE players SET cop_weekly_tasks = '"[]"';

CREATE TABLE `community_goals` (
	`id` INT(11) NOT NULL AUTO_INCREMENT,
	`goal_cfg` VARCHAR(50) NOT NULL COLLATE 'utf8mb4_general_ci',
	`end_date` DATE NOT NULL,
	PRIMARY KEY (`id`) USING BTREE
)
COLLATE='utf8mb4_general_ci'
ENGINE=InnoDB
AUTO_INCREMENT=0
;

CREATE TABLE `community_goal_contributions` (
	`id` INT(11) NOT NULL AUTO_INCREMENT,
	`pid` VARCHAR(17) NOT NULL COLLATE 'utf8mb4_general_ci',
	`goalId` INT(11) NOT NULL DEFAULT '0',
	`contribution` INT(11) NOT NULL DEFAULT '0',
	PRIMARY KEY (`id`) USING BTREE,
	UNIQUE INDEX `pid` (`pid`, `goalId`) USING BTREE,
	INDEX `FK_community_goal_contributions_community_goals` (`goalId`) USING BTREE,
	CONSTRAINT `FK_community_goal_contributions_community_goals` FOREIGN KEY (`goalId`) REFERENCES `community_goals` (`id`) ON UPDATE NO ACTION ON DELETE CASCADE,
	CONSTRAINT `FK_community_goal_contributions_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON UPDATE NO ACTION ON DELETE CASCADE
)
COLLATE='utf8mb4_general_ci'
ENGINE=InnoDB
AUTO_INCREMENT=0
;

DELIMITER //
CREATE DEFINER=CURRENT_USER PROCEDURE `deleteOldCommunityGoals`()
BEGIN
	DELETE FROM `community_goals` WHERE `end_date` <= CURDATE();
END//
DELIMITER ;

ALTER TABLE `community_goals`
	ADD COLUMN `paid` TINYINT NOT NULL DEFAULT 0 AFTER `end_date`;
