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

-- Dumping structure for procedure altislife.deleteOldHouses
DELIMITER //
CREATE PROCEDURE `deleteOldHouses`()
BEGIN
	DELETE FROM houses WHERE sold='1';
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
  `classname` varchar(64) DEFAULT NULL,
  `pos` varchar(32) DEFAULT NULL,
  `storage` text DEFAULT NULL,
  `virtualStorage` text DEFAULT NULL,
  `shared` tinyint(4) DEFAULT 0,
  `sold` tinyint(4) DEFAULT 0,
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  UNIQUE KEY `pos` (`pos`),
  KEY `fkIdx_players_houses` (`pid`),
  CONSTRAINT `FK_players_houses` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.houses: ~1 rows (approximately)
/*!40000 ALTER TABLE `houses` DISABLE KEYS */;
INSERT INTO `houses` (`id`, `pid`, `classname`, `pos`, `storage`, `virtualStorage`, `shared`, `sold`, `insert_time`) VALUES
	(1, '76561198092567307', 'Land_i_House_Big_02_V1_F', '"[3685.34,13059.8,1.16742]"', '"[]"', '"[]"', 0, 0, '2021-03-29 04:48:56');
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
) ENGINE=InnoDB AUTO_INCREMENT=115 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.logs: ~113 rows (approximately)
/*!40000 ALTER TABLE `logs` DISABLE KEYS */;
INSERT INTO `logs` (`id`, `event`, `pid`, `content`, `insert`) VALUES
	(1, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 02:24:14'),
	(2, 'Bleedout', '76561198092567307', '"[[3361.98,13069.6,0.00133753],[[`arifle_MX_Black_F`,``,``,``,[`30Rnd_65x39_caseless_black_mag`,24],[],``],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 02:28:11'),
	(3, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 02:28:18'),
	(4, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1217294`,`15000`,`Paycheck`]"', '2021-03-28 02:39:13'),
	(5, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:07:55'),
	(6, 'Bleedout', '76561198092567307', '"[[3630.83,13364.5,0.00149775],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 17:08:26'),
	(7, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:08:32'),
	(8, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:11:41'),
	(9, 'Bleedout', '76561198092567307', '"[[3630.16,13364.5,0.00148678],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 17:12:02'),
	(10, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:12:07'),
	(11, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:14:56'),
	(12, 'Bleedout', '76561198092567307', '"[[3632.02,13361.4,0.00148916],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 17:15:17'),
	(13, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:15:24'),
	(14, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:31:29'),
	(15, 'Bleedout', '76561198092567307', '"[[3630.95,13360.6,0.00149202],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 17:31:50'),
	(16, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:31:56'),
	(17, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:47:19'),
	(18, 'Bleedout', '76561198092567307', '"[[3630.29,13364,0.00148582],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 17:47:37'),
	(19, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:47:43'),
	(20, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:54:31'),
	(21, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:58:20'),
	(22, 'Bleedout', '76561198092567307', '"[[3631.37,13362.2,0.00148821],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 17:58:51'),
	(23, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 17:58:57'),
	(24, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 18:01:48'),
	(25, 'Bleedout', '76561198092567307', '"[[3628.47,13360,0.00151682],[[`arifle_SPAR_01_blk_F`,``,``,``,[],[],``],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 18:03:20'),
	(26, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 18:03:25'),
	(27, 'Bleedout', '76561198092567307', '"[[3628.68,13362.8,0.00143147],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 18:03:31'),
	(28, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 18:03:37'),
	(29, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 18:09:10'),
	(30, 'Bleedout', '76561198092567307', '"[[3632.6,13361.2,0.0015111],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 18:09:14'),
	(31, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 18:09:19'),
	(32, 'Bleedout', '76561198092567307', '"[[3631.13,13362.7,0.00150681],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 18:09:37'),
	(33, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 18:09:42'),
	(34, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1232294`,`15000`,`Paycheck`]"', '2021-03-28 18:23:14'),
	(35, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1247294`,`15000`,`Paycheck`]"', '2021-03-28 18:38:15'),
	(36, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1262294`,`15000`,`Paycheck`]"', '2021-03-28 18:53:15'),
	(37, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1277294`,`15000`,`Paycheck`]"', '2021-03-28 19:08:15'),
	(38, 'Money', '76561198092567307', '"[`Cash`,`Removed`,`0`,`680595`,`Unknown`]"', '2021-03-28 19:18:02'),
	(39, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1957889`,`680595`,`Bank Deposit`]"', '2021-03-28 19:18:02'),
	(40, 'Bleedout', '76561198092567307', '"[[3667.99,13380.4,0.00152206],[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]]]"', '2021-03-28 19:20:39'),
	(41, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 19:20:45'),
	(42, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 22:31:32'),
	(43, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 22:34:42'),
	(44, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 22:38:05'),
	(45, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1972889`,`15000`,`Paycheck`]"', '2021-03-28 22:52:33'),
	(46, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 23:07:25'),
	(47, 'Spawn', '76561198092567307', '"[`Kavala`,[3647.62,13076.9,0.0186119]]"', '2021-03-28 23:07:56'),
	(48, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1980389`,`7500`,`Paycheck`]"', '2021-03-28 23:22:56'),
	(49, 'Spawn', '76561198092567307', '"[`Kavala`,[3689,13107.4,0.356469]]"', '2021-03-28 23:31:22'),
	(50, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-28 23:35:52'),
	(51, 'Spawn', '76561198092567307', '"[`Kavala`,[3686.23,13120.2,0.596228]]"', '2021-03-28 23:36:03'),
	(52, 'Spawn', '76561198092567307', '"[`Kavala`,[3615.14,13187.4,0.195115]]"', '2021-03-28 23:43:45'),
	(53, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1987889`,`7500`,`Paycheck`]"', '2021-03-28 23:58:44'),
	(54, 'Spawn', '76561198092567307', '"[`Kavala`,[3619.31,13205.4,0.226178]]"', '2021-03-29 00:06:55'),
	(55, 'Spawn', '76561198092567307', '"[`Kavala`,[3647.62,13076.9,0.0186119]]"', '2021-03-29 00:11:00'),
	(56, 'Spawn', '76561198092567307', '"[`Kavala`,[3629.07,13076.3,-0.0217514]]"', '2021-03-29 00:18:04'),
	(57, 'Money', '76561198092567307', '"[`Bank`,`Added`,`1995389`,`7500`,`Paycheck`]"', '2021-03-29 00:31:04'),
	(58, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-29 00:37:42'),
	(59, 'Spawn', '76561198092567307', '"[`Kavala`,[3689,13107.4,0.356469]]"', '2021-03-29 00:37:58'),
	(60, 'Spawn', '76561198092567307', '"[`Kavala`,[3629.07,13076.3,-0.0217514]]"', '2021-03-29 00:40:53'),
	(61, 'Spawn', '76561198092567307', '"[`Kavala`,[3686.23,13120.2,0.596228]]"', '2021-03-29 00:43:24'),
	(62, 'Spawn', '76561198092567307', '"[`KavalaStation`,[3633.68,13361.1,0]]"', '2021-03-29 00:49:31'),
	(63, 'Spawn', '76561198092567307', '"[`Kavala`,[3619.31,13205.4,0.226178]]"', '2021-03-29 00:49:43'),
	(64, 'Money', '76561198092567307', '"[`Bank`,`Added`,`2002889`,`7500`,`Paycheck`]"', '2021-03-29 01:04:42'),
	(65, 'Spawn', '76561198092567307', '"[`Kavala`,[3613.09,13177.4,0.264072]]"', '2021-03-29 01:12:47'),
	(66, 'Spawn', '76561198092567307', '"[any,[3685.55,13058.4,0.00143623]]"', '2021-03-29 01:16:18'),
	(67, 'Spawn', '76561198092567307', '"[`Kavala`,[3629.07,13076.3,-0.0217514]]"', '2021-03-29 01:18:50'),
	(68, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3685.55,13058.4,0.00143623]]"', '2021-03-29 01:18:59'),
	(69, 'Money', '76561198092567307', '"[`Bank`,`Added`,`2010389`,`7500`,`Paycheck`]"', '2021-03-29 01:33:57'),
	(70, 'Spawn', '76561198092567307', '"[`Kavala`,[3615.14,13187.4,0.195115]]"', '2021-03-29 01:41:45'),
	(71, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 01:43:23'),
	(72, 'Spawn', '76561198092567307', '"[`Kavala`,[3686.96,13101.7,0.444872]]"', '2021-03-29 01:47:15'),
	(73, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 01:47:25'),
	(74, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 01:55:57'),
	(75, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:00:48'),
	(76, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:02:38'),
	(77, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:05:20'),
	(78, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:07:39'),
	(79, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:22:07'),
	(80, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:23:50'),
	(81, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:26:43'),
	(82, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:35:02'),
	(83, 'Money', '76561198092567307', '"[`Bank`,`Added`,`2017889`,`7500`,`Paycheck`]"', '2021-03-29 02:49:57'),
	(84, 'Spawn', '76561198092567307', '"[`Kavala`,[3647.62,13076.9,0.0186119]]"', '2021-03-29 02:53:10'),
	(85, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:53:21'),
	(86, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:55:20'),
	(87, 'Spawn', '76561198092567307', '"[`Kavala`,[3664.76,13249.5,-0.091362]]"', '2021-03-29 02:58:29'),
	(88, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 02:58:38'),
	(89, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:01:55'),
	(90, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:07:41'),
	(91, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:11:12'),
	(92, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:15:11'),
	(93, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:19:09'),
	(94, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:28:00'),
	(95, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:39:19'),
	(96, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:42:30'),
	(97, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:44:54'),
	(98, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:48:15'),
	(99, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:51:16'),
	(100, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 03:54:47'),
	(101, 'Money', '76561198092567307', '"[`Bank`,`Added`,`2025389`,`7500`,`Paycheck`]"', '2021-03-29 04:09:46'),
	(102, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 04:24:52'),
	(103, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 04:31:03'),
	(104, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 04:33:23'),
	(105, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 04:34:55'),
	(106, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 04:39:19'),
	(107, 'House', '76561198092567307', '"[`Sold`,[3685.34,13059.8,1.16742],`600000`]"', '2021-03-29 04:39:22'),
	(108, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 04:45:28'),
	(109, 'House', '76561198092567307', '"[`Sold`,[3685.34,13059.8,1.16742],`600000`]"', '2021-03-29 04:45:43'),
	(110, 'Money', '76561198092567307', '"[`Bank`,`Added`,`2625389`,`600000`,`Unknown`]"', '2021-03-29 04:45:43'),
	(111, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 04:48:36'),
	(112, 'House', '76561198092567307', '"[`Sold`,[3685.34,13059.8,1.16742],`600000`]"', '2021-03-29 04:48:46'),
	(113, 'Money', '76561198092567307', '"[`Bank`,`Added`,`3225389`,`600000`,`Unknown`]"', '2021-03-29 04:48:46'),
	(114, 'Spawn', '76561198092567307', '"[`House (Big, White)`,[3684.44,13058.3,-0.257817]]"', '2021-03-29 04:50:17');
/*!40000 ALTER TABLE `logs` ENABLE KEYS */;

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
  `eventslevel` enum('0','1','2') NOT NULL DEFAULT '0',
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
INSERT INTO `players` (`uid`, `pid`, `name`, `aliases`, `cash`, `bankacc`, `group_id`, `coplevel`, `rtalevel`, `npaslevel`, `scolevel`, `ncalevel`, `mpulevel`, `rpulevel`, `afolevel`, `uclevel`, `cop_licenses`, `cop_gear`, `cop_stats`, `cop_blacklisted`, `mediclevel`, `aalevel`, `med_licenses`, `med_gear`, `med_stats`, `med_blacklisted`, `hatolevel`, `hato_licenses`, `hato_stats`, `hato_gear`, `hato_blacklisted`, `civ_gear`, `civ_licenses`, `civ_stats`, `arrested`, `prison_timer`, `adminlevel`, `eventslevel`, `donorlevel`, `prestige`, `level`, `xp`, `professions`, `daily_tasks`, `weekly_tasks`, `achievements`, `textures`, `playtime`, `insert_time`, `last_seen`) VALUES
	(4, '76561197971322689', 'Lewis Holloway [CO0101]', '"[`Lewis Holloway [CO0101]`]"', 0, 50000, -1, '0', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '5', '0', '"[]"', '"[[[],[],[],[`U_O_R_Gorka_01_black_F`,[]],[`V_TacVestIR_blk`,[]],[],`H_Beret_blk`,`G_Aviator`,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[[[],[],[],[`U_C_Poor_1`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[]"', '"[100,100,0]"', 0, 0, '0', '0', '0', 0, 1, 50, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`]"', '"[]"', '"[0,2,2]"', '2021-03-07 22:07:36', '2021-03-28 02:23:11'),
	(2, '76561198054519084', 'Ben Sewell', '"[`Ben Sewell`]"', 0, 50000, -1, '0', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', '"[]"', '"[100,100,0]"', 0, 0, '0', '0', '0', 0, 1, 0, '"[]"', '"[]"', '"[]"', '"[]"', '"[]"', '"[0,0,7]"', '2021-01-29 14:51:04', '2021-03-23 20:59:30'),
	(1, '76561198092567307', 'Jack Williams', '"[`Scarso`]"', 0, 3225389, 1, '8', '3', '3', '3', '3', '3', '3', '3', '3', '"[]"', '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[`SI`,``]]"', '"[50,30,0]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '1', '"[]"', '"[100,100,0]"', '"[[[],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[],[``,``]]"', 0, '"[[[],[],[],[`U_C_Man_casual_1_F`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[[`FreshApple`,20],[`Water`,2],[`Pickaxe`,1]],[`U_C_Man_casual_1_F`,``]]"', '"[`Driving`,`Boating`,`Trucking`,`Piloting`,`Schnapps`,`Tobacco`]"', '"[90,80,0.00200193]"', 0, 0, '5', '0', '0', 5, 3, 3439, '"[[`Gathering`,[0,19]],[`Mining`,[0,28]],[`Repairing`,[0,1]]]"', '"[[`ProcessSand`,0],[`GatherPeach`,0],[`MineCoal`,0]]"', '"[[`SellCigar`,0],[`SellCigarette`,0]]"', '"[`FirstSpawn`,`FanGirl`,`Prestige`,`BuyVehicle`,`Scarso`,`Lewis`]"', '"[[`C_SUV_01_F`,[`Orange`]]]"', '"[913,1,374]"', '2021-01-18 00:53:15', '2021-03-29 04:48:46'),
	(5, '76561198173004713', 'Steve White', '"[`Steve White`]"', 0, 50000, -1, '0', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[]"', '"[]"', '"[100,100,0]"', 0, 0, '0', '0', '0', 0, 1, 0, '"[]"', '"[]"', '"[]"', '"[]"', '"[]"', '"[0,0,0]"', '2021-03-08 22:01:19', '2021-03-23 20:59:31'),
	(6, '76561198273172138', 'Albert Stuart', '"[`Jetan Holo`]"', 8619, 95000, -1, '3', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[[[`arifle_SPAR_01_blk_F`,``,``,``,[],[],``],[],[],[`U_Rangemaster`,[]],[`V_PlateCarrier1_blk`,[]],[`B_Carryall_cbr`,[]],`H_Beret_blk`,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[[`Coffee`,12]],[`PC`,`INVIS`]]"', '"[100,90,0.495058]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[[[],[],[],[`U_C_Poor_1`,[]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[[`Pickaxe`,1]],[``,``]]"', '"[`Driving`,`Trucking`,`Boating`,`Piloting`]"', '"[100,80,0]"', 0, 0, '0', '0', '0', 0, 1, 100, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`,`BuyVehicle`]"', '"[]"', '"[18,0,97]"', '2021-03-18 19:02:22', '2021-03-28 02:23:11'),
	(3, '76561198342068529', 'Ace Boyden', '"[`Mr. Ace Boyden`]"', 0, 110000, 3, '3', '0', '0', '0', '0', '0', '0', '0', '0', '"[]"', '"[[[`arifle_SPAR_01_blk_F`,``,``,``,[],[],``],[],[],[`U_Rangemaster`,[]],[],[],``,``,[],[`ItemMap`,`ItemGPS`,`ItemRadio`,`ItemCompass`,`ItemWatch`,``]],[[`Redbull`,15]],[`PC`,``]]"', '"[100,100,0]"', 0, '0', '0', '"[]"', '"[]"', '"[100,100,0]"', 0, '0', '"[]"', '"[100,100,0]"', '"[]"', 0, '"[[[`arifle_SPAR_01_GL_blk_F`,``,``,``,[`30Rnd_556x45_Stanag`,0],[],``],[],[],[`U_C_Man_casual_1_F`,[[`1Rnd_HE_Grenade_shell`,1,1]]],[],[],``,``,[],[`ItemMap`,``,``,`ItemCompass`,`ItemWatch`,``]],[],[`U_C_Man_casual_1_F`,``]]"', '"[]"', '"[100,100,0]"', 0, 0, '0', '0', '0', 0, 1, 100, '"[]"', '"[]"', '"[]"', '"[`FirstSpawn`,`BuyVehicle`]"', '"[]"', '"[72,0,25]"', '2021-02-28 15:40:50', '2021-03-28 02:23:11');
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
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.settings: ~4 rows (approximately)
/*!40000 ALTER TABLE `settings` DISABLE KEYS */;
INSERT INTO `settings` (`id`, `setting`, `value`) VALUES
	(1, 'DonationGoal', '0'),
	(2, 'ThreatLevel', '0'),
	(3, 'Day', '2021-3-29'),
	(4, 'Week', '13');
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
  `impound` int(11) NOT NULL DEFAULT 0,
  `plate` varchar(50) NOT NULL DEFAULT '',
  `texture` varchar(50) NOT NULL DEFAULT '',
  `insert_time` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  KEY `fkIdx_players_vehicles` (`pid`),
  KEY `index_type` (`type`),
  KEY `index_side` (`faction`) USING BTREE,
  CONSTRAINT `FK_players_vehicles` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table altislife.vehicles: ~12 rows (approximately)
/*!40000 ALTER TABLE `vehicles` DISABLE KEYS */;
INSERT INTO `vehicles` (`id`, `pid`, `faction`, `classname`, `type`, `alive`, `active`, `sold`, `impound`, `plate`, `texture`, `insert_time`) VALUES
	(2, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-18 23:26:59'),
	(3, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-18 23:27:34'),
	(4, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-18 23:28:11'),
	(6, '76561198092567307', 'Civilian', 'C_SUV_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-18 23:29:22'),
	(7, '76561198273172138', 'Civilian', 'C_Hatchback_01_sport_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-24 21:41:23'),
	(8, '76561198273172138', 'Civilian', 'O_LSV_02_unarmed_F', 'Car', 1, 0, 0, 0, '', 'PoliceBlack', '2021-03-24 21:42:16'),
	(9, '76561198273172138', 'Civilian', 'C_Hatchback_01_sport_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-25 23:41:05'),
	(10, '76561198273172138', 'Civilian', 'C_Hatchback_01_sport_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-25 23:47:17'),
	(11, '76561198273172138', 'Civilian', 'C_Hatchback_01_sport_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-25 23:52:44'),
	(12, '76561198092567307', 'Civilian', 'C_Offroad_01_F', 'Car', 1, 0, 0, 0, '', 'White', '2021-03-26 16:18:53'),
	(13, '76561198092567307', 'Civilian', 'C_Hatchback_01_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-26 16:21:46'),
	(14, '76561198092567307', 'Civilian', 'C_Van_02_vehicle_F', 'Car', 1, 0, 0, 0, '', 'Black', '2021-03-26 16:23:52');
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
