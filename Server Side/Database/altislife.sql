-- --------------------------------------------------------
-- Host:                         localhost
-- Server version:               10.4.28-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             12.6.0.6765
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Dumping database structure for altislife
CREATE DATABASE IF NOT EXISTS `altislife` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci */;
USE `altislife`;

-- Dumping structure for procedure altislife.deleteOldElection
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS `deleteOldElection`()
BEGIN
	DELETE FROM votes WHERE active='0';
	DELETE FROM candidates WHERE active='0';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.deleteOldBaseBids
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS `deleteOldBaseBids`()
BEGIN
	DELETE FROM base_bids WHERE active='0';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.deleteOldMail
DELIMITER //
CREATE PROCEDURE  IF NOT EXISTS`deleteOldMail`()
BEGIN
	DELETE FROM mail WHERE claimed='1';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.deleteOldGroups
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS`deleteOldGroups`()
BEGIN
	DELETE FROM groups WHERE active='0';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.deleteOldHouses
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS `deleteOldHouses`()
BEGIN
	DELETE FROM houses WHERE sold='1';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.deleteOldWarrants
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS `deleteOldWarrants`()
BEGIN
	DELETE FROM warrants WHERE active='0';
END//
DELIMITER ;

DELIMITER //
CREATE PROCEDURE IF NOT EXISTS`deleteOldCommunityGoals`()
BEGIN
	DELETE FROM community_goals WHERE end_date <= CURDATE();
END//
DELIMITER ;

-- Dumping structure for procedure altislife.resetDailyGoals
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS `resetDailyGoals`()
BEGIN
	UPDATE players SET cop_daily_tasks = '"[]"';
  UPDATE players SET med_daily_tasks = '"[]"';
  UPDATE players SET hato_daily_tasks = '"[]"';
  UPDATE players SET civ_daily_tasks = '"[]"';
	UPDATE settings SET `value`=DATE_FORMAT(CURDATE(), '%Y-%c-%e') WHERE setting = 'Day';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.resetGroupBuffs
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS `resetGroupBuffs`()
BEGIN
	UPDATE groups SET buffs = '"[]"';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.resetVehicles
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS `resetVehicles`()
BEGIN
	UPDATE vehicles SET `active`='0';
	DELETE FROM vehicles WHERE sold='1';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.resetWeeklyGoals
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS `resetWeeklyGoals`()
BEGIN
	UPDATE players SET cop_weekly_tasks = '"[]"';
  UPDATE players SET med_weekly_tasks = '"[]"';
  UPDATE players SET hato_weekly_tasks = '"[]"';
  UPDATE players SET civ_weekly_tasks = '"[]"';
	UPDATE settings SET `value`=WEEK(CURDATE()) WHERE setting = 'Week';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.sortPremiumGroups
DELIMITER //
CREATE PROCEDURE IF NOT EXISTS `sortPremiumGroups`()
BEGIN
	UPDATE groups SET premium = '0' WHERE premium = '1' AND CURRENT_TIMESTAMP() > premium_expire;
END//
DELIMITER ;

-- Dumping structure for table altislife.base_bids
CREATE TABLE IF NOT EXISTS `base_bids` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `base` varchar(50) NOT NULL,
  `group_id` int(11) NOT NULL,
  `bid` int(11) NOT NULL DEFAULT 0,
  `active` tinyint(4) NOT NULL DEFAULT 1,
  PRIMARY KEY (`id`),
  KEY `FK_base_bids_groups` (`group_id`),
  CONSTRAINT `FK_base_bids_groups` FOREIGN KEY (`group_id`) REFERENCES `groups` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.candidates
