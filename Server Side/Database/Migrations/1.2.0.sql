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