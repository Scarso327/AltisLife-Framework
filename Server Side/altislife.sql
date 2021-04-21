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

-- Dumping structure for table altislife.candidates
CREATE TABLE IF NOT EXISTS `candidates` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL,
  `pid` varchar(50) NOT NULL,
  `active` tinyint(4) NOT NULL DEFAULT 1,
  PRIMARY KEY (`id`),
  KEY `FK_candidates_players` (`pid`),
  CONSTRAINT `FK_candidates_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.candidates: ~2 rows (approximately)
/*!40000 ALTER TABLE `candidates` DISABLE KEYS */;
INSERT INTO `candidates` (`id`, `name`, `pid`, `active`) VALUES
	(1, 'Jack Williams', '76561198092567307', 0),
	(2, 'Ace Boyden', '76561198342068529', 0);
/*!40000 ALTER TABLE `candidates` ENABLE KEYS */;

-- Dumping structure for procedure altislife.deleteOldElection
DELIMITER //
CREATE PROCEDURE `deleteOldElection`()
BEGIN
	DELETE FROM votes WHERE active='0';
	DELETE FROM candidates WHERE active='0';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.deleteOldGroups
DELIMITER //
CREATE PROCEDURE `deleteOldGroups`()
BEGIN
	DELETE FROM groups WHERE active='0';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.deleteOldHouses
DELIMITER //
CREATE PROCEDURE `deleteOldHouses`()
BEGIN
	DELETE FROM houses WHERE sold='1';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.deleteOldWarrants
DELIMITER //
CREATE PROCEDURE `deleteOldWarrants`()
BEGIN
	DELETE FROM warrants WHERE active='0';
END//
DELIMITER ;

-- Dumping structure for table altislife.groups
CREATE TABLE IF NOT EXISTS `groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `owner` varchar(17) NOT NULL,
  `type` varchar(32) DEFAULT NULL,
  `tag` varchar(4) DEFAULT NULL,
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
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.groups: ~2 rows (approximately)
/*!40000 ALTER TABLE `groups` DISABLE KEYS */;
INSERT INTO `groups` (`id`, `owner`, `type`, `tag`, `name`, `level`, `xp`, `bank`, `tax`, `active`, `premium`, `ranks`, `buffs`, `deposit`, `withdraw`, `rank`, `invite`, `kick`, `premium_expire`, `insert_time`) VALUES
	(4, '76561198092567307', 'Party', 'RUK', 'ReformUK', 0, 0, 0, 0, 1, 0, '"[`PRIVATE`,`CORPORAL`,`SERGEANT`,`LIEUTENANT`,`CAPTAIN`,`MAJOR`,`COLONEL`]"', '"[[`Digging`,0.25],[`Surveying`,0.25]]"', 3, 3, 4, 4, 4, '2021-04-19', '2021-04-19 22:35:07');
