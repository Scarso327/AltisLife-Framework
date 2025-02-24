CREATE TABLE `player_stats` (
	`id` INT NOT NULL AUTO_INCREMENT,
	`pid` VARCHAR(17) NOT NULL,
	`season` INT NOT NULL DEFAULT (1),
	`event` VARCHAR(50) NOT NULL,
	`value` INT NOT NULL DEFAULT (0),
	INDEX `id` (`id`),
  	KEY `FK_stats_players` (`pid`),
	CONSTRAINT `FK_stats_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON UPDATE CASCADE ON DELETE CASCADE
)
COLLATE='utf8mb4_general_ci'
;

INSERT INTO `settings` (`setting`, `value`) VALUES ('NextSeason', '2025-3-12');
INSERT INTO `settings` (`setting`, `value`) VALUES ('Season', '0');