CREATE TABLE IF NOT EXISTS `candidates` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL,
  `pid` varchar(50) NOT NULL,
  `active` tinyint(4) NOT NULL DEFAULT 1,
  PRIMARY KEY (`id`),
  KEY `FK_candidates_players` (`pid`),
  CONSTRAINT `FK_candidates_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.community_goals
CREATE TABLE IF NOT EXISTS `community_goals` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `goal_cfg` varchar(50) NOT NULL,
  `end_date` date NOT NULL,
  `paid` tinyint(4) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.community_goal_contributions
CREATE TABLE IF NOT EXISTS `community_goal_contributions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) NOT NULL,
  `goalId` int(11) NOT NULL DEFAULT 0,
  `contribution` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  UNIQUE KEY `pid` (`pid`,`goalId`),
  KEY `FK_community_goal_contributions_community_goals` (`goalId`),
  CONSTRAINT `FK_community_goal_contributions_community_goals` FOREIGN KEY (`goalId`) REFERENCES `community_goals` (`id`) ON DELETE CASCADE ON UPDATE NO ACTION,
  CONSTRAINT `FK_community_goal_contributions_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.groups
CREATE TABLE IF NOT EXISTS `groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `owner` varchar(17) NOT NULL,
  `type` varchar(32) DEFAULT NULL,
  `tag` varchar(5) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL,
  `level` int(11) DEFAULT 0,
  `xp` int(11) DEFAULT 0,
  `bank` int(11) DEFAULT 0,
  `tax` float DEFAULT 0,
  `active` tinyint(4) NOT NULL DEFAULT 1,
  `premium` tinyint(4) NOT NULL DEFAULT 0,
  `ranks` text NOT NULL,
  `buffs` text NOT NULL,
  `deposit` tinyint(4) NOT NULL DEFAULT 6,
  `withdraw` tinyint(4) NOT NULL DEFAULT 6,
  `rank` tinyint(4) NOT NULL DEFAULT 6,
  `invite` tinyint(4) NOT NULL DEFAULT 6,
  `kick` tinyint(4) NOT NULL DEFAULT 6,
  `premium_expire` date NOT NULL DEFAULT current_timestamp(),
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_name` (`name`),
  UNIQUE KEY `unique_tag` (`tag`) USING BTREE,
  KEY `fkIdx_players_gangs` (`owner`),
  CONSTRAINT `FK_players_gangs` FOREIGN KEY (`owner`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.houses
CREATE TABLE IF NOT EXISTS `houses` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) NOT NULL,
  `classname` varchar(64) DEFAULT NULL,
  `pos` varchar(32) DEFAULT NULL,
  `name` varchar(32) DEFAULT '',
  `storage` text DEFAULT NULL,
  `virtualStorage` text DEFAULT NULL,
  `shared` tinyint(4) DEFAULT 0,
  `sold` tinyint(4) DEFAULT 0,
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  UNIQUE KEY `pos` (`pos`),
  KEY `fkIdx_players_houses` (`pid`),
  CONSTRAINT `FK_players_houses` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.logs
CREATE TABLE IF NOT EXISTS `logs` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `event` varchar(50) NOT NULL DEFAULT '',
  `pid` varchar(17) NOT NULL DEFAULT '',
  `content` text NOT NULL,
  `insert` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  KEY `pid` (`pid`),
  CONSTRAINT `FK_logs_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2057 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.logs_queue