/*!40000 ALTER TABLE `groups` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=28 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.houses: ~8 rows (approximately)
/*!40000 ALTER TABLE `houses` DISABLE KEYS */;
INSERT INTO `houses` (`id`, `pid`, `classname`, `pos`, `name`, `storage`, `virtualStorage`, `shared`, `sold`, `insert_time`) VALUES
	(11, '76561197971322689', 'Land_i_House_Big_02_V1_F', '"[3647.58,13052.2,0.202638]"', '', '"[]"', '"[]"', 0, 0, '2021-03-30 01:26:45'),
	(16, '76561197971322689', 'Land_i_House_Big_02_V1_F', '"[3679.29,13001,0.359909]"', '', '"[]"', '"[]"', 0, 0, '2021-03-30 01:27:36'),
	(17, '76561197971322689', 'Land_i_House_Big_02_V1_F', '"[3688.23,12996.5,0.375095]"', '', '"[]"', '"[]"', 0, 0, '2021-03-30 01:27:40'),
	(18, '76561198092567307', 'Land_i_House_Big_02_V1_F', '"[3685.34,13059.8,1.16742]"', 'House', '"[]"', '"[[`IronBar`,5]]"', 1, 0, '2021-03-30 01:55:36'),
	(19, '76561197971322689', 'Land_i_House_Big_02_V1_F', '"[3663.14,13031.2,0.480713]"', '', '"[]"', '"[]"', 0, 0, '2021-03-30 01:55:56'),
	(21, '76561198092567307', 'Land_i_Shed_Ind_F', '"[3072.6,12175.2,0.095602]"', 'Drug House', '"[]"', '"[[`PanicButton`,1]]"', 0, 0, '2021-04-01 18:07:45'),
	(24, '76561198383272185', 'Land_i_House_Big_02_V1_F', '"[3592.7,13080.7,0.13638]"', '', '"[]"', '"[]"', 0, 0, '2021-04-05 02:07:31'),
	(25, '76561198383272185', 'Land_i_Shed_Ind_F', '"[11887,9473.21,0.210056]"', '', '"[]"', '"[]"', 0, 0, '2021-04-05 02:40:39'),
	(26, '76561198273172138', 'C_Boat_Civil_04_F', '"[3108.46,12760.2,14.9616]"', '', '"[]"', '"[]"', 0, 0, '2021-04-05 23:41:55'),
	(27, '76561198273172138', 'Land_i_House_Big_01_V2_F', '"[3594.03,13034.8,0.41533]"', '', '"[]"', '"[]"', 0, 0, '2021-04-05 23:43:22');
/*!40000 ALTER TABLE `houses` ENABLE KEYS */;

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.logs: ~0 rows (approximately)
/*!40000 ALTER TABLE `logs` DISABLE KEYS */;
/*!40000 ALTER TABLE `logs` ENABLE KEYS */;

