-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               10.4.17-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             11.1.0.6116
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Dumping database structure for altislife
CREATE DATABASE IF NOT EXISTS `altislife` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;
USE `altislife`;

-- Dumping structure for table altislife.containers
CREATE TABLE IF NOT EXISTS `containers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) NOT NULL,
  `classname` varchar(32) NOT NULL,
  `pos` varchar(32) DEFAULT NULL,
  `inventory` text NOT NULL,
  `gear` text NOT NULL,
  `dir` varchar(128) DEFAULT NULL,
  `active` tinyint(4) NOT NULL DEFAULT 0,
  `owned` tinyint(4) NOT NULL DEFAULT 0,
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  KEY `fkIdx_players_containers` (`pid`),
  CONSTRAINT `FK_players_containers` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.containers: ~0 rows (approximately)
/*!40000 ALTER TABLE `containers` DISABLE KEYS */;
/*!40000 ALTER TABLE `containers` ENABLE KEYS */;

-- Dumping structure for procedure altislife.deleteOldGroups
DELIMITER //
CREATE PROCEDURE `deleteOldGroups`()
BEGIN
	DELETE FROM groups WHERE active='0';
END//
DELIMITER ;

-- Dumping structure for table altislife.groups
CREATE TABLE IF NOT EXISTS `groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `owner` varchar(17) NOT NULL,
  `tag` varchar(4) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL,
  `maxmembers` int(11) DEFAULT 8,
  `bank` int(11) DEFAULT 0,
  `active` tinyint(4) NOT NULL DEFAULT 1,
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_name` (`name`),
  UNIQUE KEY `unique_tag` (`tag`) USING BTREE,
  KEY `fkIdx_players_gangs` (`owner`),
  CONSTRAINT `FK_players_gangs` FOREIGN KEY (`owner`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.groups: ~2 rows (approximately)
/*!40000 ALTER TABLE `groups` DISABLE KEYS */;
INSERT INTO `groups` (`id`, `owner`, `tag`, `name`, `maxmembers`, `bank`, `active`, `insert_time`) VALUES
	(1, '76561198092567307', 'R', 'Ridge Incorporated', 8, 0, 1, '2021-03-08 21:50:54'),
	(3, '76561198342068529', 'SN', 'Semi hard niggas', 8, 0, 1, '2021-03-08 22:01:11');
/*!40000 ALTER TABLE `groups` ENABLE KEYS */;

-- Dumping structure for table altislife.houses
CREATE TABLE IF NOT EXISTS `houses` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) NOT NULL,
  `pos` varchar(32) DEFAULT NULL,
  `owned` tinyint(4) DEFAULT 0,
  `garage` tinyint(4) NOT NULL DEFAULT 0,
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  KEY `fkIdx_players_houses` (`pid`),
  CONSTRAINT `FK_players_houses` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.houses: ~0 rows (approximately)
/*!40000 ALTER TABLE `houses` DISABLE KEYS */;
/*!40000 ALTER TABLE `houses` ENABLE KEYS */;

-- Dumping structure for table altislife.players
CREATE TABLE IF NOT EXISTS `players` (
  `uid` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) NOT NULL,
  `name` varchar(32) NOT NULL,
  `aliases` text NOT NULL,
  `cash` int(11) NOT NULL DEFAULT 0,
  `bankacc` int(11) NOT NULL DEFAULT 0,
  `group_id` int(11) NOT NULL DEFAULT -1,
  `coplevel` enum('0','1','2','3','4','5','6','7','8','9','10','11') NOT NULL DEFAULT '0',
  `rtalevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `npaslevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `scolevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `ncalevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `mpulevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `rpulevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `afolevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `uclevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `cop_licenses` text NOT NULL,
  `cop_gear` text NOT NULL,
  `cop_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `cop_blacklisted` tinyint(4) NOT NULL DEFAULT 0,
  `mediclevel` enum('0','1','2','3','4','5') NOT NULL DEFAULT '0',
  `aalevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `med_licenses` text NOT NULL,
  `med_gear` text NOT NULL,
  `med_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `med_blacklisted` tinyint(4) NOT NULL DEFAULT 0,
  `hatolevel` enum('0','1','2','3','4','5') NOT NULL DEFAULT '0',
  `hato_licenses` text NOT NULL,
  `hato_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `hato_gear` text NOT NULL,
  `hato_blacklisted` tinyint(4) NOT NULL DEFAULT 0,
  `civ_gear` text NOT NULL,
  `civ_licenses` text NOT NULL,
  `civ_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `arrested` tinyint(4) NOT NULL DEFAULT 0,
  `prison_timer` int(11) NOT NULL DEFAULT 0,
  `adminlevel` enum('0','1','2','3','4','5') NOT NULL DEFAULT '0',
  `donorlevel` enum('0','1','2','3','4','5') NOT NULL DEFAULT '0',
  `prestige` int(11) NOT NULL DEFAULT 0,
  `level` int(11) NOT NULL DEFAULT 1,
  `xp` int(11) NOT NULL DEFAULT 0,
  `professions` text NOT NULL,
  `daily_tasks` text NOT NULL,
  `weekly_tasks` text NOT NULL,
  `achievements` text NOT NULL,
  `textures` text NOT NULL,
  `playtime` varchar(32) NOT NULL DEFAULT '"[0,0,0]"',
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  `last_seen` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  PRIMARY KEY (`pid`),
  UNIQUE KEY `unique_uid` (`uid`),
  KEY `index_name` (`name`),
  KEY `index_blacklist` (`cop_blacklisted`,`med_blacklisted`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.players: ~6 rows (approximately)
/*!40000 ALTER TABLE `players` DISABLE KEYS */;
INSERT INTO `players` (`uid`, `pid`, `name`, `aliases`, `cash`, `bankacc`, `group_id`, `coplevel`, `rtalevel`, `npaslevel`, `scolevel`, `ncalevel`, `mpulevel`, `rpulevel`, `afolevel`, `uclevel`, `cop_licenses`, `cop_gear`, `cop_stats`, `cop_blacklisted`, `mediclevel`, `aalevel`, `med_licenses`, `med_gear`, `med_stats`, `med_blacklisted`, `hatolevel`, `hato_licenses`, `hato_stats`, `hato_gear`, `hato_blacklisted`, `civ_gear`, `civ_licenses`, `civ_stats`, `arrested`, `prison_timer`, `adminlevel`, `donorlevel`, `prestige`, `level`, `xp`, `professions`, `daily_tasks`, `weekly_tasks`, `achievements`, `textures`, `playtime`, `insert_time`, `last_seen`) VALUES
	(4, '76561197971322689', 'Lewis Holloway [CO0101]', '"[`Lewis Holloway [CO0101]`]"', 0, 50000, -1, '0', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '5', '0', '"[]"', '"[[[],[],[],[`U_O_R_Gorka_01_black_F`,[]],[`V_TacVestIR_blk`,[]],[],`H_Beret_blk`,`G_Aviator`,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[]"', '"[]"', '"[100,100,0]"', 0, 0, '0', '0', 0, 1, 50, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`]"', '"[]"', '"[0,2,0]"', '2021-03-07 22:07:36', '2021-03-23 20:59:30'),
	(2, '76561198054519084', 'Ben Sewell', '"[`Ben Sewell`]"', 0, 50000, -1, '0', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[]"', '"[100,100,0]"', 0, 0, '0', '0', 0, 1, 0, '"[]"', '"[]"', '"[]"', '"[]"', '"[]"', '"[0,0,7]"', '2021-01-29 14:51:04', '2021-03-23 20:59:30'),
	(1, '76561198092567307', 'Jack Williams', '"[`Scarso`]"', 19000, 1420589, 1, '8', '3', '3', '3', '3', '3', '3', '3', '3', '"[]"', '"[[[],[],[],[`U_Rangemaster`,[]],[`V_TacVest_blk_POLICE`,[]],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[`SI`,``]]"', '"[70,60,0]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '1', '"[]"', '"[100,100,0]"', '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', 0, '"[[[],[],[],[`U_C_Man_casual_1_F`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[[`FreshApple`,20],[`Water`,2],[`Pickaxe`,1]],[`U_C_Man_casual_1_F`,``]]"', '"[`Driving`,`Boating`,`Trucking`,`Piloting`,`Schnapps`,`Tobacco`]"', '"[90,80,0]"', 0, 0, '5', '0', 5, 3, 3438, '"[[`Repairing`,[0,1]],[`Mining`,[0,27]],[`Gathering`,[0,19]]]"', '"[[`GatherApple`,280],[`ProcessSalt`,0],[`ProcessUranium`,0]]"', '"[[`SellSilver`,0],[`SellDiamond`,0]]"', '"[`FirstSpawn`,`FanGirl`,`Prestige`,`BuyVehicle`,`Scarso`,`Lewis`]"', '"[[`C_SUV_01_F`,[`Orange`]]]"', '"[725,1,372]"', '2021-01-18 00:53:15', '2021-03-24 03:53:06'),
	(5, '76561198173004713', 'Steve White', '"[`Steve White`]"', 0, 50000, -1, '0', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[]"', '"[]"', '"[100,100,0]"', 0, 0, '0', '0', 0, 1, 0, '"[]"', '"[]"', '"[]"', '"[]"', '"[]"', '"[0,0,0]"', '2021-03-08 22:01:19', '2021-03-23 20:59:31'),
	(6, '76561198273172138', 'Albert Stuart', '"[`Jetan Holo`]"', 8619, 87500, -1, '3', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[[[`arifle_SPAR_01_blk_F`,``,``,``,[],[],``],[],[],[`U_Rangemaster`,[]],[`V_PlateCarrier1_blk`,[]],[`B_Carryall_cbr`,[]],`H_Beret_blk`,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[[`Coffee`,12]],[`PC`,`INVIS`]]"', '"[100,90,0.495058]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[[[],[],[],[`U_C_Man_casual_1_F`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[[`Pickaxe`,1]],[`U_C_Man_casual_1_F`,``]]"', '"[`Driving`,`Trucking`,`Boating`,`Piloting`]"', '"[100,80,0]"', 0, 0, '0', '0', 0, 1, 100, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`,`BuyVehicle`]"', '"[]"', '"[18,0,82]"', '2021-03-18 19:02:22', '2021-03-23 20:59:31'),
	(3, '76561198342068529', 'greans', '"[`Mr. Ace Boyden`]"', 0, 110000, 3, '3', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[[`Redbull`,15]],[`PC`,``]]"', '"[60,40,0.717396]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[[[`arifle_SPAR_01_GL_blk_F`,``,``,``,[`30Rnd_556x45_Stanag`,0],[],``],[],[],[`U_C_Man_casual_1_F`,[[`1Rnd_HE_Grenade_shell`,1,1]]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[],[`U_C_Man_casual_1_F`,``]]"', '"[]"', '"[100,100,0]"', 0, 0, '0', '0', 0, 1, 100, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`,`BuyVehicle`]"', '"[]"', '"[71,0,25]"', '2021-02-28 15:40:50', '2021-03-23 20:59:30');
/*!40000 ALTER TABLE `players` ENABLE KEYS */;

-- Dumping structure for procedure altislife.resetDailyGoals
DELIMITER //
CREATE PROCEDURE `resetDailyGoals`()
BEGIN
	UPDATE players SET daily_tasks = '"[]"';
	UPDATE settings SET `value`=DATE_FORMAT(CURDATE(), '%Y-%c-%e') WHERE setting = 'Day';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.resetVehicles
DELIMITER //
CREATE PROCEDURE `resetVehicles`()
BEGIN
	UPDATE vehicles SET `active`='0';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.resetWeeklyGoals
DELIMITER //
CREATE PROCEDURE `resetWeeklyGoals`()
BEGIN
	UPDATE players SET weekly_tasks = '"[]"';
	UPDATE settings SET `value`=WEEK(CURDATE()) WHERE setting = 'Week';
END//
DELIMITER ;

-- Dumping structure for table altislife.settings
CREATE TABLE IF NOT EXISTS `settings` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `setting` varchar(50) NOT NULL,
  `value` varchar(50) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.settings: ~4 rows (approximately)
/*!40000 ALTER TABLE `settings` DISABLE KEYS */;
INSERT INTO `settings` (`id`, `setting`, `value`) VALUES
	(1, 'DonationGoal', '0'),
	(2, 'ThreatLevel', '0'),
	(3, 'Day', '2021-3-24'),
	(4, 'Week', '12');
/*!40000 ALTER TABLE `settings` ENABLE KEYS */;

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
  `plate` varchar(50) NOT NULL DEFAULT '',
  `texture` varchar(50) NOT NULL DEFAULT '',
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  KEY `fkIdx_players_vehicles` (`pid`),
  KEY `index_type` (`type`),
  KEY `index_side` (`faction`) USING BTREE,
  CONSTRAINT `FK_players_vehicles` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.vehicles: ~6 rows (approximately)
/*!40000 ALTER TABLE `vehicles` DISABLE KEYS */;
INSERT INTO `vehicles` (`id`, `pid`, `faction`, `classname`, `type`, `alive`, `active`, `sold`, `plate`, `texture`, `insert_time`) VALUES
	(1, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 1, '', 'Black', '2021-03-18 23:26:26'),
	(2, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, '', 'Black', '2021-03-18 23:26:59'),
	(3, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, '', 'Black', '2021-03-18 23:27:34'),
	(4, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, '', 'Black', '2021-03-18 23:28:11'),
	(5, '76561198092567307', 'Civilian', 'C_Offroad_01_F', 'Car', 1, 0, 0, '', 'White', '2021-03-18 23:28:45'),
	(6, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, '', 'Black', '2021-03-18 23:29:22');
/*!40000 ALTER TABLE `vehicles` ENABLE KEYS */;

-- Dumping structure for table altislife.wanted
CREATE TABLE IF NOT EXISTS `wanted` (
  `wantedID` varchar(17) NOT NULL,
  `wantedName` varchar(32) NOT NULL,
  `wantedCrimes` text NOT NULL,
  `wantedBounty` int(11) NOT NULL,
  `active` tinyint(4) NOT NULL DEFAULT 0,
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`wantedID`),
  CONSTRAINT `FK_players_wanted` FOREIGN KEY (`wantedID`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.wanted: ~0 rows (approximately)
/*!40000 ALTER TABLE `wanted` DISABLE KEYS */;
/*!40000 ALTER TABLE `wanted` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