CREATE TABLE IF NOT EXISTS `logs_queue` (
  `log_id` int(11) NOT NULL,
  `handled` tinyint(4) NOT NULL DEFAULT 0,
  `time` timestamp NOT NULL DEFAULT current_timestamp(),
  KEY `FK_logs_queue_logs` (`log_id`),
  CONSTRAINT `FK_logs_queue_logs` FOREIGN KEY (`log_id`) REFERENCES `logs` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.mail
CREATE TABLE IF NOT EXISTS `mail` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(50) NOT NULL,
  `type` varchar(50) NOT NULL DEFAULT '',
  `class` varchar(50) NOT NULL,
  `data` text NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `claimed` tinyint(4) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `pid` (`pid`),
  CONSTRAINT `FK__players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=145 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.players
CREATE TABLE IF NOT EXISTS `players` (
  `uid` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) NOT NULL,
  `name` varchar(32) NOT NULL,
  `aliases` text NOT NULL,
  `cash` int(11) NOT NULL DEFAULT 0,
  `bankacc` int(11) NOT NULL DEFAULT 0,
  `group_id` int(11) NOT NULL DEFAULT -1,
  `group_level` int(11) NOT NULL DEFAULT 0,
  `coplevel` enum('0','1','2','3','4','5','6','7','8','9','10','11') NOT NULL DEFAULT '0',
  `collevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `npaslevel` enum('0','1','2','3','4') NOT NULL DEFAULT '0',
  `scolevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `ncalevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `mpulevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `rpulevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `sfolevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `uclevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `cop_licenses` text NOT NULL,
  `cop_perks` text NOT NULL,
  `cop_gear` text NOT NULL,
  `cop_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `cop_daily_tasks` text NOT NULL DEFAULT '"[]"',
  `cop_weekly_tasks` text NOT NULL DEFAULT '"[]"',
  `cop_blacklisted` tinyint(4) NOT NULL DEFAULT 0,
  `mediclevel` enum('0','1','2','3','4','5','6','7','8') NOT NULL DEFAULT '0',
  `aalevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `hartlevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `hrlevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `med_licenses` text NOT NULL,
  `med_perks` text NOT NULL,
  `med_gear` text NOT NULL,
  `med_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `med_daily_tasks` text NOT NULL DEFAULT '"[]"',
  `med_weekly_tasks` text NOT NULL DEFAULT '"[]"',
  `med_blacklisted` tinyint(4) NOT NULL DEFAULT 0,
  `hatolevel` enum('0','1','2','3','4') NOT NULL DEFAULT '0',
  `hato_licenses` text NOT NULL,
  `hato_perks` text NOT NULL,
  `hato_gear` text NOT NULL,
  `hato_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `hato_daily_tasks` text NOT NULL DEFAULT '"[]"',
  `hato_weekly_tasks` text NOT NULL DEFAULT '"[]"',
  `hato_blacklisted` tinyint(4) NOT NULL DEFAULT 0,
  `civ_licenses` text NOT NULL,
  `civ_perks` text NOT NULL,
  `civ_gear` text NOT NULL,
  `civ_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `civ_daily_tasks` text NOT NULL DEFAULT '"[]"',
  `civ_weekly_tasks` text NOT NULL DEFAULT '"[]"',
  `arrested` tinyint(4) NOT NULL DEFAULT 0,
  `prison_timer` int(11) NOT NULL DEFAULT 0,
  `adminlevel` enum('0','1','2','3','4','5') NOT NULL DEFAULT '0',
  `eventslevel` enum('0','1','2') NOT NULL DEFAULT '0',
  `donorlevel` enum('0','1','2','3','4','5') NOT NULL DEFAULT '0',
  `prestige` int(11) NOT NULL DEFAULT 0,
  `level` int(11) NOT NULL DEFAULT 1,
  `xp` int(11) NOT NULL DEFAULT 0,
  `reputation` int(11) NOT NULL DEFAULT 0,
  `professions` text NOT NULL,
  `achievements` text NOT NULL,
  `titles` text NOT NULL,
  `textures` text NOT NULL,
  `blueprints` text NOT NULL,
  `playtime` varchar(32) NOT NULL DEFAULT '"[0,0,0,0]"',
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  `last_seen` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  PRIMARY KEY (`pid`),
  UNIQUE KEY `unique_uid` (`uid`),
  KEY `index_name` (`name`),
  KEY `index_blacklist` (`cop_blacklisted`,`med_blacklisted`) USING BTREE,
  KEY `hato_blacklisted` (`hato_blacklisted`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.settings
CREATE TABLE IF NOT EXISTS `settings` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `setting` varchar(50) NOT NULL,
  `value` varchar(300) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `setting` (`setting`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.vehicles
CREATE TABLE IF NOT EXISTS `vehicles` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) NOT NULL,
  `faction` varchar(10) NOT NULL,
  `classname` varchar(64) NOT NULL,
  `type` varchar(16) NOT NULL,
  `alive` tinyint(4) NOT NULL DEFAULT 1,
  `active` tinyint(4) NOT NULL DEFAULT 0,
  `sold` tinyint(4) NOT NULL DEFAULT 0,
  `impound` int(11) NOT NULL DEFAULT 0,
  `plate` varchar(50) NOT NULL DEFAULT '',
  `texture` varchar(50) NOT NULL DEFAULT '',
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  KEY `fkIdx_players_vehicles` (`pid`),
  KEY `index_type` (`type`),
  KEY `index_side` (`faction`) USING BTREE,
  CONSTRAINT `FK_players_vehicles` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.votes
CREATE TABLE IF NOT EXISTS `votes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(50) DEFAULT NULL,
  `candidate` int(11) DEFAULT NULL,
  `amount` int(11) DEFAULT 1,
  `active` tinyint(4) DEFAULT 1,
  PRIMARY KEY (`id`),
  UNIQUE KEY `pid` (`pid`),
  KEY `FK_votes_candidates` (`candidate`),
  CONSTRAINT `FK_votes_candidates` FOREIGN KEY (`candidate`) REFERENCES `candidates` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `FK_votes_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for table altislife.warrants
CREATE TABLE IF NOT EXISTS `warrants` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(50) NOT NULL,
  `act` varchar(50) NOT NULL,
  `crime` varchar(50) NOT NULL,
  `info` text NOT NULL,
  `insert` timestamp NOT NULL DEFAULT current_timestamp(),
  `active` tinyint(4) NOT NULL DEFAULT 1,
  PRIMARY KEY (`id`),
  KEY `FK_warrants_players` (`pid`),
  CONSTRAINT `FK_warrants_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Data exporting was unselected.

-- Dumping structure for trigger altislife.logs_after_insert
SET @OLDTMP_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_ZERO_IN_DATE,NO_ZERO_DATE,NO_ENGINE_SUBSTITUTION';
DELIMITER //
CREATE TRIGGER `logs_after_insert` AFTER INSERT ON `logs` FOR EACH ROW BEGIN
	INSERT INTO logs_queue (log_id) VALUES (NEW.id);
END//
DELIMITER ;
SET SQL_MODE=@OLDTMP_SQL_MODE;

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