-- Dumping structure for table altislife.mail
CREATE TABLE IF NOT EXISTS `mail` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(50) NOT NULL,
  `type` enum('Weapon','Magazine','Texture','Vehicle','Backpack','VirtualItem') NOT NULL,
  `class` varchar(50) NOT NULL,
  `data` text NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `claimed` tinyint(4) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `pid` (`pid`),
  CONSTRAINT `FK__players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.mail: ~6 rows (approximately)
/*!40000 ALTER TABLE `mail` DISABLE KEYS */;
INSERT INTO `mail` (`id`, `pid`, `type`, `class`, `data`, `timestamp`, `claimed`) VALUES
	(1, '76561198092567307', 'VirtualItem', 'AncientAmber', '18', '2021-04-13 13:44:47', 0),
	(2, '76561198092567307', 'VirtualItem', 'BrokenTimepiece', '6', '2021-04-13 13:44:47', 0),
	(3, '76561198092567307', 'VirtualItem', 'AncientAmber', '3', '2021-04-13 14:56:57', 0),
	(4, '76561198092567307', 'VirtualItem', 'BrokenTimepiece', '1', '2021-04-13 14:56:57', 0),
	(5, '76561198092567307', 'Texture', 'C_Offroad_02_unarmed_F', '"[[0,`Ridge`]]"', '2021-04-13 15:07:12', 0),
	(6, '76561198092567307', 'VirtualItem', 'AncientAmber', '15', '2021-04-13 15:07:12', 0),
	(7, '76561198092567307', 'VirtualItem', 'BrokenTimepiece', '5', '2021-04-13 15:07:12', 0);
/*!40000 ALTER TABLE `mail` ENABLE KEYS */;

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
  `rtalevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `npaslevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `scolevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `ncalevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `mpulevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `rpulevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `afolevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `uclevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `cop_licenses` text NOT NULL,
  `cop_perks` text NOT NULL,
  `cop_gear` text NOT NULL,
  `cop_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `cop_blacklisted` tinyint(4) NOT NULL DEFAULT 0,
  `mediclevel` enum('0','1','2','3','4','5','6','7','8') NOT NULL DEFAULT '0',
  `aalevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `hrlevel` enum('0','1','2','3') NOT NULL DEFAULT '0',
  `med_licenses` text NOT NULL,
  `med_perks` text NOT NULL,
  `med_gear` text NOT NULL,
  `med_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `med_blacklisted` tinyint(4) NOT NULL DEFAULT 0,
  `hatolevel` enum('0','1','2','3','4') NOT NULL DEFAULT '0',
  `hato_licenses` text NOT NULL,
  `hato_perks` text NOT NULL,
  `hato_gear` text NOT NULL,
  `hato_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
  `hato_blacklisted` tinyint(4) NOT NULL DEFAULT 0,
  `civ_licenses` text NOT NULL,
  `civ_perks` text NOT NULL,
  `civ_gear` text NOT NULL,
  `civ_stats` varchar(25) NOT NULL DEFAULT '"[100,100,0]"',
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
  `daily_tasks` text NOT NULL,
  `weekly_tasks` text NOT NULL,
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
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.players: ~8 rows (approximately)
/*!40000 ALTER TABLE `players` DISABLE KEYS */;
INSERT INTO `players` (`uid`, `pid`, `name`, `aliases`, `cash`, `bankacc`, `group_id`, `group_level`, `coplevel`, `rtalevel`, `npaslevel`, `scolevel`, `ncalevel`, `mpulevel`, `rpulevel`, `afolevel`, `uclevel`, `cop_licenses`, `cop_perks`, `cop_gear`, `cop_stats`, `cop_blacklisted`, `mediclevel`, `aalevel`, `hrlevel`, `med_licenses`, `med_perks`, `med_gear`, `med_stats`, `med_blacklisted`, `hatolevel`, `hato_licenses`, `hato_perks`, `hato_gear`, `hato_stats`, `hato_blacklisted`, `civ_licenses`, `civ_perks`, `civ_gear`, `civ_stats`, `arrested`, `prison_timer`, `adminlevel`, `eventslevel`, `donorlevel`, `prestige`, `level`, `xp`, `reputation`, `professions`, `daily_tasks`, `weekly_tasks`, `achievements`, `titles`, `textures`, `blueprints`, `playtime`, `insert_time`, `last_seen`) VALUES
	(4, '76561197971322689', 'Lewis Holloway [CO0003]', '"[`Lewis Holloway [CO0101]`]"', 7758417, 45349312, -1, 0, '11', '3', '3', '3', '3', '3', '3', '3', '3', '"[]"', '"[]"', '"[[[],[],[],[`U_Rangemaster`,[]],[`V_PlateCarrier2_blk`,[]],[],`H_Beret_gen_F`,`G_Aviator`,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[`CC`,``]]"', '"[60,30,0]"', 0, '5', '0', '0', '"[]"', '"[]"', '"[[[],[],[],[`U_O_R_Gorka_01_black_F`,[]],[],[],`H_Cap_blk`,`G_Aviator`,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[`Medic`,``]]"', '"[100,100,0]"', 0, '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '"[`Home`,`Driving`,`Rebel`]"', '"[]"', '"[[[],[],[],[`U_C_Man_casual_1_F`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[],[`U_C_Man_casual_1_F`,``]]"', '"[100,100,0]"', 0, 0, '5', '0', '0', 0, 1, 2200, 0, '"[]"', '"[]"', '"[[`SellCopper`,0],[`SellIron`,0]]"', '"[`FirstSpawn`,`BuyVehicle`,`OneMillion`,`TenMillion`,`JoinStaff`,`JoinAPC`,`JoinRTA`,`JoinNPAS`,`JoinSCO19`,`JoinNCA`,`JoinMPU`,`JoinRPU`,`JoinUC`]"', '"[`OneMillion`,`JoinStaff`]"', '"[]"', '"[]"', '"[148,5,11,10]"', '2021-03-07 22:07:36', '2021-04-19 00:48:32'),
	(2, '76561198054519084', 'Ben Sewell', '"[`Ben Sewell`]"', 0, 50000, -1, 0, '0', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '0', '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '"[]"', '"[]"', '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[100,100,0]"', 0, 0, '0', '0', '0', 0, 1, 0, 0, '"[]"', '"[]"', '"[]"', '"[]"', '"[]"', '"[]"', '"[]"', '"[0,0,7]"', '2021-01-29 14:51:04', '2021-04-15 23:29:24'),
	(1, '76561198092567307', 'Jack Williams', '"[`Scarso`]"', 0, 44262888, 4, 6, '11', '3', '3', '3', '3', '3', '3', '3', '3', '"[`Driving`,`Boating`,`Trucking`,`Piloting`,`Schnapps`,`Tobacco`,`Home`,`IDAP`]"', '"[[`SecondNature`,[1,0]]]"', '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[`CC`,``]]"', '"[90,90,0]"', 0, '4', '0', '0', '"[]"', '"[]"', '"[[[],[],[],[`U_O_R_Gorka_01_black_F`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[`Medic`,``]]"', '"[100,100,0]"', 0, '4', '"[]"', '"[]"', '"[[[],[],[],[`U_O_R_Gorka_01_black_F`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[`Hato`,``]]"', '"[100,100,0]"', 0, '"[`Driving`,`Boating`,`Trucking`,`Piloting`,`Schnapps`,`Tobacco`,`Home`,`IDAP`,`Rebel`]"', '"[[`SecondNature`,[1,0]],[`ExpertTrader`,[1,0]]]"', '"[[[],[],[],[`U_C_Man_casual_6_F`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[[`Identification`,[`Jack Williams`]]],[`U_C_Man_casual_6_F`,``]]"', '"[80,80,0]"', 0, 0, '5', '0', '2', 6, 2, 3970, -150, '"[[`Mining`,[0,3]]]"', '"[[`MineCopper`,0],[`MineSilver`,0],[`ProcessOil`,0]]"', '"[[`SellSalt`,0],[`SellSilver`,0]]"', '"[`FirstSpawn`,`JoinStaff`,`JoinUC`,`OneMillion`,`TenMillion`,`JoinAPC`,`JoinRTA`,`JoinNPAS`,`JoinSCO19`,`JoinNCA`,`JoinMPU`,`JoinRPU`,`BuyVehicle`,`JoinHATO`,`JoinNHS`,`TaskMaster`,`Archaeologist`,`Governor`]"', '"[`Rookie`,`OneMillion`,`Prestige`,`Convict`,`TaskMaster`,`JoinStaff`,`Captain`,`Archaeologist`,`Governor`]"', '"[[`C_SUV_01_F`,[`Orange`]],[`C_Heli_Light_01_civil_F`,[`ChromeGold`]]]"', '"[[`Items`,[`B_Pickaxe`]]]"', '"[779,3,611,1315]"', '2021-01-18 00:53:15', '2021-04-21 17:30:03'),
	(5, '76561198173004713', 'Steve White', '"[`Steve White`]"', 0, 87500, -1, 0, '0', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '0', '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '"[]"', '"[]"', '"[[[],[],[],[`U_C_Man_casual_1_F`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[[`Identification`,[`Steve White`]]],[`U_C_Man_casual_1_F`,``]]"', '"[100,100,0]"', 0, 0, '0', '0', '0', 0, 1, 1050, 0, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`,`Lewis`]"', '"[]"', '"[]"', '"[]"', '"[0,0,26,0]"', '2021-03-08 22:01:19', '2021-04-15 23:29:25'),
	(6, '76561198273172138', 'Albert Stuart', '"[`Jetan Holo`]"', 0, 68212224, -1, 0, '3', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[100,90,0]"', 0, '0', '0', '0', '"[]"', '"[]"', '"[[[],[],[],[`U_Competitor`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[100,100,0]"', 0, '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '"[`Driving`,`Trucking`,`Boating`,`Piloting`,`Home`,`IDAP`]"', '"[[`ImprovedMetabolism`,[1,0]]]"', '"[[[],[],[],[`U_C_Man_casual_6_F`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[[`Identification`,[`Albert Stuart`]]],[``,``]]"', '"[100,100,0]"', 0, 0, '0', '0', '0', 0, 2, 485, 0, '"[]"', '"[]"', '"[[`SellCopper`,0],[`SellIron`,0]]"', '"[`FirstSpawn`,`BuyVehicle`,`Jetan`,`OneMillion`,`BuyHouse`,`TenMillion`,`Lewis`,`Convict`,`TaskMaster`]"', '"[`OneMillion`,`Convict`,`TaskMaster`]"', '"[]"', '"[]"', '"[41,0,135,163]"', '2021-03-18 19:02:22', '2021-04-20 12:00:26'),
	(12, '76561198279405701', 'Jakob Boyden [AP0069]', '"[`Jakob Boyden [AP0069]`]"', 0, 158500, -1, 0, '7', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[[[`arifle_Katiba_C_F`,``,``,``,[],[],``],[],[`hgun_P07_blk_F`,``,``,``,[],[],``],[`U_Rangemaster`,[]],[`V_BandollierB_blk`,[]],[`B_Carryall_cbr`,[[`V_PlateCarrier1_blk`,false],[`U_C_FormalSuit_01_khaki_F`,false]]],`H_Beret_blk`,``,[`Rangefinder`,``,``,``,[],[],``],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[[`BloodBag`,15]],[`CI`,``]]"', '"[80,70,0]"', 0, '3', '0', '0', '"[]"', '"[]"', '"[[[],[],[],[`U_Competitor`,[]],[],[`B_Carryall_cbr`,[[`U_Competitor`,false],[`U_O_R_Gorka_01_black_F`,false]]],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[100,100,0]"', 0, '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '"[`Taxi`,`Driving`,`Trucking`,`Boating`,`Piloting`,`IDAP`,`News`]"', '"[[`SecondNature`,[1,0]]]"', '"[[[],[],[],[`U_C_IDAP_Man_shorts_F`,[]],[`V_Plain_medical_F`,[]],[`B_Messenger_Black_F`,[[`U_C_Man_casual_1_F`,false]]],`H_Cap_blk`,`G_Aviator`,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[[`Identification`,[`Jakob Boyden [AP0069]`]]],[``,``]]"', '"[100,90,0]"', 0, 0, '0', '0', '0', 0, 1, 100, 0, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`,`BuyVehicle`]"', '"[]"', '"[]"', '"[]"', '"[40,4,0,29]"', '2021-04-06 01:31:58', '2021-04-15 23:29:27'),
	(3, '76561198342068529', 'Ace Boyden', '"[`Mr. Ace Boyden`]"', 0, 110000, -1, 0, '3', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[100,100,0]"', 0, '0', '0', '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '"[]"', '"[]"', '"[[[`arifle_SPAR_01_GL_blk_F`,``,``,``,[`30Rnd_556x45_Stanag`,0],[],``],[],[],[`U_C_Man_casual_1_F`,[[`1Rnd_HE_Grenade_shell`,1,1]]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[],[`U_C_Man_casual_1_F`,``]]"', '"[100,100,0]"', 0, 0, '3', '0', '0', 0, 1, 110, 0, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`,`BuyVehicle`,`Convict`]"', '"[`Convict`]"', '"[]"', '"[]"', '"[95,0,25]"', '2021-02-28 15:40:50', '2021-04-15 23:29:24'),
	(11, '76561198383272185', 'Summit1G', '"[`Summit1G`]"', 3, 71568080, -1, 0, '3', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[[[`arifle_CTAR_blk_F`,``,``,``,[],[],``],[],[`hgun_P07_blk_F`,``,``,``,[],[],``],[`U_Rangemaster`,[]],[`V_PlateCarrier1_blk`,[]],[`B_Carryall_cbr`,[]],`H_Cap_blk`,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[`PC`,`INVIS`]]"', '"[100,100,0.026504]"', 0, '0', '0', '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[]"', '"[]"', '"[100,100,0]"', 0, '"[`Home`,`IDAP`,`Hunting`,`Driving`,`Trucking`,`Boating`,`Piloting`,`Blackmarket`,`Rebel`]"', '"[]"', '"[[[],[],[],[`U_C_Man_casual_1_F`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[[`Identification`,[`Summit1G`,`Summit1G`]]],[``,``]]"', '"[100,90,0]"', 0, 0, '0', '0', '0', 0, 1, 450, 0, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`,`BuyVehicle`,`OneMillion`,`TenMillion`,`Captain`]"', '"[`OneMillion`,`Captain`]"', '"[]"', '"[]"', '"[14,0,0,112]"', '2021-04-05 01:59:00', '2021-04-15 23:29:26');
/*!40000 ALTER TABLE `players` ENABLE KEYS */;

-- Dumping structure for procedure altislife.resetDailyGoals
DELIMITER //
CREATE PROCEDURE `resetDailyGoals`()
BEGIN
	UPDATE players SET daily_tasks = '"[]"';
	UPDATE settings SET `value`=DATE_FORMAT(CURDATE(), '%Y-%c-%e') WHERE setting = 'Day';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.resetGroupBuffs
DELIMITER //
CREATE PROCEDURE `resetGroupBuffs`()
BEGIN
	UPDATE groups SET buffs = '"[]"';
END//
DELIMITER ;

-- Dumping structure for procedure altislife.resetVehicles
DELIMITER //
CREATE PROCEDURE `resetVehicles`()
BEGIN
	UPDATE vehicles SET `active`='0';
	DELETE FROM vehicles WHERE sold='1';
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
  PRIMARY KEY (`id`),
  UNIQUE KEY `setting` (`setting`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.settings: ~10 rows (approximately)
/*!40000 ALTER TABLE `settings` DISABLE KEYS */;
INSERT INTO `settings` (`id`, `setting`, `value`) VALUES
	(1, 'DonationGoal', '0'),
	(2, 'ThreatLevel', '0'),
	(3, 'Day', '2021-4-21'),
	(4, 'Week', '16'),
	(5, 'Governor', '"[`Ace Boyden`,`76561198342068529`]"'),
	(6, 'GovernorSettings', '"[[`Paychecks`,7500],[`Tax`,9],[`Mission`,30]]"'),
	(7, 'Election', '0'),
	(8, 'NextElection', '2021-5-5'),
	(9, 'base_owner_North', '-1'),
	(10, 'base_owner_South', '-1');
/*!40000 ALTER TABLE `settings` ENABLE KEYS */;

-- Dumping structure for procedure altislife.sortPremiumGroups
DELIMITER //
CREATE PROCEDURE `sortPremiumGroups`()
BEGIN
	UPDATE groups SET premium = '0' WHERE premium = '1' AND CURRENT_TIMESTAMP() > premium_expire;
END//
DELIMITER ;

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
) ENGINE=InnoDB AUTO_INCREMENT=48 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.vehicles: ~39 rows (approximately)
/*!40000 ALTER TABLE `vehicles` DISABLE KEYS */;
INSERT INTO `vehicles` (`id`, `pid`, `faction`, `classname`, `type`, `alive`, `active`, `sold`, `impound`, `plate`, `texture`, `insert_time`) VALUES
	(2, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-18 23:26:59'),
	(3, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-18 23:27:34'),
	(4, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-18 23:28:11'),
	(6, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, 150000, '', 'Black', '2021-03-18 23:29:22'),
	(7, '76561198273172138', 'Civilian', 'C_Hatchback_01_sport_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-24 21:41:23'),
	(8, '76561198273172138', 'Civilian', 'O_LSV_02_unarmed_F', 'Car', 1, 0, 0, 0, '', 'PoliceBlack', '2021-03-24 21:42:16'),
	(9, '76561198273172138', 'Civilian', 'C_Hatchback_01_sport_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-25 23:41:05'),
	(10, '76561198273172138', 'Civilian', 'C_Hatchback_01_sport_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-25 23:47:17'),
	(11, '76561198273172138', 'Civilian', 'C_Hatchback_01_sport_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-25 23:52:44'),
	(12, '76561198092567307', 'Civilian', 'C_Offroad_01_F', 'Car', 1, 0, 0, 0, '', 'White', '2021-03-26 16:18:53'),
	(13, '76561198092567307', 'Civilian', 'C_Hatchback_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-26 16:21:46'),
	(14, '76561198092567307', 'Civilian', 'C_Van_02_vehicle_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-26 16:23:52'),
	(15, '76561198092567307', 'Civilian', 'C_Offroad_01_F', 'Car', 1, 0, 0, 0, '', 'White', '2021-03-30 01:12:06'),
	(16, '76561198273172138', 'Civilian', 'C_Boat_Civil_01_F', 'Ship', 1, 0, 0, 0, '', 'Medic', '2021-03-30 01:28:49'),
	(17, '76561198273172138', 'Civilian', 'C_Boat_Civil_01_F', 'Ship', 1, 0, 0, 0, '', 'Medic', '2021-03-30 01:31:08'),
	(18, '76561198273172138', 'Civilian', 'C_Heli_Light_01_civil_F', 'Helicopter', 1, 0, 0, 0, '', 'TotalRed', '2021-03-30 01:35:02'),
	(19, '76561198273172138', 'Civilian', 'B_Plane_CAS_01_F', 'Plane', 1, 0, 0, 0, '', '', '2021-03-30 01:35:17'),
	(20, '76561198273172138', 'Civilian', 'O_Plane_Fighter_02_Stealth_F', 'Plane', 1, 0, 0, 0, '', '', '2021-03-30 01:40:52'),
	(21, '76561198273172138', 'Civilian', 'C_Boat_Civil_01_F', 'Ship', 1, 0, 0, 0, '', 'Civilian', '2021-04-03 19:30:28'),
	(22, '76561198383272185', 'Civilian', 'C_IDAP_Heli_Transport_02_F', 'Helicopter', 1, 0, 0, 0, '', 'Dahoman', '2021-04-05 02:10:36'),
	(23, '76561198383272185', 'Civilian', 'O_Plane_CAS_02_F', 'Plane', 1, 0, 0, 0, '', '', '2021-04-05 02:55:30'),
	(24, '76561198383272185', 'Civilian', 'O_Plane_Fighter_02_F', 'Plane', 1, 0, 0, 0, '', '', '2021-04-05 03:07:48'),
	(25, '76561198383272185', 'Civilian', 'B_Plane_Fighter_01_F', 'Plane', 1, 0, 0, 0, '', '', '2021-04-05 03:09:02'),
	(26, '76561198273172138', 'Civilian', 'C_IDAP_Heli_Transport_02_F', 'Helicopter', 1, 0, 0, 0, '', 'Ion', '2021-04-06 01:10:03'),
	(27, '76561198279405701', 'Civilian', 'C_Van_02_transport_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-04-06 01:34:48'),
	(28, '76561198279405701', 'Civilian', 'C_Hatchback_01_sport_F', 'Car', 1, 0, 0, 0, '', 'DarkBlueSport', '2021-04-06 01:39:31'),
	(29, '76561198383272185', 'Civilian', 'B_Plane_CAS_01_F', 'Plane', 1, 0, 0, 0, '', '', '2021-04-06 01:40:45'),
	(30, '76561198279405701', 'Civilian', 'C_IDAP_Heli_Transport_02_F', 'Helicopter', 1, 0, 0, 0, '', 'Dahoman', '2021-04-06 01:43:27'),
	(31, '76561198383272185', 'Civilian', 'B_Heli_Transport_03_unarmed_F', 'Helicopter', 1, 0, 0, 0, '', 'Olive', '2021-04-06 02:23:45'),
	(32, '76561198383272185', 'Civilian', 'B_Heli_Transport_01_F', 'Helicopter', 1, 0, 0, 0, '', 'Civilian', '2021-04-06 02:30:30'),
	(33, '76561198383272185', 'Civilian', 'O_MRAP_02_F', 'Car', 1, 0, 0, 0, '', 'Hex', '2021-04-06 02:31:14'),
	(34, '76561198383272185', 'Civilian', 'O_MRAP_02_F', 'Car', 1, 0, 0, 0, '', 'GoldLine', '2021-04-06 02:31:33'),
	(35, '76561198383272185', 'Civilian', 'I_C_Offroad_02_LMG_F', 'Car', 1, 0, 0, 0, '', 'White', '2021-04-06 02:32:55'),
	(36, '76561198383272185', 'Civilian', 'B_G_Offroad_01_armed_F', 'Car', 1, 0, 0, 0, '', 'BlueWhite', '2021-04-06 02:33:09'),
	(37, '76561198383272185', 'Civilian', 'O_T_VTOL_02_infantry_F', 'Plane', 1, 0, 0, 0, '', '', '2021-04-06 02:33:30'),
	(38, '76561198383272185', 'Civilian', 'O_T_VTOL_02_vehicle_F', 'Plane', 1, 0, 0, 0, '', '', '2021-04-06 02:33:36'),
	(39, '76561198383272185', 'Civilian', 'I_Heli_light_03_unarmed_F', 'Helicopter', 1, 0, 0, 0, '', 'Black', '2021-04-06 02:34:10'),
	(40, '76561198383272185', 'Civilian', 'O_LSV_02_unarmed_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-04-06 02:34:22'),
	(41, '76561198279405701', 'Civilian', 'C_Van_02_vehicle_F', 'Car', 1, 0, 0, 0, '', 'Press', '2021-04-06 02:57:48'),
	(42, '76561198279405701', 'Civilian', 'C_IDAP_Van_02_vehicle_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-04-06 02:59:49'),
	(43, '76561197971322689', 'Civilian', 'C_Hatchback_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-04-11 22:03:28'),
	(44, '76561198092567307', 'Civilian', 'C_Offroad_01_F', 'Car', 1, 0, 0, 0, '', 'White', '2021-04-14 00:47:49'),
	(45, '76561197971322689', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-04-16 19:26:37'),
	(46, '76561198092567307', 'Civilian', 'C_Heli_Light_01_civil_F', 'Helicopter', 1, 0, 0, 0, '', 'ChromeGold', '2021-04-20 13:16:14'),
	(47, '76561198092567307', 'Civilian', 'C_Offroad_02_unarmed_F', 'Car', 1, 0, 0, 0, '', 'White', '2021-04-21 15:04:20');
/*!40000 ALTER TABLE `vehicles` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.votes: ~2 rows (approximately)
/*!40000 ALTER TABLE `votes` DISABLE KEYS */;
INSERT INTO `votes` (`id`, `pid`, `candidate`, `amount`, `active`) VALUES
	(1, '76561197971322689', 2, 2, 0),
	(2, '76561198279405701', 2, 1, 0);
/*!40000 ALTER TABLE `votes` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.warrants: ~2 rows (approximately)
/*!40000 ALTER TABLE `warrants` DISABLE KEYS */;
INSERT INTO `warrants` (`id`, `pid`, `act`, `crime`, `info`, `insert`, `active`) VALUES
	(1, '76561198092567307', 'OffencesAgainstThePerson', 'Section1', '"[`System`,`Suspected Weapon: TRG 5.56 mm`]"', '2021-04-19 22:35:41', 1),
	(2, '76561198092567307', 'OffencesAgainstThePerson', 'Section1', '"[`System`,`Suspected Weapon: TRG 5.56 mm`]"', '2021-04-19 22:36:33', 1);
/*!40000 ALTER TABLE `warrants` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
